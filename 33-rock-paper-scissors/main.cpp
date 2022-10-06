/*
  Ernest Izdebski, 2022-09-30

  A program that lets the player play Rock Paper Scissors against the
  computer. Press Q (or SIGINT) to exit.


  at this point I'm fairly confident the homework is being compiled
  on a -nix system, and with the extent of that confidence being
  abused in this assignment I hope that I'm correct; at the very
  least, it works on replit


  while debugging, it may be useful to run:
    for (( ; ; )) do printf '\n'; sleep 1; done | ./main
  or:
    yes '' | ./main
  to spam the Enter key into the script repeatedly
*/

// inclusions
#include <iostream>
#include <map>
#include <signal.h>
#include <vector>
#include "conio.h"

using namespace std;

// weep
#define elif else if


// rock, paper, and scissor constants
enum RockPaperScissors { rock, paper, scissors };
const RockPaperScissors _RPS_Array[] = { rock, paper, scissors };
RockPaperScissors random_rps() { return _RPS_Array[rand() % 3]; }
map<RockPaperScissors, RockPaperScissors> RPS_Matchups = { {rock, scissors}, {scissors, paper}, {paper, rock} };
string rps_names(RockPaperScissors& choice) {
  switch (choice) {
  case rock: return "ROCK";
  case paper: return "PAPER";
  case scissors: return "SCISSORS";
  }
  return "ERROR";
}

// ANSI escape sequences, use any format + ANSI_NORMAL at the end to clear formatting
// repl.it seems to use some *nix system, so this should work fine
string ANSI_CHAR(string code) { return "\x1b[" + code + "m"; }
string ANSI_CHAR(int code) { return ANSI_CHAR(to_string(code)); }
const string ANSI_NORMAL = ANSI_CHAR(0);
const string ANSI_UNDERLINE = ANSI_CHAR(4);
const string ANSI_FG_RED = ANSI_CHAR(31);
const string ANSI_FG_GREEN = ANSI_CHAR(32);
const string ANSI_FG_BLUE = ANSI_CHAR(34);
const string ANSI_FG_MAGENTA = ANSI_CHAR(35);
const string ANSI_BG_RED = ANSI_CHAR(41);
const string ANSI_BG_GREEN = ANSI_CHAR(42);
const string ANSI_BG_BLUE = ANSI_CHAR(44);
const string ANSI_BG_MAGENTA = ANSI_CHAR(45);
const string ANSI_BG_WHITE = ANSI_CHAR(47);


// quick error exit
void error(string msg, int exit_code = 1) {
  cerr << msg << endl;
  exit(exit_code);
}


// wipe console via ANSI escape code
void clear_console() {
  // https://paulschou.com/tools/ansi/escape.html
  cout << "\033[2J\033[1H";
}

struct RPS_MenuItem {
  string name;
  RockPaperScissors value;
  bool operator== (RPS_MenuItem other) {
    return (other.name == name) && (other.value == value);
  }
};


// adjust contents of menu such that it displays properly
// returns the adjusted size of inner items
int prepare_menu(vector<RPS_MenuItem>& menu) {
  int menu_size = menu.size();
  if (menu_size == 0) error("error: menu must contain items");

  int max_string_size = -1;

  // probably not the best optimized (2 for loops) but I couldn't think of a better way
  for (RPS_MenuItem item : menu) {
    max_string_size = max(max_string_size, int(item.name.length()));
  }

  for (RPS_MenuItem& item : menu) {
    item.name = "| " + item.name + string(max_string_size - item.name.length(), ' ') + " |";
  }

  return max_string_size;
}

// displays a menu with selected item
void display_menu(vector<RPS_MenuItem> menu, string filler, int selected) {
  cout << filler << endl;
  string color;
  int size = menu.size();
  for (int i = 0; i < size; i++) {
    color = (i == selected) ? ANSI_BG_WHITE : ANSI_BG_RED;
    cout << color << menu[i].name << ANSI_NORMAL << endl;
    cout << filler << endl;
  }
}

// global game variables, such that it can be accessed from exit function
int games_played = 0;
int player_wins = 0;
int player_losses = 0;

