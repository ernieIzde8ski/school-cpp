/*
  Ernest Izdebski, 2022-10-12,14

  Bubble sort example from various lecture notes.
*/

#include <iostream>
#define elif else if
using namespace std;

const string SEPSTRING = std::string(50, '-') + "\n";

// populate an array with random numbers in range [0, rand_upper_bound)
void populate_array(int arr[], int size, int rand_upper_bound = 1000) {
  for (int i = 0; i < size; i++)
    arr[i] = rand() % rand_upper_bound;
}

// Print array to console
void display_array(int(arr)[], int size, bool newline = true) {
  cout << "[ ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << (newline ? "]\n" : "]");
}


// returns the highest ranked value of an array
// segfaults when passed an array of length zero, I would imagine
template <typename T> T highest_array_value(T arr[], int arr_size) {
  T highest = arr[0];
  for (int i = 1; i < arr_size; i++) {
    // "This does what you think it does." - GCC
    highest = max(highest, arr[i]);
  }
  return highest;
}

// same implementation as highest_array_value except with std::min()
// instead of std::max()
template <typename T> T lowest_array_value(T arr[], int arr_size) {
  T lowest = arr[0];
  for (int i = 1; i < arr_size; i++)
    lowest = min(lowest, arr[i]);
  return lowest;
}

// adds up every member of the array
// probably segfaults on array length 0, too
template <typename T> T sum_array(T arr[], int arr_size) {
  int resp = arr[0];
  for (int i = 1; i < arr_size; i++) resp += arr[i];
  return resp;
}


// returns index of value if found in array, else -1
template <typename T> T sequential_search(T value, T arr[], int arr_size) {
  for (int i = 0; i < arr_size; i++) {
    if (arr[i] == value) return i;
  }
  return -1;
}

// Bubble sort, with complexity O(n²)
void bubble_sort(int arr[], int size) {
  for (int i_0 = 0; i_0 < size; i_0++) {
    for (int i_1 = 0; i_1 < size; i_1++) {
      int temp = arr[i_0];
      if (arr[i_1] > temp) {
        arr[i_0] = arr[i_1];
        arr[i_1] = temp;
      }
    }
  }
}

// Recursively binary search for the index of the first instance of
// type T in array of a given size. Returns -1 when not found.
// Assumes the array is already sorted.


template <typename T> T binary_search(T searched_value, T arr[], int start, int stop) {
  T found_value;
  if (start == stop) {
    int found_value = arr[start];
    return (searched_value == found_value) ? start : -1;
  } else {
    int mid = (start + stop) / 2;
    T found_value = arr[mid];
    if (found_value == searched_value) return mid;
    elif(found_value > searched_value) return binary_search<T>(searched_value, arr, start, mid);
    elif(found_value < searched_value) return binary_search<T>(searched_value, arr, mid, stop);
  }

  throw "this shouldn't happen";
}

template <typename T> T binary_search(T value, T arr[], int size) {
  return binary_search<T>(value, arr, 0, size);
}

int main() {
  // define variables
  srand(time(0));
  int arr_size = 50;
  int arr[arr_size];
  int search_index, search_value;
  char cont = 'y';

  while (cont == 'y' || cont == 'Y') {
    cout << SEPSTRING;
    // create, display array
    populate_array(arr, arr_size);
    cout << "Unsorted array: ";
    display_array(arr, arr_size);

    // display highest, lowest
    cout << "Highest value of array: " << highest_array_value(arr, arr_size) << endl;
    cout << "Lowest value of array:  " << lowest_array_value(arr, arr_size) << endl;

    // display total, average
    int total = sum_array(arr, arr_size);
    cout << "Total sum of values:    " << total << endl;
    cout << "Average of all values:  " << (double(total) / arr_size) << endl;

    // sequentially search for a prompted value
    cout << endl << "Sequentially search for which value? ";
    cin >> search_value;
    search_index = sequential_search(search_value, arr, arr_size);
    if (search_index == -1)
      cerr << "error: value '" << search_value << "' not found in array";
    else
      cout << "value found at index: " << search_index;
    cout << "\n\n";


    // bubble sort, O(n²)
    bubble_sort(arr, arr_size);
    cout << "Sorted array:   ";
    display_array(arr, arr_size);

    // binary search for prompted value
    cout << endl << "Binary search for which value? ";
    cin >> search_value;
    search_index = binary_search<int>(search_value, arr, arr_size);
    if (search_index == -1)
      cerr << "error: value '" << search_value << "' not found in array";
    else
      cout << "value found at index: " << search_index;
    cout << endl;
    
    // repeat the loop
    cout << SEPSTRING << endl;
    cout << "Continue? [y/N] ";
    cin >> cont;
    cout << endl;
  }
  cout << "goodbye!" << endl;
}
