/*
  Ernest Izdebski, 2022-09-14

  A program that receives the Celsius temperature from the keyboard and
  converts the Celsius temperatures to Fahrenheit temperatures.
*/

#include <iostream>
using namespace std;

int main() {
  // define & populate variable
  cout << "Input degrees in Celsius: ";
  double degrees_c;
  cin >> degrees_c;

  // display output
  cout << degrees_c << "°C is " << (9*degrees_c / 5) + 32 << "°F." << endl; 
}
