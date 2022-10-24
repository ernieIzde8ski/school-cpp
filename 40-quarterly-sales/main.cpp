/*
  Ernest Izdebski, 2022-10-24

  A program that lets the user enter four quarterly sales figures for
  six divisions of a company.  The Figures should be stored in a two-
  dimensional array.  Once the figures are entered (using a random
  number generator), the program should display the following data for
  each:

  - a list of the sales figures by division
  - each division's highest sales
  - each division's lowest sales
  - each division yearly sales
  - total of all sales for all divisions.
*/

#include <iostream>
#include "ernie.hpp"

const int QUARTERS = 4;
const int DIVISIONS = 6;

// populates the matrix with random values
void populate_matrix(int matrix[DIVISIONS][QUARTERS], int max_sales = 1000) {
  for (int i = 0; i < DIVISIONS; i++) {
    for (int j = 0; j < QUARTERS; j++) {
      matrix[i][j] = ernie::rand_int(max_sales);
    }
  }
}

void display_matrix(int matrix[DIVISIONS][QUARTERS]) {
  for (int i = 0; i < DIVISIONS; i++) {
    std::cout << "Division #" << i << " quarterly sales:\t[";
    for (int j = 0; j < QUARTERS; j++) {
      std::cout << "\t" << matrix[i][j];
    }
    std::cout << "\t]\n";
  }
}

void display_lowest_sales(int matrix[DIVISIONS][QUARTERS]) {
  std::cout << "Lowest sales per division: \t[";
  for (int i = 0; i < DIVISIONS; i++) {
    std::cout << "\t" << ernie::arrayLowestValue(matrix[i], QUARTERS);
  }
  std::cout << "\t]\n";
}

void display_highest_sales(int matrix[DIVISIONS][QUARTERS]) {
  std::cout << "Highest sales per division: \t[";
  for (int i = 0; i < DIVISIONS; i++) {
    std::cout << "\t" << ernie::arrayHighestValue(matrix[i], QUARTERS);
  }
  std::cout << "\t]\n";
}


void display_total_sales(int matrix[DIVISIONS][QUARTERS]) {
  std::cout << "Total sales per division: \t[";
  for (int i = 0; i < DIVISIONS; i++) {
    std::cout << "\t" << ernie::arraySum(matrix[i], QUARTERS);
  }
  std::cout << "\t]\n";
}


void display_all_sales(int matrix[DIVISIONS][QUARTERS]) {
  int arr[DIVISIONS];
  for (int i = 0; i < DIVISIONS; i++) {
    arr[i] = ernie::arraySum(matrix[i], QUARTERS);
  }
  std::cout << "Total sales overall for all:\t" << ernie::arraySum(arr, DIVISIONS) << std::endl << std::endl;
}


int main() {
  srand(time(0));
  // define
  int matrix[DIVISIONS][QUARTERS];

  // populate
  populate_matrix(matrix);

  // display
  display_matrix(matrix);
  std::cout << std::endl;
  display_lowest_sales(matrix);
  display_highest_sales(matrix);
  display_total_sales(matrix);
  display_all_sales(matrix);
}
