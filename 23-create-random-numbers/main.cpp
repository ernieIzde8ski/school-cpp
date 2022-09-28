/*
  Ernest Izdebski, 2022-09-28

  Generates a seeded random number between: 1 and 10, 1 and 100, 1 and 1000.
  Loops five times.
*/

#include <iostream>
using namespace std;

int rand_int(int start, int range) {
  return (rand() % range) + start;
}

int main() {
  srand(time(0));
  int limit = 5;
  int upper_bounds[3] = {10, 100, 1000};
  for (int i_0 = 0; i_0 < limit; i_0++) {
    for (int i_1 = 0; i_1 < 3; i_1++) {
      cout << "Random in range [1, " << upper_bounds[i_1] << "]: "
           << rand_int(1, upper_bounds[i_1]) << endl;
    }
    cout << endl;
  }
}
