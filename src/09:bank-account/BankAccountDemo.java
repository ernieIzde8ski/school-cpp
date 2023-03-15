/*
    Ernest Izdebski         15.03.2023


    A demo of the SavingsAccount class.
    There were no instructions on the assignment, so I ran through
    all implemented methods on the subclass of BankAccount.
*/


public class BankAccountDemo {
    public static void main(String[] args) throws BankingException {
        /* constants */
        double startingBalance = 100.0;
        double interestRate = 0.025;

        double deposit = 50.0;
        double withdrawal = 125.0;
        /* demo code */
        System.out.println("initializing account with balance " + startingBalance +
                           " and interest rate " + (interestRate * 100) + "%");
        SavingsAccount account = new SavingsAccount(startingBalance, interestRate);
        System.out.print(account.toString() + "\n\n");
        
        System.out.println("Depositing " + deposit + "$.");
        account.deposit(deposit);
        System.out.print(account.toString() + "\n\n");
        
        System.out.println("Withdrawing " + withdrawal + "$.");
        account.withdraw(withdrawal);
        System.out.print(account.toString() + "\n\n");
        
        System.out.println("Concluding the monthly process.");
        account.monthlyProcess();
        System.out.print(account.toString() + "\n\n");
    }
}