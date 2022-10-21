/*
  Ernest Izdebski, 2022-10-19

  A program that lets the user enter the total rainfall for each of 12
  months into an array of doubles.  The program should calculate and
  display the total rainfall for the year, the average monthly
  rainfall, and the months with the highest and lowest amounts.
*/

#define elif else if
#include <iostream>
#include <numeric>
#include "ernie.hpp"

const int T_MONTHS = 12;
const std::string MONTH_NAMES[T_MONTHS] = {
  "Jan", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

int main() {
  double rainfalls[T_MONTHS];
  double total_rainfall;
  double average_rainfall;
  int lowest_month, highest_month;

  // populate array
  for (int i = 0; i < T_MONTHS; i++) {
    do rainfalls[i] = ernie::input<double>("Input rainfall (cm) for " + MONTH_NAMES[i] + ".: ");
    while (rainfalls[i] < 0);
  }

  // perform calculations
  total_rainfall = ernie::arraySum(rainfalls, T_MONTHS);
  average_rainfall = total_rainfall / T_MONTHS;
  lowest_month = ernie::arrayLowestValueIndex(rainfalls, T_MONTHS);
  highest_month = ernie::arrayHighestValueIndex(rainfalls, T_MONTHS);

  // display to console
  std::cout << std::endl;
  std::cout << "Total Yearly Rainfall:     " << total_rainfall << "cm" << std::endl;
  std::cout << "Monthly Average Rainfall:  " << average_rainfall << "cm" << std::endl;
  std::cout << "Month with Least Rainfall: " << MONTH_NAMES[lowest_month] << std::endl;
  std::cout << "Month with Most Rainfall:  " << MONTH_NAMES[highest_month] << std::endl;
  std::cout << std::endl;
}
