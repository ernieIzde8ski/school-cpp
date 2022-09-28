/*
  Ernest Izdebski, 2022-09-28

  A program that can be used as a math tutor for a young student.
  The program should display two random numbers to be added, such as:
    247 
    + 129
    __________
*/
#include <csignal>
#include <iostream>
using namespace std;

// upper limit for the two random numbers generated
const int RANDOM_NUMBER_UPPER_LIMIT = 1000;

// ANSI colors, use any format + ANSI_NORMAL at the end to clear formatting
// repl.it seems to use some *nix system, so this should work fine
const string ANSI_NORMAL = "\x1b[0m";
const string ANSI_FG_RED = "\x1b[31m";
const string ANSI_FG_GREEN = "\x1b[32m";

// I am aware that globals are considered bad design, but this was easiest
// for making accessible to sigint_handler
int correct_guesses = 0;
int total_guesses = 0;

// interrupt signal handler
// displays how many answers were correct if any answers were given at all
void sigint_handler(int signum) {
  cout << endl << endl; // move away from previous lines
  // avoid illogical divide-by-zero issues
  if (total_guesses == 0) {
    cout << endl << "Goodbye!" << endl;
    exit(signum);
  }

  double ratio = double(correct_guesses) / total_guesses * 100;
  cout << endl << "correct guesses: " << correct_guesses << endl;
  cout << "total guesses:   " << total_guesses << endl;
  cout << "correct/total:   " << ratio << "%" << endl << endl;
  exit(signum);
}

// something like python's rjust but with ints,
// for right-justified padding as a string
// ex: rjust(5, 3) -> "  5"
string rjust(int num, int min_length, char pad=' ') {
  string res = to_string(num);
  min_length = min_length - res.length();
  // std::string(<int>, <char>) yields <char> repeated <int> times
  // max on min_length because this constructor throws an error
  // when the first value is less than zero
  return string(max(min_length, 0), pad) + res;
}

int main() {
  // let user know how to end program just in case
  cout << "welcome to Math Program; use ctrl+c to interrupt the Math Program" << endl << endl;
  signal(SIGINT, sigint_handler); // add interrupt signal handler

  // initialize pseudo-random num generator
  srand(time(0));

  while (true) {
    // define two random numbers in the [0, 1000) range
    int num_0 = rand() % RANDOM_NUMBER_UPPER_LIMIT;
    int num_1 = rand() % RANDOM_NUMBER_UPPER_LIMIT;
    int sum = num_0 + num_1;
    int input;

    // display random numbers, populate input variable
    // right-justified such that numbers are not out of alignment
    cout << "  " << rjust(num_0, 3) << endl;
    cout << "+ " << rjust(num_1, 3) << endl;
    cout << "_____" << endl;
    cin >> input;

    // check input
    total_guesses++;
    if (input == sum) {
      cout << ANSI_FG_GREEN << "correct!" << ANSI_NORMAL;
      correct_guesses++;
    } else {
      cout << ANSI_FG_RED << "incorrect, correct answer was: " << ANSI_NORMAL << sum;
    }
    cout << endl << endl;
  }
}
