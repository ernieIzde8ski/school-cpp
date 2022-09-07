/*
  Ernest Izdebski, 2022-09-07

  A program that asks the user to enter two numbers, and uses the conditional operator to determine which number is smaller and which is the larger, or are they equal.
*/

#include <iostream>
using namespace std;

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
  } else if (n_0 == n_1) {
    cout << n_0 << " is equal to " << n_1 << endl;
  } else if (n_0 > n_1) {
    cout << n_0 << " is greater than " << n_1 << endl;
  }
}
