/*
  Ernest Izdebski, 2022-11-11

  Reads a file "myNumbers.txt" containing 50 numbers and runs various
  functions on it.
*/

#include <iostream>
#include <fstream>
#include "ernie.hpp"


// recursive search function
// returns -1 if searchTerm is not found in the array
template <typename T>
T recursiveBinarySearch(T arr[], T searchTerm, int start, int end) {
  // if start becomes larger than end, then the error case
  // has occurred and there is no solution

  // this is a little neater than start > end because I can
  // expect no compiler errors from unhandled cases
  if (start <= end) {
    int mid = (start + end) / 2;
    T foundItem = arr[mid];

    if (foundItem == searchTerm) return mid;
    elif(foundItem > searchTerm) return recursiveBinarySearch(arr, searchTerm, start, --mid);
    elif(foundItem < searchTerm) return recursiveBinarySearch(arr, searchTerm, ++mid, end);
  }
  return -1;
}

// overload for not manually inputting zero
template <typename T>
T recursiveBinarySearch(T arr[], T searchTerm, int size) {
  return recursiveBinarySearch(arr, searchTerm, 0, size);
}

// generic bubbleSort implementation
template <typename T> void bubbleSort(T array[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (array[i] < array[j]) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

// populate array from filepath
void populateArray(int arr[], int size, std::string fp) {
  // open
  std::ifstream file(fp);
  // read lines into array
  int line;
  for (int i = 0; file >> line && i < size; i++) {
    if (line < 0) throw "error: line #" + std::to_string(i) + " less than zero";
    if (line > 2000) throw "error: line #" + std::to_string(i) + " greater than 2000";
    arr[i] = line;
  }
  // close
  file.close();
}

int main() {
  // define variables
  int arrSize = 50;
  int arr[arrSize];
  int highestValue, lowestValue, valueSum;
  double valueAverage;

  // process
  populateArray(arr, arrSize, "myNumbers.txt");
  bubbleSort(arr, arrSize);

  highestValue = ernie::arrayHighestValue(arr, arrSize);
  lowestValue = ernie::arrayLowestValue(arr, arrSize);
  valueSum = ernie::arraySum(arr, arrSize);
  valueAverage = double(valueSum) / arrSize;

  // display
  ernie::displayArray(arr, arrSize, "Numbers from 'myNumbers.txt':\t");
  std::cout << std::endl
    << "Highest value:\t" << highestValue << std::endl
    << "Lowest value:\t" << lowestValue << std::endl
    << "Sum of all values:\t" << valueSum << std::endl
    << "Average value:\t" << valueAverage << std::endl
    << std::endl;

  // enter search loop
  while (true) {
    int searchValue = ernie::input<int>("Search for which value? ");
    if (searchValue == -1) break;
    auto found = (recursiveBinarySearch(arr, searchValue, arrSize) != -1);
    if (found) std::cout << searchValue << " is in the array !" << std::endl;
    else std::cout << searchValue << " is not in the array :(" << std::endl;
    std::cout << std::endl;
  }
  std::cout << std::endl << "goodbye!" << std::endl;
}
