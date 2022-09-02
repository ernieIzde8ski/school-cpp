/*
  Ernest Izdebski, 2022-09-02

  Calculate & display payroll for a given employee.
*/

#include <iostream>
using namespace std;

int main() {
  // define variables
  string employee_name;
  int hours_worked;
  float pay_rate; // probably better to use a float, as payrate can go into cents

  // populate variables
  cout << "Provide employee name: ";
  // StackOverflow suggested this fix to cin only accepting
  // one whitespace-separated string at a time
  getline(cin, employee_name);
  cout << "Provide hours worked: ";
  cin >> hours_worked;
  cout << "Provide pay rate: ";
  cin >> pay_rate;

  // perform & display calculations
  // this is likewise a float to handle fractions of a dollar properly
  float gross_pay = hours_worked * pay_rate;
  cout << endl << "Gross Pay for " << employee_name << ": " << gross_pay << endl;
}
