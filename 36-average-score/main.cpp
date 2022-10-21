/*
  Ernest Izdebski, 2022-10-21

  Return weighted grade for students based upon console input.
*/

#include <iostream>
#include <vector>
#include <tuple>
#include "ernie.hpp"

// the assignment isn't consistent with this value
// "HomeWork 30% (0.35)"
// but I chose 30% over .35 because it adds up to 100

const double WEIGHT_HOMEWORK = .30;
const double WEIGHT_MIDTERM = .35;
const double WEIGHT_FINAL = .35;

const std::vector<std::tuple<double, std::string>> _GRADES_MAP = {
  {95, "A"},
  {90, "A-"},
  {85, "B+"},
  {80, "B"},
  {75, "B-"},
  {70, "C+"},
  {65, "C"},
  {60, "C-"},
  {55, "D"},
};

// gets letter grade for any grade % passed into function
std::string get_letter_grade(double score) {
  for (std::tuple<double, std::string> keys : _GRADES_MAP) {
    if (score >= std::get<0>(keys)) return std::get<1>(keys);
  }
  // edge case
  return "F";
}

// calculates final grade for the entire class from params
double calculate_final_grade(double hw, double midterm, double final_exam) {
  return (hw * WEIGHT_HOMEWORK) + (midterm * WEIGHT_MIDTERM) + (final_exam * WEIGHT_FINAL);
}



int main() {
  // define
  double homework, midterm, final_exam;
  double score;
  std::string letter_grade;

  // populate
  homework = ernie::input<double>("Input total \% of completed homework: ");
  midterm = ernie::input<double>("Input midterm exam score: ");
  final_exam = ernie::input<double>("Input final exam score:   ");
  score = calculate_final_grade(homework, midterm, final_exam);
  letter_grade = get_letter_grade(score);

  // display
  std::cout << "\nYou got a " << score << "%.\n"
    "This is equivalent to a(n) " << letter_grade << ".\n\n";
}
