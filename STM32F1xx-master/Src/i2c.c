/*
  i2c.c - I2C support for EEPROM, keypad and Trinamic plugins

  Part of grblHAL driver for STM32F103xx

  Copyright (c) 2018-2023 Terje Io

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <main.h>

#include "i2c.h"

#ifdef I2C_PORT

#include "grbl.h"

#if KEYPAD_ENABLE == 1
#include "keypad/keypad.h"
#endif

#if TRINAMIC_ENABLE && TRINAMIC_I2C
#define I2C_ADR_I2CBRIDGE 0x47
#endif

#define I2Cport(p) I2CportI(p)
#define I2CportI(p) I2C ## p

#define I2CPORT I2Cport(I2C_PORT)

static uint8_t keycode = 0;
static keycode_callback_ptr keypad_callback = NULL;
static I2C_HandleTypeDef i2c_port = {
    .Instance = I2CPORT,
    .Init.ClockSpeed = 100000,
    .Init.DutyCycle = I2C_DUTYCYCLE_2,
    .Init.OwnAddress1 = 0,
    .Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT,
    .Init.DualAddressMode = I2C_DUALADDRESS_DISABLE,
    .Init.OwnAddress2 = 0,
    .Init.GeneralCallMode = I2C_GENERALCALL_DISABLE,
    .Init.NoStretchMode = I2C_NOSTRETCH_DISABLE
};

#if I2C_PORT == 1
void I2C1_EV_IRQHandler(void)
{
  HAL_I2C_EV_IRQHandler(&i2c_port);
}

void I2C1_ER_IRQHandler(void)
{
  HAL_I2C_ER_IRQHandler(&i2c_port);
}
#else
void I2C2_EV_IRQHandler(void)
{
  HAL_I2C_EV_IRQHandler(&i2c_port);
}

void I2C2_ER_IRQHandler(void)
{
  HAL_I2C_ER_IRQHandler(&i2c_port);
}
#endif

bool i2c_probe (uint_fast16_t i2cAddr)
{
    //wait for bus to be ready
    while (HAL_I2C_GetState(&i2c_port) != HAL_I2C_STATE_READY) {
        if(!hal.stream_blocking_callback())
            return false;
    }

    return HAL_I2C_IsDeviceReady(&i2c_port, i2cAddr << 1, 4, 10) == HAL_OK;
}

void i2c_get_keycode (uint_fast16_t i2cAddr, keycode_callback_ptr callback)
{
    keycode = 0;
    keypad_callback = callback;

    HAL_StatusTypeDef ret = HAL_I2C_Master_Receive_IT(&i2c_port, i2cAddr << 1, &keycode, 1);

    if(!ret)
        ret = HAL_I2C_Master_Receive_IT(&i2c_port, i2cAddr << 1, &keycode, 1);
}

#if EEPROM_ENABLE

nvs_transfer_result_t i2c_nvs_transfer (nvs_transfer_t *i2c, bool read)
{
    while (HAL_I2C_GetState(&i2c_port) != HAL_I2C_STATE_READY);

//    while (HAL_I2C_IsDeviceReady(&i2c_port, (uint16_t)(0xA0), 3, 100) != HAL_OK);

    if(read)
        HAL_I2C_Mem_Read(&i2c_port, i2c->address << 1, i2c->word_addr, i2c->word_addr_bytes == 1 ? I2C_MEMADD_SIZE_8BIT : I2C_MEMADD_SIZE_16BIT, i2c->data, i2c->count, 100);
    else {
        HAL_I2C_Mem_Write(&i2c_port, i2c->address << 1, i2c->word_addr, i2c->word_addr_bytes == 1 ? I2C_MEMADD_SIZE_8BIT : I2C_MEMADD_SIZE_16BIT, i2c->data, i2c->count, 100);
#if !EEPROM_IS_FRAM
        hal.delay_ms(7, NULL);
#endif
    }
    i2c->data += i2c->count;

    return NVS_TransferResult_OK;
}

#endif

void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
    if(keypad_callback && keycode != 0) {
        keypad_callback(keycode);
        keypad_callback = NULL;
    }
}

#if TRINAMIC_ENABLE && TRINAMIC_I2C

static uint16_t axis = 0xFF;
static const uint16_t tmc_addr = I2C_ADR_I2CBRIDGE << 1;

TMC_spi_status_t tmc_spi_read (trinamic_motor_t driver, TMC_spi_datagram_t *reg)
{
    uint8_t buffer[5] = {0};
    TMC_spi_status_t status = 0;

    if(driver.axis != axis) {
        buffer[0] = driver.axis | 0x80;
        HAL_I2C_Mem_Write(&i2c_port, tmc_addr, axis, I2C_MEMADD_SIZE_8BIT, buffer, 1, 100);

        axis = driver.axis;
    }

    HAL_I2C_Mem_Read(&i2c_port, tmc_addr, (uint16_t)reg->addr.idx, I2C_MEMADD_SIZE_8BIT, buffer, 5, 100);

    status = buffer[0];
    reg->payload.value = buffer[4];
    reg->payload.value |= buffer[3] << 8;
    reg->payload.value |= buffer[2] << 16;
    reg->payload.value |= buffer[1] << 24;

    return status;
}

TMC_spi_status_t tmc_spi_write (trinamic_motor_t driver, TMC_spi_datagram_t *reg)
{
    uint8_t buffer[5] = {0};;
    TMC_spi_status_t status = 0;

    if(driver.axis != axis) {
        buffer[0] = driver.axis | 0x80;
        HAL_I2C_Mem_Write(&i2c_port, tmc_addr, axis, I2C_MEMADD_SIZE_8BIT, buffer, 1, 100);

        axis = driver.axis;
    }

    buffer[0] = (reg->payload.value >> 24) & 0xFF;
    buffer[1] = (reg->payload.value >> 16) & 0xFF;
    buffer[2] = (reg->payload.value >> 8) & 0xFF;
    buffer[3] = reg->payload.value & 0xFF;

    reg->addr.write = 1;
    HAL_I2C_Mem_Write(&i2c_port, tmc_addr, (uint16_t)reg->addr.value, I2C_MEMADD_SIZE_8BIT, buffer, 4, 100);
    reg->addr.write = 0;

    return status;
}

#endif

void i2c_init (void)
{
#if I2C_PORT == 1
    GPIO_InitTypeDef GPIO_InitStruct = {
        .Pin = GPIO_PIN_6|GPIO_PIN_7, // SCL|SDA
        .Mode = GPIO_MODE_AF_OD,
        .Pull = GPIO_PULLUP,
        .Speed = GPIO_SPEED_FREQ_HIGH
    };
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    __HAL_RCC_I2C1_CLK_ENABLE();
    __HAL_AFIO_REMAP_I2C1_DISABLE();

    HAL_I2C_Init(&i2c_port);

    HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
    HAL_NVIC_EnableIRQ(I2C1_ER_IRQn);
#endif

#if I2C_PORT == 2
    GPIO_InitTypeDef GPIO_InitStruct = {
        .Pin = GPIO_PIN_10|GPIO_PIN_11,
        .Mode = GPIO_MODE_AF_OD,
        .Pull = GPIO_PULLUP,
        .Speed = GPIO_SPEED_FREQ_HIGH,
    };
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    __HAL_RCC_I2C2_CLK_ENABLE();

    HAL_I2C_Init(&i2c_port);

    HAL_NVIC_EnableIRQ(I2C2_EV_IRQn);
    HAL_NVIC_EnableIRQ(I2C2_ER_IRQn);
#endif
}

#endif
