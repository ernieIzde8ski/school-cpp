/*
  Ernest Izdebski, 2022-08-29

  Output my name ("Ernie") five times.
*/

#include <iostream>
using namespace std;

int main() {
  // int _ = 0: declares the initial value of the _ variable
  // _ < 5: iterates until the expression evaluates to false
  // _++: increments the i by 1 each time the loop completes

  // this means that the code inside of the brackets runs once
  // for each value of _=0, _=1, ..., _=4
  // or, five times

  for (int _ = 0; _ < 5; _++) {
    // output the string to the console once
    cout << "Ernie\n";
  }
}
