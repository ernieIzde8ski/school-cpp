/*
  Ernest Izdebski, 2022-09-14

  A program that displays a letter grade when a score from 0 to 100 is entered.
*/

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// it will be easier to manipulate in the future and less likely to be
// accidentally inconsistent if we just iterate over a vector or array
// instead of if/else-if statements

// a mapping (although not a true map) of minimum scores to letter grade values
// in descending sort order by score value
const vector<tuple<int, string>> grades = {
  tuple<int, string>(90, "A"),
  tuple<int, string>(80, "B"),
  tuple<int, string>(70, "C"),
  tuple<int, string>(60, "D"),
  tuple<int, string>(50, "F"),
};

// get letter grade for a given score, preferably for one in the range [0, 100]
string get_letter_grade(int score) {
  for (tuple<int, string> grade : grades) {
    if (score >= get<0>(grade)) return get<1>(grade);
  }
  return "F"; // it's not specified in the assignment, but any grade in the range [0, 50)
  // is excluded by the above definitions, so here's the extra case
}

int main() {
  // populate & define variable
  float score; // unconcerned with precision
  cout << "Input score: ";
  cin >> score;
  cout << endl;

  // display value
  cout << "Score: " << score << endl;
  cout << "Corresponding letter grade: " << get_letter_grade(score) << endl;
}
