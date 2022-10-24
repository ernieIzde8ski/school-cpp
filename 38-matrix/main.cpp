/*
  Ernest Izdebski, 2022-10-21

  Create a two-dimensional array, find various information on each row,
  and use a do-while loop to allow the user to run the program
  continuously.
*/

#include <iostream>
#include "conio.h"
#include "ernie.hpp"

// define constants for all matrix sizes in this program
// seemingly the easiest way to avoid issues without resorting to vectors

const int MATRIX_ROWS = 5;
const int MATRIX_COLS = 15;

void populate_matrix(int matrix[MATRIX_ROWS][MATRIX_COLS], int num_max = 50) {
  for (int i = 0; i < MATRIX_ROWS; i++) {
    for (int j = 0; j < MATRIX_COLS; j++) {
      matrix[i][j] = ernie::rand_int(num_max);
    }
  }
}

void display_matrix(int matrix[MATRIX_ROWS][MATRIX_COLS]) {
  std::cout << "Matrix: \n";
  for (int i = 0; i < MATRIX_ROWS; i++) {
    for (int j = 0; j < MATRIX_COLS; j++) {
      std::cout << "\t" << matrix[i][j];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}


struct RowValues {
  int lowest;
  int highest;
  int total;
  double average;

  RowValues() {};

  RowValues(int row[], int size) {
    lowest = row[0];
    highest = row[0];
    total = row[0];

    for (int i = 1; i < size; i++) {
      int val = row[i];
      if (val < lowest) lowest = val;
      elif(val > highest) highest = val;
      total += val;
    }

    average = double(total) / size;
  };

  static void display(RowValues arr[], int size) {
    for (int i = 0; i < size; i++) {
      RowValues row = arr[i];
      std::cout << "Row #" << i << ":\n";
      std::cout << "\tLowest value:  " << row.lowest << "\n";
      std::cout << "\tHighest value: " << row.highest << "\n";
      std::cout << "\tAverage value: " << row.average << "\n";
      std::cout << "\tTotal value:   " << row.total << "\n";
    }
    std::cout << std::endl;
  }
};

int main() {

  // define vars
  int matrix[MATRIX_ROWS][MATRIX_COLS];
  RowValues matrix_row_values[MATRIX_ROWS];
  char cont = '\n';

  srand(time(0));

  do {
    // the requirements as worded by the assignment are rather
    // vague, so I've taken some creative liberties

    // populate values
    populate_matrix(matrix);
    for (int i = 0; i < MATRIX_ROWS; i++) {
      // instantiate RowValues instances
      matrix_row_values[i] = { matrix[i], MATRIX_COLS };
    }

    // display values
    display_matrix(matrix);
    RowValues::display(matrix_row_values, MATRIX_ROWS);

    // handle continue/exit
    std::cout << "Continue? [Y/n]\t";
    cont = conio::getche();
    if (cont != '\n') std::cout << "\n";
  } while (cont == '\n' || cont == 'y' || cont == 'Y');

  std::cout << "\nGoodbye!" << std::endl;
}
