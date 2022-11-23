/*
  Ernest Izdebski, 2022-11-18

  Renders a 10x10 multiplication table.
*/

#include <iostream>
#include <numeric>
#include <vector>
#define elif else if

// right-justify a string with given padding and minimum length
std::string rjust(std::string s, int chars, char filler = ' ') {
  return s + std::string(chars - s.length(), filler);
}

// rjust with typecasting int to std::string
std::string rjust(int num, int chars, char filler = ' ') {
  return rjust(std::to_string(num), chars, filler);
}


void drawTable(int rows, int cols) {
  // this code came very close to many off-by-one errors

  // The last member of any column should have the largest number of digits

  // we iterate starting at 1 for this code, because we want to
  // multiply starting with values of one. to compensate, I've added
  // elements we won't be accessing at position 0.

  std::vector<std::string> lastRow = { "" };
  std::vector<int> lastRowWidths = { -1 };
  std::string sepRow; // value of the in-between rows

  for (int col = 1; col <= cols; col++) {
    std::string product = std::to_string(col * rows);
    lastRow.push_back(product);
    lastRowWidths.push_back(product.length());
  }

  {
    // so there's a native c++ function that can be used to sum
    // who knew ?
    int sepRowLength =
      std::accumulate(lastRowWidths.begin(), lastRowWidths.end(), 0)
      + (lastRowWidths.size() * 3) - 3;
    sepRow = std::string(sepRowLength, '-');
  }

#define PRINT_COL(col) std::cout << "| " << col << " "
#define PRINT_BLANK(start, stop) std::cout << start << sepRow << stop << std::endl;
#define END_ROW std::cout << "|\n";

  PRINT_BLANK('+', '+');
  // iterate starting at 1 to multiply easier
  for (int row = 1; row < rows; row++) {

    for (int col = 1; col <= cols; col++) {
      // arrays start at zero but this iteration starts at 1, so have to adjust
      PRINT_COL(rjust(row * col, lastRowWidths[col]));
    }
    END_ROW;
    PRINT_BLANK('|', '|');
  }
  for (std::string s : lastRow) {
    if (s == "") continue;
    PRINT_COL(s);
  }
  END_ROW;
  PRINT_BLANK('+', '+');

#undef PRINT_COL
#undef PRINT_BLANK
#undef END_ROW
}

int main(int argc, char** argv) {
  int rows;
  int cols;

  // get rows, columns from command-line arguments in switch case
  switch (argc) {
  case 1:
    rows = cols = 10;
    break;
  case 2:
    rows = cols = atoi(argv[1]);
    break;
  case 3:
    rows = atoi(argv[1]);
    cols = atoi(argv[2]);
    break;
  default:
    std::cerr << "invalid usage: expected 0, 1, or 2 arguments";
    return 1;
  }

  if (rows < 1 || cols < 1) {
    std::cerr << "error: cannot create table with given dimensions ("
      << rows << "x" << cols << ")\n";
    return 2;
  }

  std::cout << "Generating " << rows << "x" << cols
    << " sized multiplication table.\n\n";
  (drawTable(rows, cols));

  return 0;
}
