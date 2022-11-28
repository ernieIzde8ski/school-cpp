/*
  Ernest Izdebski, 2022-11-23

  Get payroll information with a struct & display its contents.
*/

#include <iostream>

template <typename T>T  input(std::string prompt = "") {
  T resp;
  std::cout << prompt;
  std::cin >> resp;
  return resp;
}

struct PayRoll {

  int empNumber;    // Employee number
  std::string name; // Employee's name
  double hours;     // Hours worked
  double payRate;   // Hourly payRate
  double grossPay;  // Gross Pay

  
  // display to console
  void display() {
    std::cout << "Employee #" << empNumber << ":"
      << "\n\tName:\t\t" << name
      << "\n\tHours:\t\t" << hours
      << "\n\tPayrate:\t" << payRate
      << "\n\tGross pay:\t" << grossPay
      << "\n";
  }

  // constructor that helps calculate grossPay
  PayRoll(int _empNumber, std::string _name, double _hours, double _payRate) {
    empNumber = _empNumber;
    name = _name;
    hours = _hours;
    payRate = _payRate;
    grossPay = hours * payRate;
  }

  // static methods, functions, close enough
  static PayRoll getInfo(int num = -1) {
    return PayRoll(
      (num != -1) ? num : input<int>("Employee number? "),
      input<std::string>("Employee name? "),
      input<double>("Hours worked?  "),
      input<double>("Pay rate?      ")
    );
  }

};


int main() {
  std::cout << "welcome to the Great Gizmo of Payroll 5000!\n";
  for (int i = 0;; i++) {
    std::cout << "Handling employee #" << i << std::endl;
    PayRoll employee = PayRoll::getInfo(i);
    std::cout << std::endl;
    employee.display();
    std::cout << std::endl << std::endl;
  }
}
