/*
    Ernest Izdebski
    2023-03-15

    A subclass of BankAccount to prevent the user from going below a
    budget of 25 dollars.
*/

public class SavingsAccount extends BankAccount {
    // class-specific status-related stuff
    public static  double budgetThreshold = 25.00;
    boolean status;
    private void setStatus() { this.status = this.balance > budgetThreshold; }

    /* constructor to make sure status is set */
    SavingsAccount(double startingBalance, double interestRate) {
        super(startingBalance, interestRate);
        this.setStatus();
    }


    /* methods */
    public void deposit(double total) throws BankingException {
        super.deposit(total);
        this.setStatus();
    }

    public void withdraw(double total) throws BankingException {
        if (!this.status) throw new BankingException
            ("Savings account is currently inactive. Please deposit more funds.");
        super.withdraw(total);
    }

    public void monthlyProcess() {
        if (this.totalWithdrawals > 4)
            this.charge += this.totalWithdrawals - 4;
        super.monthlyProcess();
        this.setStatus();
    }
}
