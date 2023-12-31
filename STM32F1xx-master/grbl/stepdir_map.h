/*
  stepdir_map.h - An embedded CNC Controller with rs274/ngc (g-code) support

  Lookup tables for converting core step and dir signals to physical signals, includes signal inversion.

  May be used by driver code if step and/or dir pins are located to the same port.

  NOT referenced in the core grbl code

  Part of grblHAL

  Copyright (c) 2021-2022 Terje Io

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

#if STEP_OUTMODE == GPIO_MAP

static const uint32_t c_step_outmap[] = {
    0,
    X_STEP_BIT,
    Y_STEP_BIT,
    Y_STEP_BIT | X_STEP_BIT,
    Z_STEP_BIT,
    Z_STEP_BIT | X_STEP_BIT,
    Z_STEP_BIT | Y_STEP_BIT,
    Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
  #if N_AXIS > 3
    A_STEP_BIT,
    A_STEP_BIT | X_STEP_BIT,
    A_STEP_BIT | Y_STEP_BIT,
    A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    A_STEP_BIT | Z_STEP_BIT,
    A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
  #endif
  #if N_AXIS > 4
    B_STEP_BIT,
    B_STEP_BIT | X_STEP_BIT,
    B_STEP_BIT | Y_STEP_BIT,
    B_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    B_STEP_BIT | Z_STEP_BIT,
    B_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    B_STEP_BIT | A_STEP_BIT,
    B_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
  #endif
  #if N_AXIS > 5
    C_STEP_BIT,
    C_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | Y_STEP_BIT,
    C_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | Z_STEP_BIT,
    C_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    C_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | A_STEP_BIT,
    C_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    C_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | Y_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | A_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
  #endif
  #if N_AXIS > 6
    U_STEP_BIT,
    U_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | Z_STEP_BIT,
    U_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | A_STEP_BIT,
    U_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    U_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | Z_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | A_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | Z_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | A_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
  #endif
  #if N_AXIS > 7
    V_STEP_BIT,
    V_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | A_STEP_BIT,
    V_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | A_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | A_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | A_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | A_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | A_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | X_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT,
    V_STEP_BIT | U_STEP_BIT | C_STEP_BIT | B_STEP_BIT | A_STEP_BIT | Z_STEP_BIT | Y_STEP_BIT | X_STEP_BIT,
  #endif
};

static uint32_t step_outmap[sizeof(c_step_outmap) / sizeof(uint32_t)];

#endif

#if DIRECTION_OUTMODE == GPIO_MAP

static const uint32_t c_dir_outmap[] = {
    0,
    X_DIRECTION_BIT,
    Y_DIRECTION_BIT,
    Y_DIRECTION_BIT | X_DIRECTION_BIT,
    Z_DIRECTION_BIT,
    Z_DIRECTION_BIT | X_DIRECTION_BIT,
    Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
  #if N_AXIS > 3
    A_DIRECTION_BIT,
    A_DIRECTION_BIT | X_DIRECTION_BIT,
    A_DIRECTION_BIT | Y_DIRECTION_BIT,
    A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    A_DIRECTION_BIT | Z_DIRECTION_BIT,
    A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
  #endif
  #if N_AXIS > 4
    B_DIRECTION_BIT,
    B_DIRECTION_BIT | X_DIRECTION_BIT,
    B_DIRECTION_BIT | Y_DIRECTION_BIT,
    B_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    B_DIRECTION_BIT | Z_DIRECTION_BIT,
    B_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    B_DIRECTION_BIT | A_DIRECTION_BIT,
    B_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
  #endif
  #if N_AXIS > 5
    C_DIRECTION_BIT,
    C_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | Y_DIRECTION_BIT,
    C_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | Z_DIRECTION_BIT,
    C_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    C_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | A_DIRECTION_BIT,
    C_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    C_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | Y_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
  #endif
  #if N_AXIS > 6
    U_DIRECTION_BIT,
    U_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | Z_DIRECTION_BIT,
    U_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | A_DIRECTION_BIT,
    U_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    U_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | Z_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
  #endif
  #if N_AXIS > 7
    V_DIRECTION_BIT,
    V_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | A_DIRECTION_BIT,
    V_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | A_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | X_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT,
    V_DIRECTION_BIT | U_DIRECTION_BIT | C_DIRECTION_BIT | B_DIRECTION_BIT | A_DIRECTION_BIT | Z_DIRECTION_BIT | Y_DIRECTION_BIT | X_DIRECTION_BIT,
  #endif
};


static uint32_t dir_outmap[sizeof(c_dir_outmap) / sizeof(uint32_t)];

#endif

#if (STEP_OUTMODE == GPIO_MAP) || (DIRECTION_OUTMODE == GPIO_MAP)

#define USE_STEPDIR_MAP 1

static void stepdirmap_init (settings_t *settings)
{
    uint_fast8_t i;

#if STEP_OUTMODE == GPIO_MAP

    i = sizeof(step_outmap) / sizeof(uint32_t);
    do {
        i--;
        step_outmap[i] = c_step_outmap[i ^ settings->steppers.step_invert.value];
    } while(i);
#endif

#if DIRECTION_OUTMODE == GPIO_MAP
    i = sizeof(dir_outmap) / sizeof(uint32_t);
    do {
        i--;
        dir_outmap[i] = c_dir_outmap[i ^ settings->steppers.dir_invert.value];
    } while(i);
#endif
}

#endif

