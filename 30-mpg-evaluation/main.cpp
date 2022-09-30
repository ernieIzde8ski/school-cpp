/*
  Ernest Izdebski, 2022-09-30

  Rewritten miles-per-gallon program with a function to evaluate how
  well the car is on economy. Output is sampled from assignment reqs.
*/

#include <iostream>
using namespace std;

// quick error exit
void error(string msg, int exit_code = 1) {
  cerr << msg << endl;
  exit(exit_code);
}


// calculate & display miles per gallon
void calcMyMPG(double initial_miles, double final_miles, double gallons_used) {

  // exit on impossible inputs
  if (gallons_used <= 0)
    error("Total galloons used cannot be equal to or less than zero");
  else if (final_miles < initial_miles)
    error("Final miles cannot be less than initial");

  // calculate mpg
  double miles_per_gallon = (final_miles - initial_miles) / gallons_used;

  // display results
  if (miles_per_gallon > 30) cout << "35 MPG is great keep the car";
  else if (miles_per_gallon < 20) cout << "Your MPG is under 20 MPG, Sell the car";
  else cout << "Over 20 MPG is OK";
  cout << endl;
}


int main() {
  // define, populate variables
  double initial_miles, final_miles, gallons_used;
  
  // populate data from console input
  cout << "Enter initial miles: ";
  cin >> initial_miles;
  cout << "Enter final miles: ";
  cin >> final_miles;
  cout << "Enter total gallons used: ";
  cin >> gallons_used;
  cout << endl;

  // pass to function for calculation & display 
  calcMyMPG(initial_miles, final_miles, gallons_used); 
}
