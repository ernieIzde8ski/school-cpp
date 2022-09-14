/*
  Ernest Izdebski, 2022-09-14

  Accepts two numbers from the keyboard and determines whether one is larger, or whether they are identical.
*/

#include <iostream>
using namespace std;

// This homework was assigned already, as "MinimumMaximumNumber.cpp"
// I've updated the logic slightly, but otherwise left the main function identical

int main() {
  // define number variables
  // I use doubles because the author *might* choose a decimal number
  double n_0;
  double n_1;

  // populate variables
  cout << "Input 1st number: ";
  cin >> n_0;
  cout << "Input 2nd number: ";
  cin >> n_1;

  // perform conditional logic
  if (n_0 < n_1) {
    cout << n_0 << " is less than " << n_1 << endl;
  } else if (n_0 > n_1) {
    cout << n_0 << " is greater than " << n_1 << endl;
  } else { // other possible conditions already checked, n_0 == n_1
    cout << n_0 << " is equal to " << n_1 << endl;
  }
}
