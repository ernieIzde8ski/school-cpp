/*
  Ernest Izdebski, 2022-10-28

  A painting company has determined that for every 115 square feet of
  wall space, one gallon of paint and eight hours of labor will be
  required.  The company charges $18.00 per hour for labor.  Write a
  modular program that allows the user to enter the number of rooms
  that are to be painted and the price of the paint per gallon.  It
  should also ask for the square feet of wall space in each room,
  before finally displaying certain data.
*/

#include <iostream>
#include "ernie.hpp"

// how many square feet can be covered by a single gallon of paint
const double SQUARE_FEET_PER_GALLON = 115;
// the hours worked per gallon of paint
const double HOURS_WORKED_PER_GALLON = 8;
// the charge per hour of labor
const double PAY_RATE_PER_HOUR = 18.00;

int main() {
  // display intro message
  std::cout << "Welcome to Painting Simulator 2022!\n"
    << "- Paint is spread at a rate of " << SQUARE_FEET_PER_GALLON << " ft^2 per gal.\n"
    << "- Each gallon takes " << HOURS_WORKED_PER_GALLON << " hours of work to be placed.\n"
    << "- You are charged " << PAY_RATE_PER_HOUR << "$ for each hour of work.\n"
    << std::endl;

  // define & populate base variables
  double paintCostPerGallon = ernie::input<double>("How much does paint cost ($) per gallon?\t");
  int totalRooms = ernie::input<int>("How many rooms are to be painted?\t");

  // populate array
  double rooms[totalRooms];
  std::cout << "how many square feet...\n";
  for (int i = 0; i < totalRooms; i++) {
    rooms[i] = ernie::input<double>("\tin room #" + std::to_string(i) + "? ");
  }

  // define, calculate remaining variables
  double gallonsRequired, hoursRequired, totalPaintCost, totalLaborCost, totalCost;

  gallonsRequired = ernie::arraySum(rooms, totalRooms) / SQUARE_FEET_PER_GALLON;
  totalPaintCost = gallonsRequired * paintCostPerGallon;

  hoursRequired = gallonsRequired * HOURS_WORKED_PER_GALLON;
  totalLaborCost = hoursRequired * PAY_RATE_PER_HOUR;

  totalCost = totalLaborCost + totalPaintCost;

  // display
  std::cout << "\n\n"
    << "Required gallons of paint:\t" << gallonsRequired << "\n"
    << "Required hours of labor:\t" << hoursRequired << "\n"
    << "Total paint cost:\t\t" << totalPaintCost << "\n"
    << "Total labor cost:\t\t" << totalLaborCost << "\n"
    << "Overall cost:\t\t\t" << totalCost
    << std::endl << std::endl;
}
