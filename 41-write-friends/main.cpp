/*
  Ernest Izdebski, 2022-10-28

  Create a text file on the computer, storing 5 first names of friends.
*/

#include <iostream>
#include <fstream>

const int MAX_FRIENDS = 5;

int main() {
  // create file handler
  std::ofstream file;
  file.open("./friends.txt");

  // write into file handler
  for (int i = 1; i <= MAX_FRIENDS; i++) {
    std::string name;
    std::cout << "Input friend #" << i << ":\t";
    std::cin >> name;
    file << name << std::endl;
  };

  // close file
  file.close();
  std::cout << "\nFinished writing to file!" << std::endl;
}
