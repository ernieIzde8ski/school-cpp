/*
    Ernest Izdebski
    2023-03-14

    An abstract class to hold the following data for a bank account:
        - Balance
        - Number of deposits this month
        - Number of withdrawals
        - Annual interest rate
        - Monthly service charges
*/

public class BankAccount {
    /* attributes */
    double balance;                 // self-explanatory
    double rate;                    // annual interest rate
    double charge;                  // monthly service charge
    int totalDeposits;              // number of times deposit() called
    int totalWithdrawals;           // number of times withdraw() called

    /* constructor */
    BankAccount (double startingBalance, double interestRate) {
        this.balance = startingBalance;
        this.rate = interestRate;
        this.charge = 0.0;
    }
    // empty constructor
    BankAccount() { this(0.0, 0.0); }

    // the assignment does not say any getters/setters, so I assume
    // we don't implement them

    /* methods */
    public void deposit(double total) throws BankingException {
        if (total < 0.0) throw new BankingException("Cannot deposit negative sums!");
        ++this.totalDeposits;
        this.balance += total;
    }

    public void withdraw(double total) throws BankingException {
        if (total < 0.0) throw new BankingException("Cannot withdraw negative sums!");
        if (total > this.balance)
            throw new BankingException("Cannot withdraw more than the current balance!");
        ++this.totalWithdrawals;
        this.balance -= total;
    }

    // method is called by monthlyProcess, so private
    private void calcInterest() {
        // rate is annual, so we divide by twelve for monthly
        this.balance += this.balance * (this.rate / 12.0);
    }

    public void monthlyProcess() {
        this.balance -= this.charge;
        this.calcInterest();
        this.totalDeposits = 0;
        this.totalWithdrawals = 0;
        this.charge = 0.0; // note: this variable is useless in the base class
    }

    // for debugging
    public String toString() {
        return this.getClass().getSimpleName() + "(balance=" + this.balance
               + "$,rate=" + (this.rate*100) + "%,charge=" + this.charge
               + ",totalDeposits=" + this.totalDeposits
               + ",totalWithdrawals=" + this.totalWithdrawals + ")";
    }
}
