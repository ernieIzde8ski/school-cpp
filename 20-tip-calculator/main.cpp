/*
  Ernest Izdebski, 2022-09-23

  A program that computes the tax and tip on a restaurant bill for a
  patron.  From the keyboard enter the bill amount.  The tax should be
  6.75 percent of the meal cost.  The tip should be 15 percent of the
  total after adding the tax.  Display the meal cost, tax amount, tip
  amount, and the total bill on the screen
*/

#include <iostream>
using namespace std;

// calculation constants
const double TAX_RATE = .0675;
const double TIP_RATE = .15;

int main() {
  // define variables
  double meal_cost, tax_cost, tip_cost, bill_total;
  cout << "Input your Meal's Cost: ";
  cin >> meal_cost;
  cout << endl;

  // perform calculations
  tax_cost = meal_cost * TAX_RATE;
  tip_cost = meal_cost * TIP_RATE;
  bill_total = meal_cost + tax_cost + tip_cost;

  // display results
  cout << "MEAL COST:  +   " << meal_cost << endl;
  cout << "TOTAL TAX:  +   " << tax_cost << endl;
  cout << "TIP TOTAL:  +   " << tip_cost << endl;
  cout << "FINAL CHARGE:   " << bill_total << endl << endl;
}
