/*
  Ernest Izdebski, 2022-09-14

  A program that will calculate the area of a circle.  The user will be
  prompted to enter the diameter from the keyboard in inches.
*/

#include <iostream>
using namespace std;

// probably better to define as a constant
const double PI = 3.14159;

// might as well try writing a class once since it's C++
class Circle {
public:
  Circle(double _radius) {
    radius = _radius;
  }
  double radius;
  double area() {
    return PI * radius * radius;
  }
};

int main() {
  // define & populate variables
  double diameter;
  cout << "Input circle diameter (in.): ";
  cin >> diameter;

  Circle circle(diameter / 2);

  // output area
  cout << "A circle with a diameter of " << diameter << " inches has an area of "
    << circle.area() << " square inches." << endl;
}
