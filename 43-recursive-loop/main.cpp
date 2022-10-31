/*
  Ernest Izdebski, 2022-10-28

  Use a recursive loop to display my name ten times.
*/

#include <iostream>


const std::string NAME = "Ernie";

void displayName(int i = 0, int times = 10) {
  if (i < times) {
    std::cout << NAME << "\n";
    displayName(i+1, times);
  } else {
    std::cout << "reached end of loop" << std::endl;
  }
}

int main() { displayName(); }
