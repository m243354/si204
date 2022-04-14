/**
 * easycurses.h
 *
 * This code is a wrapper for the curses library. It hides the details of
 * curses to instead provide "easy to use" functions. Using these functions
 * instead of curses directly will lose some flexibility and functionality,
 * but most basic applications don't need it.
 *
 * @author chambers
 * adapted by choi
 * adapted by brown 4/22
 */

#ifndef __EASYCURSES_H__
#define __EASYCURSES_H__
#include <curses.h>

// Initializes curses and returns the pointer to the window handle that
// must be passed to the drawing functions.
void startCurses();

// Write one character to the terminal at location (row,col).
// NOTE: ch has type int rather than char here only so in future extra
//       credit situations you can make use of an extended character set.
//       You should treat it as if it was just char.
void drawChar(int ch, int row, int col);

// Grab the last key pressed by the user.
int inputChar();

// Redraw everything added to the curses window.
void refreshWindow();

// Close curses and return the terminal to normal operation.
void endCurses();
   
// Sets the rows/cols parameters to the dimensions of the given window.
void getWindowDimensions(int& rows, int& cols);

#endif // __EASYCURSES_H__
