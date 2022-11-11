/*
  Ernest Izdebski, 2022-11-10

  Reads in 10 integers and returns the sum of the negative, positive,
  and all numbers.
*/
#include <iostream>

// simple input function
template <typename T> T input(std::string s = "") {
  T resp;
  std::cout << s;
  std::cin >> resp;
  return resp;
}

int main() {
  int negativeSum = 0;
  int positiveSum = 0;
  int totalSum = 0;

  std::cout << "give ten numbers:\n";
  for (int i = 0; i < 10; i++) {
    // we don't really need to stick them in an array or something
    // we can just push them into the sums right here
    int cinNumber = input<int>("#" + std::to_string(i) + ":\t");
    totalSum += cinNumber;
    if (cinNumber < 0) negativeSum += cinNumber;
    else positiveSum += cinNumber;
  }

  std::cout << "Negative sum: \t" << negativeSum << std::endl
    << "Positive sum: \t" << positiveSum << std::endl
    << "Total sum: \t" << totalSum << std::endl
    << std::endl;
}
