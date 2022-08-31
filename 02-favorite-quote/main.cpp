/*
  Ernest Izdebski, 2022-08-29

  This program logs three quotes to the console.
*/

#include <iostream>
using namespace std;


int main() {
  // an array of quotes, without endlines
  // this line is a bit long without line-wrapping
  string quotes[] = {
    "On Earth there is no poverty, no crime, no war. You look out the window at Starfleet Headquarters and you see paradise. Well, it's easy to be a saint in paradise. But the Maquis do not live in paradise. Out there, in the Demilitarized Zone, all problems have not been solved yet. There are no saints, just people; angry, scared, determined people who are going to do whatever it takes to survive, whether it meets with Federation approval or not!",
    "You know, there are some words I've known since I was a schoolboy: \"With the first link, the chain is forged. The first speech censured, the first thought forbidden, the first freedom denied, chains us all irrevocably.\" Those words were uttered by Judge Aaron Satie, as wisdom and warning. The first time any man's freedom is trodden on, we're all damaged.",
    "Find him and kill him! - Worf",
  };


  // I tried using quotes.size() but I ran into some errors, including my first segfault
  // maybe I'll learn those later on, I think it probably has to do with pointers or whatever
  
  // as far as I can tell, this method works by dividing the total size of the
  // array by the space it has to allocate for one given member

  // upper bound for iteration to end at
  int total = sizeof(quotes) / sizeof(quotes[0]);


  // iterate through the array, ending at its last index
  for (int i = 0; i < total; i++) {
    // log the current quote number
    cout << "Quote " << i << ":   ";
    // obtain the member of quotes at index i, finish log with an endline
    cout << quotes[i] << endl;
  }
}
