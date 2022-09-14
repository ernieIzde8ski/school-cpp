/*
  Ernest Izdebski, 2022-09-14

  A program that calculates and displays a person’s body mass index
  (BMI).
*/

#include <iostream>
using namespace std;

// Function to calculate BMI. Params are in imperial (lb, in)
double calculate_BMI(double weight, double height) {
  // dividing by height twice is equivalent to dividing by the square of height
  return weight * 703 / height / height;
}

int main() {
  // define vars
  double weight;
  double height;
  double BMI;
  string evaluation;

  // populate vars
  cout << "Input weight (lb.): ";
  cin >> weight;
  cout << "Input height (in.): ";
  cin >> height;

  if (height == 0) {
    cout << "division error: you can't be that short.";
    exit(1);
  }

  // output BMI to console
  BMI = calculate_BMI(weight, height);
  evaluation = (BMI < 18.5) ? "underweight" : (BMI > 25) ? "overweight" : "optimal weight";
  cout << "Your Body Mass Index is " << BMI << ". This is considered " << evaluation << ".\n";
}
