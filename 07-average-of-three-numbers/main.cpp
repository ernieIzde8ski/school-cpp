/*
  Ernest Izdebski, 2022-09-02

  Take the input of three numbers (as doubles) and display their average.
*/

#include <iostream>
using namespace std;

int main() {
  // define variables
  double i_0;
  double i_1;
  double i_2;

  // populate variables
  cout << "Input 1st value: ";
  cin >> i_0;
  cout << "Input 2nd value: ";
  cin >> i_1; 
  cout << "Input 3rd value: ";
  cin >> i_2;

  // calculate and display the average
  double average = (i_0 + i_1 + i_2) / 3;
  cout << endl << "the mean of these numbers is: " << average << endl;
}
