/*
  Ernest Izdebski, 2022-09-14

  A program that determines if an applicant is eligible for a car loan.
*/
#include <csignal>
#include <iostream>
using namespace std;


// prompt for yes/no
bool confirm(string prompt) {
  cout << prompt << " [y/n] ";
  string resp;
  cin >> resp;

  // reportedly in c++ 20 there is a .starts_with method, but this doesn't exist
  // on my compiler (gcc version 10.2.1 20201203)
  if ((resp.rfind("y", 0) == 0) || (resp.rfind("Y", 0) == 0)) return true;
  else if ((resp.rfind("n", 0) == 0) || (resp.rfind("N", 0) == 0)) return false;

  // expected conditions already met, trying again
  cout << "input error: input must be 'y' or 'n'" << endl;
  return confirm(prompt);
}


int main() {
  // add interrupt signal handler via anonymous function
  signal(SIGINT, [](int sig_num) -> void {
    cout << endl << "Goodbye!" << endl;
    exit(sig_num);
  });
  
  cout << "welcome to some Official bank program™, we discuss Car Loans" << endl
    << "Send interrupt signal to close program (ctrl+c on linux)"
    << endl << endl << endl;

  for (int i = 1;; i++) {
    cout << "Handling car loan applicant no. " << i << endl;
    // define, populate variables
    bool is_recent_graduate = confirm("Is applicant a recent graduate? ");
    bool is_employed = confirm("Is applicant currently employed?");

    // display eligibility status
    if (!is_recent_graduate) {
      cout << "Ineligible applicant: must be recent graduate" << endl << endl;
    } else if (!is_employed) {
      cout << "Ineligible applicant: must be employed" << endl << endl;
    } else {
      cout << "Applicant #" << i << " is eligible!" << endl << endl;
    };
  }
}
