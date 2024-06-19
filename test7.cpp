#include <iostream>
#include <string>

using namespace std;


class Account {
    private:
        int accountNumber;
        double balance;
    public:
        Account(const int accountNumber,const double balance) : accountNumber(accountNumber), balance(balance) {}

        ~Account() {}

        virtual void deposit (double amount) {
            balance += amount;
        }

        virtual void withdraw (double amount) {
            if (amount <= balance) {
                balance -= amount;
            } else {
                cout << "Insufficient Funds" << endl;
            }

        }
        virtual void displayBalance () const {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance;           
        }       
};


class SavingsAccount : public Account {
    private:
        double interestRate;
    public:
        SavingsAccount (const int accountNumber, const double balance , const double interestRate) : Account (accountNumber, balance), interestRate(interestRate) {}

        void displayBalance () const override {
            Account::displayBalance();
            cout << ", Interest Rate: "<< interestRate << "%" << endl;
        } 
};


class CheckingAccount : public Account {
    public:
        CheckingAccount (const int accountNumber, const double balance) : Account (accountNumber, balance) {}

        void displayBalance () const override {
            Account::displayBalance();
            cout << ", Checking Account" << endl;
        }      
};

int main() {

    Account* savings = new SavingsAccount(1001, 1000.0, 3.0); 
    Account* checking = new CheckingAccount(2001, 2000.0);

    savings->deposit(500.0);
    checking->withdraw(1000.0);

    savings->displayBalance();
    checking->displayBalance();

    delete savings;
    delete checking;

    return 0;
}