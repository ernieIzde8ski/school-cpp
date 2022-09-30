/*
  Ernest Izdebski, 2022-09-30

  Helps operate the Fast Freight Shipping Company by aiding the User in
  calculating Shipping Charges.
*/

#include <iostream>
#include <tuple>
using namespace std;

// return given type T from console input
template <typename T> T input(string prompt) {
  T resp;
  cout << prompt;
  cin >> resp;
  return resp;
}

struct ShippingCharge {
  double weight; // maximum weight for this charge
  double rate;   // rate of charge per mile
};

// ordered array of charges
const ShippingCharge SHIPPING_CHARGES[] = {
  {2, 1.10  / 500},
  {6, 2.20  / 500},
  {10, 3.70 / 500},
  {20, 4.80 / 500},
};

// obtain length of above array at compile time
const int CHARGES_LENGTH = sizeof(SHIPPING_CHARGES) / sizeof(SHIPPING_CHARGES[0]);


// constant such that I ensure I don't mistype this
const double SHIPPING_CHARGES_ERROR = -1.0;

// calculate shipping charge
double calcShippingCharges(double weight, double distance) {
  if (weight < 0 || distance < 0) {
    cerr << "Error: weight and distance cannot be less than zero" << endl;
    return SHIPPING_CHARGES_ERROR;
  }
  
  // check if weight is less than or equal to any of the charge rates
  for (int i = 0; i < CHARGES_LENGTH; i++) {
    if (weight <= SHIPPING_CHARGES[i].weight) 
      return distance * SHIPPING_CHARGES[i].rate;
  };
  
  // display error in the case of no matching rates
  cerr << "Error: no suitable charge rate found" << endl;
  return SHIPPING_CHARGES_ERROR;
}

int main() {
  while (true) {
    // define/populate variables
    double weight = input<double>("Input package weight (kg): ");
    double distance = input<double>("Input distance package is to be shipped (mi): ");
    
    // perform calculations, skipping this iteration if necessary
    double shipping_charges = calcShippingCharges(weight, distance);
    cout << endl;
    if (shipping_charges == SHIPPING_CHARGES_ERROR) continue;
    
    cout << "weight:   " << weight << " kilograms" << endl;
    cout << "distance: " << distance << " miles" << endl;
    cout << "charge:   " << shipping_charges << "$" << endl;
    cout << endl << endl;
  }
}
