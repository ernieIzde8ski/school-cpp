/*
  Ernest Izdebski, 2022-11-09

  Search through an array of length 25 by recursive binary search
  function.
*/

#include <iostream>
#define print(msg) std::cout << msg << std::endl;
#define elif else if

// recursive search function
// returns -1 if searchTerm is not found in the array
template <typename T>
T recursiveBinarySearch(T arr[], T searchTerm, int start, int end) {
  // if indexEnd becomes larger than indexEnd, then the error case
  // has occurred and there is no solution

  // this is a little neater than indexStart > indexEnd because I can
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

void populateArray(int array[], int size, int bound = 256) {
  srand(time(0));
  for (int i = 0; i < size; i++) { array[i] = rand() % bound; }
}

template <typename T>
void bubbleSort(T array[], int size) {
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
void displayArray(int array[], int size) {
  std::cout << "Array:\t[ ";
  for (int i = 0; i < size; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << "]" << std::endl;
}


int main() {
  const int arrSize = 25;
  int arr[arrSize];

  populateArray(arr, arrSize);
  bubbleSort(arr, arrSize);
  displayArray(arr, arrSize);

  while (true) {
    int searchTerm, location, lastDigit;
    std::cout << "search for which number? ";
    std::cin >> searchTerm;

    if (searchTerm == -1) break;

    location = recursiveBinarySearch(arr, searchTerm, arrSize);

    if (location == -1) {
      print("sorry, number not found :(");
      continue;
    }

    location++;
    lastDigit = location % 10;

    std::cout << "Number is found at the " << location <<
      (
        // perhaps I should have written a switch case
        (lastDigit == 1) ? "st"
        : (lastDigit == 2) ? "nd"
        : (lastDigit == 3) ? "rd"
        : "th"
        )
      << " column in the array."
      << std::endl;
  }
  print("goodbye!");
  std::cout << "Goodbye!" << std::endl;
}
