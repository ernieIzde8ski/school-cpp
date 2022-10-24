/*
  Ernest Izdebski, 2022-10-23

  Crunch numbers on the daily feeding habits of three monkeys over the
  course of one week.
*/

#include <iostream>
#include "ernie.hpp"

const int TOTAL_MONKEYS = 3;
const int WEEKDAYS = 7;
const std::string WEEKDAY_NAMES[WEEKDAYS] = { "MON", "TUES", "WED", "THUR", "FRI", "SAT", "SUN" };

// returns a number that is either zero or positive from console input
double positive_real_number(
  std::string prompt = "", std::string err_msg = "error: input cannot be negative"
) {
  double resp;
  while (true) {
    resp = ernie::input<double>(prompt);
    if (resp >= 0) return resp;
    std::cerr << err_msg << std::endl;
  }
}


int main() {
  // define
  double monkeys[TOTAL_MONKEYS][WEEKDAYS];
  double average_food_eaten[WEEKDAYS], least_food_eaten, most_food_eaten;

  // populate
  for (int i = 0; i < TOTAL_MONKEYS; i++) {
    std::cout << "Handling monkey #" << i << ":\n"
      "\tInput total pounds eaten per day for this monkey.\n";
    double* monkey = monkeys[i];
    for (int day = 0; day < WEEKDAYS; day++) {
      monkey[day] = positive_real_number("\t" + WEEKDAY_NAMES[day] + "?\t");
    }
  }
  std::cout << std::endl;

  // calculate
  // in my defense I was half asleep while writing this
  {
    // scope abuse to create variables that disappear with the scope
    double food_eaten[TOTAL_MONKEYS]; // total food eaten in the week per monkey

    // iterate over each monkey and add them to the two arrays 
    for (int i = 0; i < TOTAL_MONKEYS; i++) {
      for (int day = 0; day < WEEKDAYS; day++) {
        food_eaten[i] += monkeys[i][day];
        average_food_eaten[day] += monkeys[i][day];
      }
    }

    // fix the average_food_eaten just being total_food_eaten
    for (int day = 0; day < WEEKDAYS; day++) {
      average_food_eaten[day] /= TOTAL_MONKEYS;
    }

    // get min/max values of the array
    least_food_eaten = most_food_eaten = food_eaten[0];
    for (int i = 1; i < TOTAL_MONKEYS; i++) {
      double eaten = food_eaten[i];
      if (eaten < least_food_eaten) least_food_eaten = eaten;
      elif(eaten > most_food_eaten) most_food_eaten = eaten;
    }
  }

  std::cout << "\n\n"
    << "Least food eaten:\t" << least_food_eaten << " lb.\n"
    << "Most food eaten:\t" << most_food_eaten << " lb.\n"
    << "Average food eaten on the following days:\n";
  for (int day = 0; day < WEEKDAYS; day++ ) {
    std::cout << "\t" << WEEKDAY_NAMES[day] << ":\t" << average_food_eaten[day] << std::endl;
  }

  // aint got no time for no "bar charts"
  std::cout << std::endl;
}
