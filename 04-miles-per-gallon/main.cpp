/*
  Ernest Izdebski, 31-08-2022

  Accept input about truck mileage and output the miles-per-gallon.
*/

#include <iostream>
using namespace std;

int main() {
  // define variables

  int initial_miles;
  int final_miles;
  int gallons_used;

  // populate data from input stream
  cout << "Enter initial miles: ";
  cin >> initial_miles;
  cout << "Enter final miles: ";
  cin >> final_miles;
  cout << "Enter total gallons used: ";
  cin >> gallons_used;

  // calculate MPG
  int miles_per_gallon = (final_miles - initial_miles) / gallons_used;

  // display requested information
  cout << "Beginning Miles:  " << initial_miles << endl;
  cout << "Ending Miles:     " << final_miles << endl;
  cout << "Gallons Used:     " << gallons_used << endl;
  cout << "Miles per Gallon: " << miles_per_gallon << endl;
}
