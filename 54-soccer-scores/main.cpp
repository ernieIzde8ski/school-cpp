/*
  Ernest Izdebski, 2022-11-23

  Keeps track of 6 soccer players (one for each member of a team) and
  displays a table and related information on said team.
*/

#include <cmath>
#include <iostream>
#include <numeric>
#define elif else if

// so strings don't have repeat methods ? Really ?
std::string repeatString(std::string s, unsigned n = 5) {
  std::string copy = s;
  while (n--) copy += s;
  return copy;
}

// right-justify a string with given padding and minimum length
std::string rjust(std::string s, int chars, char filler = ' ') {
  return s + std::string(chars - s.length(), filler);
}

// rjust with typecasting int to std::string
std::string rjust(int num, int chars, char filler = ' ') {
  return rjust(std::to_string(num), chars, filler);
}

// function for getting total number of digits in an integer
int totalDigits(int num) {
  return int(std::log10(num)) + 1;
}

// simple input func
template <typename T>T  input(std::string prompt = "") {
  T resp;
  std::cout << prompt;
  std::cin >> resp;
  return resp;
}

struct SoccerPlayer {
  int num;
  int pointsScored;
  std::string name;

  // SoccerPlayer() {};

  // constructor from std::cin
  static SoccerPlayer fromStdin(int num) {
    int pointsScored;
    std::string name = input<std::string>("give player name: ");
    do {
      pointsScored = input<int>("give total points scored: ");
    } // the second conditional is only ever evaluated when the first 
    // passes too, and it returns std::cout, which happens to be truthy
    while (pointsScored < 0
      && (std::cerr << "error: cannot have less than zero points" << std::endl)
      );
    return { num, pointsScored, name };
  }

  // method call to change into string, used in debugging
  std::string to_string() {
    return "SoccerPlayer(num=" + std::to_string(num)
      + ",pointsScored=" + std::to_string(pointsScored)
      + ",name=" + name + ")";
  }
};

void displayTeam(SoccerPlayer team[], int totalPlayers) {
  SoccerPlayer* bestPlayer = (&team[0]);
  int pointsScored = 0;
  // default sizes set to the lengths of '#', 'name', 'score'
  int maxLineLengths[3] = { 1, 4, 5 };
  int lineLengths[totalPlayers][3];

  // iterate through each player to find out which is the best
  // and the lengthiest value of each 
  for (int i = 0; i < totalPlayers; i++) {
    // finding best player
    SoccerPlayer player = team[i];
    if (player.pointsScored > bestPlayer->pointsScored) bestPlayer = &player;

    // checking lengthiest values
    int lineLength[3];

    lineLength[0] = totalDigits(player.num);
    lineLength[1] = player.name.length();
    lineLength[2] = totalDigits(player.pointsScored);

    for (int j = 0; j < 3; j++)
      maxLineLengths[j] = std::max(lineLength[j], maxLineLengths[j]);
  }

  // display logic slowly starts here
  std::string ENDLINE; // line to be displayed in-between individual scores
  {
    // std::accumulate can be used in this way to sum values
    int maxLineLength =
      std::accumulate(maxLineLengths, maxLineLengths + 3, 0);
    ENDLINE = repeatString("─", maxLineLength + 7);
  }

#define PRINTBORDER(S0,S1) std::cout << S0 << ENDLINE << S1 << std::endl
#define PRINTLINE(NUM,NAME,SCORE) \
  std::cout << "| " << rjust(NUM, maxLineLengths[0]) << " | "\
    << rjust(NAME, maxLineLengths[1]) << " | "\
    << rjust(SCORE, maxLineLengths[2]) << " |\n"

  // displaying a table
  std::cout << "Team statistics: " << std::endl;
  PRINTBORDER("┌", "┐");
  PRINTLINE("#", "name", "score");
  for (int i = 0; i < totalPlayers; i++) {
    SoccerPlayer player = team[i];
    PRINTBORDER("│", "│");
    PRINTLINE(player.num, player.name, player.pointsScored);
    pointsScored += player.pointsScored; // incrementing global score
  }
  PRINTBORDER("└", "┘");

  // displaying extra statistics
  if (totalPlayers < 2) return; // silly to display information for only one player
  std::cout << "Of all " << totalPlayers << " players, " << bestPlayer->name
    << " was the best, scoring " << bestPlayer->pointsScored << " points in total.\n"
    "\nAs a whole, the team accumulated " << pointsScored << " points.\n";
}

#define USAGE "usage: \n\t"
int main(int argc, char** argv) {
  unsigned PLAYERS = 6;
  if (argc == 1) {}
  elif(argc == 2) {
    // secretly I allow for changing the number of member in team
    // so that testing this file is significantly easier
    PLAYERS = atoi(argv[1]);
  } else {
    std::fprintf(stderr, "usage: %s [totalPlayers=6]\n", argv[0]);
    exit(1);
  }

  // create array
  std::cout << "Making team with " << PLAYERS << " players.\n";
  SoccerPlayer team[PLAYERS];
  // populate array
  for (int i = 0; i < PLAYERS; i++) {
    std::cout << "soccer player #" << i << std::endl;
    team[i] = SoccerPlayer::fromStdin(i);
  }
  std::cout << std::endl;

  // display array
  displayTeam(team, PLAYERS);
}
