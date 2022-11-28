/*
  Ernest Izdebski, 2022-11-28

  Tells which of certain substances will freeze or boil at a given
  temperature (in Fahrenheit).
*/

#include <iostream>
#define elif else if

// simple input function
template <typename T> T input(std::string s = "") {
  T resp;
  std::cout << s;
  std::cin >> resp;
  return resp;
}



// substance arrays - position N in given array is relative to position N in any other array herein
#define TOTAL_SUBSTANCES 4
const std::string SUBSTANCE_NAMES[TOTAL_SUBSTANCES] = { "ethyl alcohol", "mercury", "oxygen", "water" };
const int SUBSTANCE_FREEZING[TOTAL_SUBSTANCES] = { -173, -38, -362, 32 };
const int SUBSTANCE_BOILING[TOTAL_SUBSTANCES] = { 172, 676, -306, 212 };

// print reactions for a given temperature
void printReactions(int temp_f) {
  for (int i = 0; i < TOTAL_SUBSTANCES; i++) {
    // mild assumption assuming freezing temp < boiling
    if (temp_f <= SUBSTANCE_FREEZING[i])
      std::cout << SUBSTANCE_NAMES[i] << " freezes\n";
    elif(temp_f >= SUBSTANCE_BOILING[i])
      std::cout << SUBSTANCE_NAMES[i] << " boils\n";
  }
}

int main(int argc, char** argv) {
  int temp;

  // populate args from either stdin or console arguments
  if (argc == 1) temp = input<int>("Input temperature (fahrenheit)");
  elif (argc == 2) temp = atoi(argv[1]);
  else {
    std::cerr << "usage: " << argv[0] << " [temp]\n";
    return 1;
  }

  printReactions(temp);
}
