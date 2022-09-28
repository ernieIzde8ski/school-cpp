/*
  Ernest Izdebski, 2022-09-28

  "Write a function named fallingDistance that accepts an object's
  falling time (in seconds) as an argument. The function should return
  the distance, in meters, that the object has fallen during that time
  interval. Write a program that demonstrates the function by calling
  it in a loop that passes the time as arguments, and displays the
  return value."
*/

#include <iostream>
#include <cmath>

using namespace std;

// for checking against relativity
const double speed_of_light = 299792458;

// calculates how much an object has fallen in meters
double fallingDistance(double time, double gravity = 9.8) {
  return .5 * gravity * pow(time, 2);
}

int main() {

  for (int i = 0;; i++) {
    cout << "handling Falling Object no. " << i << endl;
    double time, distance;
    cout << "how many seconds has this object been falling? ";
    cin >> time;
    distance = fallingDistance(time);
    cout << "this Object has fallen a distance of " << distance << " meters." << endl;

    // check against relativity
    double average_velocity = distance / time;
    if (average_velocity > speed_of_light) {
      cout << "The supposed average velocity (" << average_velocity << 
        " m/s) exceeds lightspeed (" << speed_of_light << " m/s)," <<
        endl << "however this is not possible" << endl;
    }
    cout << endl;
  }
}
