/*
  Ernest Izdebski, 2022-10-21

  Test ernie::rand_int functions
*/

#include <iostream>
#include "ernie.hpp"

const int TESTS = 25;
int main() {
  srand(time(0));

  std::cout << "Testing first overload of ernie::rand_int" << std::endl;
  std::cout << "ernie::rand_int(" << TESTS << "):\t";
  for (int i = 0; i < TESTS; i++) {
    std::cout << ernie::rand_int(TESTS) << "\t";
  }
  std::cout << std::endl << std::endl;

  std::cout << "Testing second overload of ernie::rand_int" << std::endl;
  std::cout << "ernie::rand_int(i, " << TESTS << "):\t";
  for (int i = 0; i < TESTS; i++) {
    std::cout << ernie::rand_int(i, TESTS) << "\t";
  }

  std::cout << std::endl << std::endl;
}
