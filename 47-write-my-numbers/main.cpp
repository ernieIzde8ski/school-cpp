/*
  Ernest Izdebski, 2022-11-10

  Program that writes 50 numbers in the range [0, 2000) to a file.
*/

#include <iostream>
#include <fstream>

// function for left-padded random integers in the range [0, upperBound)
std::string ljustedRandInt(int upperBound=2000, int chars=4, char filler='0') {
  std::string randInt = std::to_string(rand() % upperBound);
  std::string prepend(chars - randInt.length(), filler);
  return prepend + randInt;
}

int main() {
  // initialize rng seed
  srand(time(0));

  // open file for usage
  std::ofstream file("./myNumbers.txt");
  
  // pump numbers into file
  for (int i = 0; i < 50; i++) {
    file << ljustedRandInt() << "\n";
  }

  // exit
  file.close();
  std::cout << "Done writing!" << std::endl;
}
