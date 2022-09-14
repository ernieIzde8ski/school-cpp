/*
  Ernest Izdebski, 2022-09-14

  A program that will calculate the area of a rectangle.  From the
  keyboard the user will enter the length and the width.
*/

// another class - it seems fitting to bundle information for one "thing" this way


#include <iostream>
using namespace std;

class Rectangle {
public:

  // default constructor is more useful in this code, come to think of it
  Rectangle() {
    cout << "Input rectangle length: ";
    cin >> length;
    cout << "Input rectangle width:  ";
    cin >> width;

    // use checks from other constructor
    if (length == 0 || width == 0) {
      cout << "input error: Length and width of a rectangle cannot equal zero";
      exit(1); // I've yet to look into the section that goes over exceptions,
      // but a non-zero exit code works for now 
    }
  }

  // if length and width are obtained otherwise, this constructor would be better
  Rectangle(double _length, double _width) {
    if (_length == 0 || _width == 0) {
      cout << "input error: Length and width of a rectangle cannot equal zero";
      exit(1);
    }
    length = _length;
    width = _width;
  }

  double length;
  double width;


  double area() { return length * width; };
  double perimeter() { return 2 * length + 2 * width; };
};

int main() {
  // define variables
  Rectangle rectangle;

  // output to console
  cout << "The area of a rectangle with dimensions " << rectangle.width << "\"x"
    << rectangle.length << "\" is " << rectangle.area() << "\"²." << endl;
}
