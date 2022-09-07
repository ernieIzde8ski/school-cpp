/*
  Ernest Izdebski, 2022-09-07

  A program that will allow you to deposit money into your bank account, withdrawal from your bank account and display your balance once you have performed each action.
*/

#include <iostream>
using namespace std;

int main() {
  // initialize variables
  double balance = 5000;
  double deposit;
  double withdrawal;

  // populate variables
  cout << "Current balance:" << balance << endl;
  cout << "Withdraw a sum: ";
  cin >> withdrawal;
  cout << "Deposit a sum:  ";
  cin >> deposit;

  // recalculate balance 
  balance = balance + deposit - withdrawal;
  cout << "Final balance:  " << balance << endl << endl;
}
