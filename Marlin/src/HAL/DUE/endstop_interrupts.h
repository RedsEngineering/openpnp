/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Endstop Interrupts
 *
 * Without endstop interrupts the endstop pins must be polled continually in
 * the temperature-ISR via endstops.update(), most of the time finding no change.
 * With this feature endstops.update() is called only when we know that at
 * least one endstop has changed state, saving valuable CPU cycles.
 *
 * This feature only works when all used endstop pins can generate an 'external interrupt'.
 *
 * Test whether pins issue interrupts on your board by flashing 'pin_interrupt_test.ino'.
 * (Located in Marlin/buildroot/share/pin_interrupt_test/pin_interrupt_test.ino)
 */

#include "../../module/endstops.h"

// One ISR for all EXT-Interrupts
void endstop_ISR() { endstops.update(); }

/**
 *  Endstop interrupts for Due based targets.
 *  On Due, all pins support external interrupt capability.
 */

void setup_endstop_interrupts() {
  #define _ATTACH(P) attachInterrupt(digitalPinToInterrupt(P), endstop_ISR, CHANGE)
  TERN_(HAS_X_MAX, _ATTACH(X_MAX_PIN));
  TERN_(HAS_X_MIN, _ATTACH(X_MIN_PIN));
  TERN_(HAS_Y_MAX, _ATTACH(Y_MAX_PIN));
  TERN_(HAS_Y_MIN, _ATTACH(Y_MIN_PIN));
  TERN_(HAS_Z_MAX, _ATTACH(Z_MAX_PIN));
  TERN_(HAS_Z_MIN, _ATTACH(Z_MIN_PIN));
  TERN_(HAS_X2_MAX, _ATTACH(X2_MAX_PIN));
  TERN_(HAS_X2_MIN, _ATTACH(X2_MIN_PIN));
  TERN_(HAS_Y2_MAX, _ATTACH(Y2_MAX_PIN));
  TERN_(HAS_Y2_MIN, _ATTACH(Y2_MIN_PIN));
  TERN_(HAS_Z2_MAX, _ATTACH(Z2_MAX_PIN));
  TERN_(HAS_Z2_MIN, _ATTACH(Z2_MIN_PIN));
  TERN_(HAS_Z3_MAX, _ATTACH(Z3_MAX_PIN));
  TERN_(HAS_Z3_MIN, _ATTACH(Z3_MIN_PIN));
  TERN_(HAS_Z4_MAX, _ATTACH(Z4_MAX_PIN));
  TERN_(HAS_Z4_MIN, _ATTACH(Z4_MIN_PIN));
  TERN_(HAS_Z_MIN_PROBE_PIN, _ATTACH(Z_MIN_PROBE_PIN));
  TERN_(HAS_I_MAX, _ATTACH(I_MAX_PIN));
  TERN_(HAS_I_MIN, _ATTACH(I_MIN_PIN));
  TERN_(HAS_J_MAX, _ATTACH(J_MAX_PIN));
  TERN_(HAS_J_MIN, _ATTACH(J_MIN_PIN));
  TERN_(HAS_K_MAX, _ATTACH(K_MAX_PIN));
  TERN_(HAS_K_MIN, _ATTACH(K_MIN_PIN));  
  TERN_(HAS_M_MAX, _ATTACH(M_MAX_PIN));  /**SG**/
  TERN_(HAS_M_MIN, _ATTACH(M_MIN_PIN));  /**SG**/
  TERN_(HAS_O_MAX, _ATTACH(O_MAX_PIN));  /**SG**/
  TERN_(HAS_O_MIN, _ATTACH(O_MIN_PIN));  /**SG**/
  TERN_(HAS_P_MAX, _ATTACH(P_MAX_PIN));  /**SG**/
  TERN_(HAS_P_MIN, _ATTACH(P_MIN_PIN));  /**SG**/
  TERN_(HAS_Q_MAX, _ATTACH(Q_MAX_PIN));  /**SG**/
  TERN_(HAS_Q_MIN, _ATTACH(Q_MIN_PIN));  /**SG**/
}
