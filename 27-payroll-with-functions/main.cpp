/*
  Ernest Izdebski, 2022-09-28

  A program that will calculate a simple payroll with functions.
*/

#include <iostream>
using namespace std;

// calculates gross pay from hours worked and pay rate
double calcGrossPay(double hours, double pay_rate) {
  return hours * pay_rate;
}

// calculate net pay using the formula: net = gross - (gross * tax)
double calcNetPay(double gross_pay, double tax_rate = .25) {
  return gross_pay - (gross_pay * tax_rate);
}

// print given net pay
void displayPayCheck(double net_pay) {
  cout << "Paycheck: " << net_pay << "$" << endl << endl;
}

int main() {
  // "while loop"
  for (int i = 0;; i++) {
    cout << "handling employee #" << i << endl;

    double hours_worked;
    double pay_rate;

    cout << "input hours worked: ";
    cin >> hours_worked;
    cout << "input pay rate: ";
    cin >> pay_rate;

    // run all calculations in one line
    displayPayCheck(calcNetPay(calcGrossPay(hours_worked, pay_rate)));
  }
}
