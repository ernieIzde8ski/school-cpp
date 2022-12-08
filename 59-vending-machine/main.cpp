/*
  Ernest Izdebski, 2022-11-30

  A soft-drink machine simulator.
*/

#include <iostream>
#include "ansi.hpp"
#include "ernie.hpp"

#define elif else if

void error(std::string message) {
  std::cerr << ANSI::FG_RED << "error: " << message << ANSI::NORMAL << std::endl;
}

struct MachineItem {
  std::string name;
  double cost = .75;
  const int starting = 20;
  int remaining = 20;
};


// display options for sodas to buy & quitting the program
void displayMachineActions(MachineItem machine[], int machineSize) {
  std::cout << ANSI::BG_BLUE; // make it all blue
  std::cout << "[-1] [Leave the Vending Machine Behind]";
  for (int i = 0; i < machineSize; i++) {
    auto item = machine[i];
    std::cout << "\n[" << i << "]  (" << item.remaining << ")\t" << item.name;
  }
  std::cout << ANSI::NORMAL << std::endl; // end bluedom
}

// get a machine action
int promptMachineAction(MachineItem machine[], int machineSize) {
  int action;
  while (true) {
    action = ernie::input<int>("Which? ");
    if (action == -1) return action; // short-circuit on exit
    if (action >= 0 && action < machineSize) { // check if is a valid soda
      // check if there are sodas of this kind remaining
      if (machine[action].remaining != 0) return action;
      error("this soda is sold out");
    } else error( // if not a valid soda
      "please input a number in the range [1, " + std::to_string(machineSize) + ")"
    );
  }
}


double promptMoney(double minimum, double maximum = 10.00) {
  double resp;
  START: {
  resp = ernie::input<double>("please input Money (usd): ");
  if (resp < minimum) {
    auto msg = "error: not enough money: " + std::to_string(resp) + "$ (cost: ";
    std::cerr << "error: not enough money: " << resp << "$ (cost: " << minimum << "$)\n";
  } elif(resp > maximum) {
    std::cerr << "error: money over limit: " << resp << "$ (limit: " << maximum << "$)\n";
  } else return resp;
  goto START; // Ernie Considered Harmful
  }
}

int main() {
  // intro message
  std::cout << ANSI::BOLD << ANSI::FG_GREEN << "welcome to the Soda Machine !" << ANSI::NORMAL <<"\n\n";

  // code start
  int totalSodas = 5;
  MachineItem sodaMachine[totalSodas] = {
    {"Cola"}, {"Root Beer"}, {"Lemon-Lime"}, {"Grape"}, {"Cream Soda"}
  };


  // event loop
  while (true) {
    displayMachineActions(sodaMachine, totalSodas);  // display action
    std::cout << std::endl;
    int keyPress = promptMachineAction(sodaMachine, totalSodas);  // get action
    if (keyPress == -1) break;  // exit loop on action -1
    MachineItem soda = sodaMachine[keyPress];  // get requested soda
    double money = promptMoney(sodaMachine[keyPress].cost, 10.0);  // ask for money
    if (money != sodaMachine[keyPress].cost) std::cout << "change: "
      << (money - sodaMachine[keyPress].cost) << "$\n";  // display change
    sodaMachine[keyPress].remaining--; // decrement remaining total
    std::cout << std::endl;
  }


}
