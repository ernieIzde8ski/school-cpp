/*
  Ernest Izdebski, 2022-09-07

  A program that asks the user to input how many cookies he or she actually ate
  and then reports how many total calories were consumed. Assumes a bag of
  cookies holds 40 cookies, and an individual cookie is equivalent to 300.
*/

#include <iostream>
using namespace std;


const int calories_per_cookie = 300;

int main() {

  // the program requirements specify:
  //   Write a program that asks the user to input how many cookies he or she actually ate and then reports how many total calories were  consumed.
  // it doesn't say anything about using the 'Bag of cookies' information,
  // so I didn't

  // define & populate variables
  int cookies_consumed;
  cout << "how many Cookies did you Eat? ";
  cin >> cookies_consumed;

  // perform output logic
  cout << "Total Calories consumed: " << calories_per_cookie * cookies_consumed << endl;

}
