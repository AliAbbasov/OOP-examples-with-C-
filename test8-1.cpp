#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

double trackStockPrice(string symbol, double currentPrice) {
    static unordered_map<string, double> highestPrices;

    if (highestPrices.find(symbol) == highestPrices.end()) {
        highestPrices[symbol] = currentPrice;
    } else {
        if (currentPrice > highestPrices[symbol]) {
            highestPrices[symbol] = currentPrice;
        }
    }
    return highestPrices[symbol];
};

/*
    Exercise-2: Bank Account Management

    Create a C++ program that models a simplified bank account management system. 
    In this system, you will create a BankAccount class with the following features:

    1. Each BankAccount object should have a unique account number that starts from 1001 and increments by 1 for each new account created.
    2. Each account should have an account balance.
    3. Implement methods to deposit and withdraw funds from the account.
    4. Implement a method to display the account details, including the account number and balance.
*/


class BankAccount {
private:
    int accountNumber;
    double balance;
    static int totalAccounts;

public:
    BankAccount() {
        this->accountNumber = totalAccounts + 1001;
        this->balance = 0;
        totalAccounts++;
    }

    void deposit(double amount) {
        if (amount > 0) {
            this->balance += amount;
            cout << "Deposited " << amount << " to account " << this->accountNumber << endl;
        } else {
            cout << "Invalid amount" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && this->balance >= amount) {
            this->balance -= amount;
            cout << "Withdrew " << amount << " from account " << this->accountNumber << endl;
        } else {
            cout << "Invalid amount" << endl;
        }
    }

    void displayAccountDetails() {
        cout << "Account Number: " << this->accountNumber << endl;
        cout << "Balance: " << this->balance << endl;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }
};

int BankAccount::totalAccounts = 0;
/*
    Exercise-3: One instance Class

    Create a C++ program that implements a  class, 
    which ensures that only one instance(object) of the class can be created. 
*/
class OnlyOneInstance {
private:
    static OnlyOneInstance *instance;
    OnlyOneInstance() {}

public:
    OnlyOneInstance(const OnlyOneInstance &obj) = delete;

    static OnlyOneInstance *getInstance() {
        if (instance == nullptr) {
            instance = new OnlyOneInstance();
        }
        return instance;
    }

    ~OnlyOneInstance() {
        delete instance;
        instance = nullptr;
    }
};

OnlyOneInstance *OnlyOneInstance::instance = nullptr;



int main() {

    cout << "1. Task" << endl;
    //  Exercise-1: example usage
    double price1 = trackStockPrice("AAPL", 150.25);
    cout << "Highest AAPL Stock Price: $" << price1 << endl;

    double price2 = trackStockPrice("GOOGL", 2700.50);
    cout << "Highest GOOGL Stock Price: $" << price2 << endl;

    double price3 = trackStockPrice("AAPL", 155.75);
    cout << "Highest AAPL Stock Price: $" << price3 << endl;

    double price4 = trackStockPrice("TSLA", 800.00);
    cout << "Highest TSLA Stock Price: $" << price4 << endl;

    cout << endl;
    cout << endl;
    cout << "2. Task" << endl;
    //  Exercise-2: example usage
    BankAccount account1;
    account1.deposit(1000);
    account1.withdraw(500);
    account1.displayAccountDetails();

    BankAccount account2;
    account2.deposit(1500);
    account2.displayAccountDetails();

    // Display the total number of accounts created.
    cout << "Total Accounts Created: " << BankAccount::getTotalAccounts() << endl;

    cout << endl;
    cout << endl;
    cout << "3. Task" << endl;

    OnlyOneInstance *obj1 = OnlyOneInstance::getInstance();
    OnlyOneInstance *obj2 = OnlyOneInstance::getInstance();

    cout << "Address of obj1: " << obj1 << endl;
    cout << "Address of obj2: " << obj2 << endl;


    delete obj1;
    delete obj2;

    return 0;

}