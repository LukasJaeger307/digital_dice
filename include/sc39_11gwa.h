/**\file */

/* 
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details. 
 */

/**
 * \page sc39-11gwa Using an SC39-11GWA digital LED display
 * Kingbright's SC39-11GWA digital displays are a little retro and
 * not as fancy as LCDs but certainly useful for smaller projects and
 * easy to learn and understand. However memorizing the bit patterns for
 * each digit is rather unnerving. To help you with that, I included a
 * three handy functions that greatly simplify the use of such a display.
 * You need to start by wiring the display to your G-series LaunchPad. Get
 * a copy of the data sheet of the display 
 * [here] (http://www.kingbrightusa.com/images/catalog/SPEC/SC39-11GWA.pdf).
 * Now use the following table to wire the pins of the LaunchPad to the
 * pins of the display.
 *
 * |LaunchPad|Display|
 * |---------|-------|
 * |P 2.0    |1      |
 * |P 2.1    |2      |
 * |GND      |3      |
 * |P 2.2    |4      |
 * |P 2.3    |5      |
 * |P 2.4    |10     |
 * |P 2.5    |9      |
 * |P 1.6    |7      |
 * |P 1.7    |6      |
 *
 * If you don't intend to use the decimal point (pin 6 at the display) you
 * can omit that connection. **DON'T FORGET PROTECTIVE RESISTORS!** I used 10
 * kiloohms which seems to work so far. Now that you are wired up, we can start
 * coding. Make sure you configured all necessary pins as outputs before you
 * start printing digits:
 *
 * ```c
 * P2OUT |= BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5;
 * P1OUT |= BIT6 | BIT7;
 * ```
 *
 * Now you can write the numbers on the display using \ref write_num. It
 * returns an error code if the number was larger than nine, so you can
 * check whether or not you did it right.
 *
 * ```c
 * write_num(5);	// Writes 5 to the display
 * ```
 *
 * If you want to set or clear the decimal point for some reason, you can
 * use the following functions:
 * 
 * ```c
 * set_DP();	// Makes the decimal point light up
 * clear_DP();	// Makes the decimal point go dark again
 * ```
 *
 */

#ifndef _SC39_11GWA_H_
#define _SC39_11GWA_H_

#include "lazy.h"

/**
 * Writes a number between 0 and 9 on a sc39-11gwa digital LED display.
 * @param num The number to write
 * @return _OK_ If the number was not larger than 9 and _ERR_ otherwise
 */
RC write_num(uint8_t num);

/**
 * Makes the decimal point light up.
 * @return _OK_ if everything goes right and _ERR_ otherwise
 */
RC set_DP();

/**
 * Makes the decimal point go dark.
 * @return _OK_ if everything goes right and _ERR_ otherwise
 */
RC clear_DP();

#endif
