/*
  Ernest Izdebski, 2022-09-28

  A program that will ask the user to enter the width and length of a
  rectangle, and then display the rectangle’s area.
  
  It calls the following functions:

    .getLength: asks the user to enter the rectangle’s length, and
      then returns that value as a double.

    .getWidth: asks the user to enter the rectangle’s width, and then
      returns that value as a double.

    .getArea: accepts the rectangle’s length and width as arguments,
      and returns the rectangle’s area. The area is calculated by
      multiplying the length by the width.

    .displayData: accepts the rectangle’s length, width, and area as
      arguments. Displays them in an appropriate message on the screen.
*/

#include <iostream>
using namespace std;

// ANSI escape codes, use any format + ANSI_NORMAL at the end to clear formatting
// repl.it seems to use some *nix system, so this should work fine
const string ANSI_NORMAL = "\x1b[0m";
const string ANSI_BOLD = "\x1b[1m";
const string ANSI_UNDERLINE = "\x1b[4m";
const string ANSI_FG_RED = "\x1b[31m";

// function to generate lambda functions that take an prompt and return a double
auto doubleFunctionFactory(string prompt) {
  auto inner = [prompt]() {
    double resp;    // define
    cout << prompt; // populate
    cin >> resp;    // prompt
    return resp;    // return
  };
  return inner; // return the generated func
}

// lambda functions for length, width
const auto getLength = doubleFunctionFactory("Input rectangle length (cm): ");
const auto getWidth = doubleFunctionFactory("Input rectangle width (cm):  ");

// return area from length, width arguments
double getArea(double length, double width) {
  return length * width;
}



// do as the name says
void displayData(double length, double width, double area) {
  if (area <= 0) {
    cout << ANSI_FG_RED << "This can't be real" << ANSI_NORMAL << endl;
    return;
  }
  cout << "Length: " << length << " centimeters" << endl;
  cout << "Width:  " << width << " centimeters"<< endl;
  cout << "Area:   " << area << " centimeters squared" << endl;
}


int main() {
  cout << ANSI_BOLD << ANSI_UNDERLINE << "Welcome to the Rectangle Construction Facility™" << ANSI_NORMAL << endl << endl;
  // 'for' loops are usually syntactic sugar for 'while' loops, so I
  // assume this is allowed 
  for (int i = 0;; i++) {
    cout << ANSI_UNDERLINE << "Handling Rectangle no. " << i << ANSI_NORMAL << endl;
    // call functions & pass them into one another
    double length = getLength();
    double width  = getWidth();
    double area = getArea(length, width);
    cout << endl;
    displayData(length, width, area);
    cout << endl << endl; // separate this rectangle from the next
  }
}
