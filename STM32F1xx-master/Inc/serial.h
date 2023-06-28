/*

  serial.h - low level functions for transmitting bytes via the serial port

  Part of grblHAL

  Copyright (c) 2017-2023 Terje Io

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

#include <stdint.h>
#include <stdbool.h>

#include "driver.h"
#include "grbl/stream.h"

#define RX_BUFFER_HWM 900
#define RX_BUFFER_LWM 300

#if defined(SERIAL_MOD) || defined(SERIAL2_MOD)
void serialRegisterStreams (void);
#endif

#ifdef SERIAL_MOD
const io_stream_t *serialInit (uint32_t baud_rate);
#endif

#ifdef SERIAL2_MOD
const io_stream_t *serial2Init (uint32_t baud_rate);
#endif

/*EOF*/
