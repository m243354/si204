/**
 * This code is a wrapper for the curses library. It hides the details of
 * curses to instead provide "easy to use" functions. Using these functions
 * instead of curses directly will lose some flexibility and functionality,
 * but most basic applications don't need it.
 *
 * @author chambers
 * adapted by choi
 * adapted by brown 4/22
 */
#include <iostream>
#include <curses.h>
#include <signal.h>
#include "easycurses.h"

// Global variable holding the pointer to the ncurses terminal.
WINDOW* gcW = 0;

// Signal handler to restore terminal settings in case of segfault or ctrl-c
void handler(int signum) {
  endCurses();
  if (signum == SIGSEGV)
    std::cout << "Segmentation fault" << std::endl;
  exit(1);
} 

// Initializes curses and returns the pointer to the window handle that
// must be passed to the drawing functions.
void startCurses() {
  // make sure endCurses() is called when bad things happen
  signal(SIGSEGV,handler);    
  signal(SIGINT,handler);
  atexit(endCurses);

  // start curses up the way we want it!
  gcW = initscr();  
  cbreak();
  noecho(); 
  nodelay(gcW, true);
  keypad(gcW, true);  // allows arrow keys
  curs_set(0);
}

// Write one character to the terminal at location (row,col).
void drawChar(int ch, int row, int col) {
  if( gcW == 0 ) {
    std::cout << "ERROR: drawChar() called with an uninitialized window. Call startCurses() first.\n";
    exit(42);
  }
  else {
    wmove(gcW, row, col);
    waddch(gcW, ch);
  }
}

// Grab the last key pressed by the user.
int inputChar() {
  return wgetch(gcW);
}

// Redraw everything added to the curses window.
void refreshWindow() {
  if( gcW == 0 ) {
    std::cout << "ERROR: refreshWindow() called with an uninitialized window. Call startCurses() first.\n";
    exit(42);
  }
  wrefresh(gcW);
}

// Close curses and return the terminal to normal operation.
void endCurses() {
  if (gcW != 0)
    endwin();
  gcW = 0;
}

// Sets the rows/cols parameters to the dimensions of the given window.
void getWindowDimensions(int& rows, int& cols) {
  if( gcW == 0 ) {
    std::cout << "ERROR: getWindowDimensions() called with an uninitialized window. Call startCurses() first.\n";
    exit(42);
  }
  getmaxyx(gcW, rows, cols);
}