// display function called on exit
void quit(int code = 0) {
  cout << endl;

  if (!games_played) {
    // early exit in event of no games played
    cout << ANSI_FG_MAGENTA << "goodbye!" << ANSI_NORMAL << endl;
    exit(code);
  };
  
  cout << "Total games:         " << ANSI_FG_BLUE << games_played << ANSI_NORMAL << endl;
  cout << "Total player wins:   " << ANSI_FG_GREEN << player_wins << ANSI_NORMAL << endl;
  cout << "Total player losses: " << ANSI_FG_RED << player_losses << ANSI_NORMAL << endl;

  // calculate win/loss ratio before display
  // player_wins must first be typecast to double to avoid flooring the value
  // we use player_wins + player_losses instead of total_games because
  // total_games includes tied games, which is unfair
  double ratio = double(player_wins) / (player_wins + player_losses);

  cout << "Win ratio:           " << ((ratio < .5) ? ANSI_BG_RED : ANSI_BG_GREEN) 
    << ratio << "%" << ANSI_NORMAL << endl << endl; 
  exit(code);
}

// determine result of rock paper scissors bet
// increments globally scoped variables
string rps_shoot(RockPaperScissors& choice) {
  RockPaperScissors computer_choice = random_rps();
  
  games_played++;

  if (RPS_Matchups[computer_choice] == choice) {
    player_losses++;
    return ANSI_BG_MAGENTA + "SORRY,,," + ANSI_NORMAL + " COMPUTER CHOSE "
      + ANSI_BG_GREEN + rps_names(computer_choice) + " . . . " + ANSI_NORMAL
      + "\nYOU " + ANSI_BG_RED + "LOSE . . ." + ANSI_NORMAL;
  } elif(RPS_Matchups[choice] == computer_choice) {
    player_wins++;
    return ANSI_BG_MAGENTA + "HOORAH ! " + ANSI_NORMAL + "The COMPUTER CHOSE "
      + ANSI_BG_RED + rps_names(computer_choice) + ANSI_NORMAL + " , \n"
      + ANSI_BG_GREEN + "YOU WIN !!!!  " + ANSI_NORMAL;
  } else return ANSI_FG_BLUE + "WHAT . . . . TRY AGAIN . . .. . .." + ANSI_NORMAL
    + "\n" + ANSI_BG_BLUE + "(You and the Computer had the Same Result)" + ANSI_NORMAL;

  return "ROLLING CODE IS UNIMPLEMENTED . . .";
}

int main() {
  // assign quit function to sigint handler
  signal(SIGINT, quit);

  srand(time(0)); // initialize random number generator
  vector<RPS_MenuItem> rps_menu = { {"Rock", rock}, {"Paper", paper}, {"Scissors", scissors} };

  // define & populate variables
  int rps_menu_item_size = prepare_menu(rps_menu);
  string filler = '|' + string(rps_menu_item_size + 2, '-') + "|";
  int selected_entry = 0; // selected item in range [0, 3)
  const int selected_lower_bound_inclusive = 0; // selected should not go below 0
  const int selected_upper_bound_exclusive = 3; // selected should not equal or go above 3

  // infinite loop (until forcibly broken)
  string premenu_line = "At Any point , press Q to exit";
  while (true) {
    // prepare console output
    clear_console();
    cout << premenu_line << endl << endl;
    display_menu(rps_menu, filler, selected_entry);
    cout << endl << ANSI_UNDERLINE << "Game #" << games_played << ANSI_NORMAL << endl;

    // accept console input
    int choice = getch();
    if (choice == 'q' || choice == 'Q') break;

    // begin evaluating console input
    if (choice == '\n') {
      // currently selected menu item has been chosen
      premenu_line = rps_shoot(rps_menu[selected_entry].value);
    } elif(choice == 27) {
      // arrow keys send the following three strokes:
      // 27 (Escape), 91 ('['), and one stroke in range [65, 69) ('A', 'B', 'C', 'D')
      getch(); // ignoring the left square bracket
      choice = getch();
      if (choice == 65 || choice == 68) {
        // up arrow, left arrow: move selection to above entry
        if (selected_entry == selected_lower_bound_inclusive) // wrap entry around
          selected_entry = selected_upper_bound_exclusive;
        selected_entry--;
      } elif(choice == 66 || choice == 67) {
        // down arrow, right arrow: move selection to below entry
        selected_entry++;
        if (selected_entry == selected_upper_bound_exclusive)
          selected_entry = selected_lower_bound_inclusive; // wrap entry around
      };
    } else // in the event of an unrecognized keypress
      premenu_line = ANSI_BG_RED + "what" + ANSI_NORMAL + "\n" + ANSI_FG_RED + "(send an arrow key, enter, or 'q')" + ANSI_NORMAL;
  }
  quit();
}
