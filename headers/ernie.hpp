/*
    ernie.hpp, a good header file

    collection of functions I use to be lazy
*/

#pragma once
#include <iostream>

namespace ernie {
// simple input function
template <typename T> T input(std::string s = "") {
  T resp;
  std::cout << s;
  std::cin >> resp;
  return resp;
}

// Array Methods
// ALL of these are likely to segfault if an array with size 0 is
// passed into any of them

// simple array summation
template <typename T> T arraySum(T arr[], int size) {
  // just in case the given operator T does not support typecasts from 0
  T resp = arr[0];
  for (int i = 1; i < size; i++) resp += arr[i];
  return resp;
}

// get value ranked lowest in array
template <typename T> T arrayLowestValue(T arr[], int size) {
  T resp = arr[0];
  for (int i = 1; i < size; i++) resp = std::min(resp, arr[i]);
  return resp;
}

// get index of value ranked lowest in array
template <typename T> int arrayLowestValueIndex(T arr[], int size) {
  int index = 0;
  T lowest_value = arr[0];
  for (int i = 1; i < size; i++) {
    T next = arr[i];
    if (next < lowest_value) {
      index = i;
      lowest_value = next;
    }
  };
  return index;
}

// get value ranked highest in array
template <typename T> T arrayHighestValue(T arr[], int size) {
  T resp = arr[0];
  for (int i = 1; i < size; i++) resp = std::max(resp, arr[i]);
  return resp;
}

// get index of value ranked highest in array
template <typename T> int arrayHighestValueIndex(T arr[], int size) {
  int index = 0;
  T highest_value = arr[0];
  for (int i = 1; i < size; i++) {
    T next = arr[i];
    if (next > highest_value) {
      index = i;
      highest_value = next;
    }
  };
  return index;
}

// random number generator in range [0, stop)
int rand_int(int stop) {
  return rand() % stop;
}

// random number generator in range [start, stop)
int rand_int(int start, int stop) {
  return rand_int(stop-start) + start;
}

} // end namespace ernie
