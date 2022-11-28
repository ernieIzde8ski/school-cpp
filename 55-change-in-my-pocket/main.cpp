/*
  Ernest Izdebski, 2022-11-28

  Takes input from stdin of a number of quarters, dimes, nickles, and
  sends these values to a function, outputting the monetary value of
  said coins.
*/

#include <iostream>
#define elif else if
#define QUARTER_VALUE 25
#define DIME_VALUE 10
#define NICKLE_VALUE 5
#define PENNY_VALUE 1


// simple input function
template <typename T> T input(std::string s = "") {
  T resp;
  std::cout << s;
  std::cin >> resp;
  return resp;
}

// function for printing coin value to stdout
void printCoinValue(int quarters = 0, int dimes = 0, int nickles = 0, int pennies = 0) {
  int resp = (quarters * QUARTER_VALUE) + (dimes * DIME_VALUE) + (nickles * NICKLE_VALUE) + (pennies * PENNY_VALUE);
  std::cout << "You have entered " << resp << "¢.\n";
}


int main(int argc, char** argv) {
  // define
  int quarters, dimes, nickles;

  // populate
  if (argc == 1) {
    // if no arguments, populate from stdin
    std::cout << "please input your Total Money:\n";
    quarters = input<int>("\tquarters ? ");
    dimes = input<int>("\tdimes ?    ");
    nickles = input<int>("\tnickles ?  ");
    std::cout << std::endl;
  } elif (argc == 4) {
    // if three arguments, populate from these
    quarters = atoi(argv[1]);
    dimes = atoi(argv[2]);
    nickles = atoi(argv[3]);
  } else {
    // if any other arrangement of arguments, notify the user they have erred
    std::cerr << "usage: " << argv[0] << "[<quarters> <dimes> <nickles>]";
    exit(1);
  }

  // send flow over to function
  printCoinValue(quarters, dimes, nickles);
}
