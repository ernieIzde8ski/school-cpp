/*
  Ernest Izdebski, 31-08-2022

  Accept input of two numbers and output various operations on them.
*/

#include <iostream>
using namespace std;

int main() {
  // define two values

  int n_0;
  int n_1;

  // pipe input stream into variable
  cout << "enter first value:   ";
  cin >> n_0;
  cout << "enter second value:  ";
  cin >> n_1;

  // perform operations
  cout << n_0 << " * "  << n_1 << ": " << n_0 * n_1 << endl;
  cout << n_0 << " / "  << n_1 << ": " << n_0 / n_1 << endl; // integer division, so no floats
  cout << n_0 << " + "  << n_1 << ": " << n_0 + n_1 << endl;
  cout << n_0 << " - "  << n_1 << ": " << n_0 - n_1 << endl; 
}
