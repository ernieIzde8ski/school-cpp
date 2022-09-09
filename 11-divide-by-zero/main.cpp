/*
  Ernest Izdebski, 2022-09-09

  A program that will accept two numbers from the keyboard and process the collected data by dividing the first by the second.
*/

#include <iostream>
using namespace std;


int main() {
  // define variables
  double divisor;
  double dividend;

  cout << "Input first number:  ";
  cin >> divisor;
  cout << "Input second number: ";
  cin >> dividend;

  // perform output logic
  if (dividend == 0) {
    cout << "Input error: dividend cannot be 0" << endl;
    // shortcircuit the entire function, thereby not needing to use an else statement
    // since it's an error, return a non-zero exit code
    return 1;
  }

  cout << divisor << " / " << dividend << " == " << (divisor / dividend) << endl;
}
