/*
  Ernest Izdebski, 2022-11-28

  Program to grade a driver's license exam using parallel arrays.
*/

#include <iostream>
#include "conio.h"

#define elif else if
#define SOLUTIONS 20

int MIN_CORRECT = 15;

const char CORRECT_SOLUTIONS[SOLUTIONS] = {
  'B', 'D', 'A', 'A', 'C',
  'A', 'B', 'A', 'C', 'D',
  'B', 'C', 'D', 'A', 'D',
  'C', 'C', 'B', 'D', 'A',
};

// message displayed at program start
void introMessage() {
  std::cout << "Welcome to Driving Test\n"
    << "\tmininum passing grade is set to " << MIN_CORRECT
    << "/" << SOLUTIONS << " questions answered correctly.\n\n";
}

// gets a letter in the range ABCD from prompt
char get_abcd(std::string prompt = "") {
  char resp;
  while (true) {
    std::cout << prompt;
    resp = conio::getche();
    std::cout << "\n";
    if (resp >= 'a') resp -= 32; // shift lowercase
    if (resp >= 'A' && resp <= 'D') return resp;
    std::cerr << "\nmust be a,b,c,d\n";
  }
}


// this does what you think it does
void populateSolutionsFromStdin(char solutions[SOLUTIONS]) {
  std::cout << "give student solutions:\n";
  for (int i = 0; i < SOLUTIONS; i++)
    solutions[i] = get_abcd("#" + std::to_string(i+1) + ":\t");
}

// grades a given set of solutions by comparing to CORRECT_SOLUTIONS
void gradeSolutions(char solutions[SOLUTIONS]) {
  int correctSolutions = 0;

  // print incorrect ones, accumulate number of correct solutions
  for (int i = 0; i < SOLUTIONS; i++) {
    char studentChoice = solutions[i];
    char correctChoice = CORRECT_SOLUTIONS[i];
    if (studentChoice == correctChoice) correctSolutions++;
    else std::cout << "#" << i << ":\texpected " << correctChoice
      << ", got " << studentChoice << std::endl;
  }

  // print score
  std::cout << std::endl << correctSolutions << "/" << SOLUTIONS << ". ";
  if (correctSolutions < MIN_CORRECT)
    std::cout << "You flunked.\n";
  elif (correctSolutions == SOLUTIONS)
    std::cout << "Perfect score!\n";
  elif(correctSolutions == MIN_CORRECT)
    std::cout << "You just barely passed. Congrats?\n";
  else std::cout << "You passed!\n";
}

int main(int argc, char** argv) {
  // allow command-line arguments to override MIN_CORRECT
  if (argc == 2)
    MIN_CORRECT = atoi(argv[1]);
  elif(argc != 1) {
    std::cerr << "usage: " << argv[0] << " [min_passing_grade]\n";
    return 1;
  }
  introMessage();
  // declare
  char studentSolutions[SOLUTIONS];

  // populate
  populateSolutionsFromStdin(studentSolutions);

  // calculate/display
  std::cout << std::endl;
  gradeSolutions(studentSolutions);
}
