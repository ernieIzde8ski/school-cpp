/*
  Ernest Izdebski, 2022-10-24

  Colors header file tests.
*/

#include "ansi.hpp"
#include <iostream>

int main() {
  ANSI::SGR_RGB(0, 0, 0);
  char text[13] = "Hello World!";
  std::string codes[13] = {
    ANSI::BG_BLACK,
    ANSI::DIM,
    ANSI::UNDERLINE,
    ANSI::STRIKETHROUGH,
    ANSI::FG_YELLOW,
    ANSI::BG_RED,
    ANSI::FG_CYAN,
    ANSI::ITALIC,
    ANSI::SGR_RGB(0, 128, 64),
    ANSI::BG_MAGENTA,
    ANSI::FG_GREEN,
    ANSI::FG_RED,
    ANSI::BG_WHITE,
  };
  ANSI::ERASE_IN_DISPLAY(2);
  ANSI::CURSOR_POSITION(4);
  for (int i = 0; i < 13; i++) {
    std::cout << codes[i] << text[i] << ANSI::NORMAL;
  }
  std::cout << std::endl;
  ANSI::CURSOR_POSITION();
  std::cout << ANSI::BOLD << "The demonstration has concluded." << ANSI::NORMAL << std::endl;
  std::cout << "(Went backwards Lol)" << std::endl;
  ANSI::CURSOR_POSITION(6);
}
