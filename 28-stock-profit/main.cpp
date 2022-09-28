/*
  Ernest Izdebski, 2022-09-28

  A program that accepts as arguments the number of shares, the purchase price per share,
  the purchase commission paid, the sale price per share, and the sale commission paid.
  The function should return the profit (or loss) from the sale of stock.
*/

#include <iostream>
using namespace std;

// struct for all data so I don't have to type out arguments more than twice
struct Shares {
  int total;
  double sale_price_per_share;
  double sale_commission_paid;
  double purchase_price_per_share;
  double purchase_commission_paid;

  double profit() {
    // complicated formula provided in the assignment
    // as 'Profit = ((NS * SP) – SC) – ((NS * PP) + PC)'
    return ((total * sale_price_per_share) - sale_commission_paid)
      - ((total * purchase_price_per_share) + purchase_commission_paid);
  }
  
  void display_profit() {
    cout << "Total profits/losses: " << profit() << "$" << endl;
  }
};

int main() {
  // create variable-holding struct
  Shares shares = {};
  
  // populate struct
  cout << "Total shares: ";
  cin >> shares.total;
  cout << "Sale price per share: ";
  cin >> shares.sale_price_per_share;
  cout << "Sale commission paid: ";
  cin >> shares.sale_commission_paid;
  cout << "Purchase price per share: ";
  cin >> shares.purchase_price_per_share;
  cout << "Purchase commission paid: ";
  cin >> shares.purchase_commission_paid;

  // use struct method (a function bound to a class/struct, same difference)
  shares.display_profit();
}
