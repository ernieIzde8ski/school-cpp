/*
  Ernest Izdebski, 2022-10-24

  Colors header file tests.
*/

#include "ansi.hpp"
#include <iostream>

int main() {
  ANSI::colorRGB(0, 0, 0);
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
    ANSI::colorRGB(0, 128, 64),
    ANSI::BG_MAGENTA,
    ANSI::FG_GREEN,
    ANSI::FG_RED,
    ANSI::BG_WHITE,
  };
  for (int i = 0; i < 13; i++) {
    std::cout << codes[i] << text[i] << ANSI::NORMAL;
  }
  std::cout << std::endl;

  std::cout << ANSI::BOLD << "The demonstration has concluded.\n" << ANSI::NORMAL << std::endl;
}
