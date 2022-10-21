/*
  Ernest Izdebski, 2022-10-21

  Determine, from input, the day of the week with lowest sales, day with
  highest sales, total weekly sales, and average weekly sales.
*/
#include "ernie.hpp"
#include <iostream>

// total weekdays
const int WEEKDAYS = 5;
// ordered mapping of number: name for weekdays
const std::string WEEKDAY_NAMES[WEEKDAYS] = { 
  "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"
};


int main() {
  // define
  double week_sales[WEEKDAYS];
  int lowest_sales_day, highest_sales_day;
  double total_sales, average_sales;

  // populate
  for (int i = 0; i < WEEKDAYS; i++) {
    week_sales[i] = ernie::input<double>("Input daily sales for " + WEEKDAY_NAMES[i] + ": ");
  } 

  // calculate

  /* 
    technically, running these as separate functions instead of
    combining them into one loop is more expensive than necessary, but
    I think this approaches the point where time spent programming is
    more valuable than time spent executing programs themselves
    
    in other words, it is more time-efficient to call a library I've
    already written, even if it means the code execution itself will
    be a couple milliseconds laggier
  */

  lowest_sales_day = ernie::arrayLowestValueIndex(week_sales, WEEKDAYS);
  highest_sales_day = ernie::arrayHighestValueIndex(week_sales, WEEKDAYS);
  total_sales = ernie::arraySum(week_sales, WEEKDAYS);
  average_sales = total_sales / WEEKDAYS;

  // display
  std::cout << std::endl;
  std::cout << "Day with lowest sales:  " << WEEKDAY_NAMES[lowest_sales_day] << "\n";
  std::cout << "Day with highest sales: " << WEEKDAY_NAMES[highest_sales_day] << "\n";
  std::cout << "Average weekly sales:   " << average_sales << "\n";
  std::cout << "Total weekly sales:     " << total_sales << "\n";
  std::cout << std::endl;
}
