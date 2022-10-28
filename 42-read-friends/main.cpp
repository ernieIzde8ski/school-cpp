/*
  Ernest Izdebski, 2022-10-28

  Read file "friends.txt" and display lines to console.
*/

#include <iostream>
#include <fstream>


int main() {
  // open file with its constructor
  std::ifstream file ("friends.txt");

  // read from file
  int i = 1;
  for (std::string line; file >> line; i++ ) {
    std::cout << "Friend #" << i << ":\t" << line << std::endl;
  }

  // close file
  file.close();
  std::cout << "You have no more friends." << std::endl;
}
