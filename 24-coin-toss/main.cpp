/*
  Ernest Izdebski, 2022-09-28

  Simulate a coin toss game, best out of seven. 0 for heads, 1 for
  tails.
*/

#include <iostream>
using namespace std;

// ANSI colors, use any format + ANSI_NORMAL at the end to clear formatting
// repl.it seems to use some *nix system, so this should work fine
const string ANSI_NORMAL = "\x1b[0m";
const string ANSI_FG_RED = "\x1b[31m";
const string ANSI_FG_GREEN = "\x1b[32m";
const string ANSI_BG_RED = "\x1b[41m";
const string ANSI_BG_GREEN = "\x1b[42m";


// recommendation: playing the game is boring,
// so run `yes 0 | ./main` instead

int main() {
  // define variables
  int successes = 0;
  int failures = 0;

  // initialize pseudo-random number generator
  srand(time(0));

  // initialize game loop
  for (int i = 0; i < 7; i++) {
    // obtain guess, coin flip
    string input;
    do {
      cout << "[0] Heads or [1] Tails?  ";
      cin >> input;
    } while (input != "0" && input != "1");
    string coin = to_string(rand() % 2);

    // display whether the guess was correct or not
    if (input == coin) {
      cout << ANSI_FG_GREEN << "correct !" << ANSI_NORMAL;
      successes++;
    } else {
      cout << ANSI_FG_RED << "FAIL . . ." << ANSI_NORMAL;
      failures++;
    }
    cout << endl;
  }

  // display final results
  // no == check because 7 is an odd number ==> integer parts always be > or < 
  string color, res = (successes > failures) ? (ANSI_BG_GREEN, "WON") : (ANSI_BG_RED, "LOST");
  cout << "Overall, you have: ";
  if (failures > successes) cout << ANSI_BG_RED << "LOST";
  else cout << ANSI_BG_GREEN << "WON";
  cout << " the game" << ANSI_NORMAL << " (" << failures <<
       " losses, " << successes << " wins)" << endl;
}
