/*
  Ernest Izdebski, 2022-09-14

  A program that accepts two numbers from the keyboard and divides the first by
  the second, ensuring the second is not zero with a while loop.
*/

#include <iostream>
using namespace std;

int main() {
  // define variables
  double divisor;
  double dividend;
  
  // populate variables
  cout << "Input divisor:  ";
  cin >> divisor;
  cout << "Input dividend: ";
  cin >> dividend;
  
  while (dividend == 0) {
    cout << "error: cannot divide by zero" << endl;
    cout << "Input dividend: ";
    cin >> dividend;
  }

  cout << divisor << " / " << dividend << " = " << (divisor / dividend) << endl;
}
