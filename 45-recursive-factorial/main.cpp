/*
  Ernest Izdebski, 2022-11-09

  Using Recursive Loops, give the factorial value for a number entered
  from the system.
*/

#include <iostream>
#include "ernie.hpp"

// recursive factorial function
int recursiveFactorial(int n) {
  if (n == 1) return 1;
  if (n < 1) throw (-1);
  return n * recursiveFactorial(n - 1);
}

int main() {
  while (true) {
    int input = ernie::input<int>("give a number:\t");
    if (input < 1) break;
    std::cout << input << "! == " << recursiveFactorial(input) << std::endl;
  }
  std::cout << "goodbye!" << std::endl;
}
