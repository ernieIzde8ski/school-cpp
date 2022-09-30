/*
  Ernest Izdebski, 2022-09-30

  A program that accepts two numbers from the keyboard and sends those
  numbers to a function, adding them together and displaying the results.
*/

#include <iostream>
using namespace std;

// return given type T from console input
template <typename T> T input(string prompt) {
  T resp;
  cout << prompt;
  cin >> resp;
  return resp;
}

void display_addition(double n_0, double n_1) {
  cout << n_0 << " + " << n_1 << " == " << n_0 + n_1 << endl;
}

int main() {
  // define, populate variables
  double n_0 = input<double>("Input 1st number: ");
  double n_1 = input<double>("Input 2nd number: ");

  // send variables to function
  display_addition(n_0, n_1);
}
