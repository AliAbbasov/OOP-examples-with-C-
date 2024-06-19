#include <iostream>
#include <vector>

/*
    Exercise-4: Prime Number Caching

    Objective:
    Write a C++ program that efficiently generates and caches prime numbers up to 100 and allows you to query the cached prime numbers.

    Requirements:
    1. Implement a function that generates prime numbers up to 100(e.g., generatePrimes(int limit)).
    2. Cache the generated prime numbers for quick retrieval.
    4. Create a menu-driven user interface to interact with the caching system.
    5. Generate and cache prime numbers up to a specified limit.
    6. Check if a number is prime using the cached data.
*/

class PrimeNumberCache {
private:
    std::vector<int> primes;

public:
    
    void generateAndCachePrimes(int limit) {
        primes.clear(); 

        for (int num = 2; num <= limit; ++num) {
            bool is_prime = true;
            for (int i = 2; i * i <= num; ++i) {
                if (num % i == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime) {
                primes.push_back(num);
            }
        }
    }

  
    bool isPrime(int num) {
        for (int prime : primes) {
            if (num == prime) {
                return true;
            }
            if (num % prime == 0) {
                return false;
            }
        }
        return false;
    }

    void displayCachedPrimes() {
        std::cout << "Cached prime numbers:" << std::endl;
        for (int prime : primes) {
            std::cout << prime << " ";
        }
        std::cout << std::endl;
    }
};



int main() {
    PrimeNumberCache prime_cache;

    int choice;
    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Generate and Cache Prime Numbers up to 100" << std::endl;
        std::cout << "2. Generate and Cache Prime Numbers up to a specified limit" << std::endl;
        std::cout << "3. Check if a Number is Prime (Using Cached Data)" << std::endl;
        std::cout << "4. Display Cached Primes" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                prime_cache.generateAndCachePrimes(100);
                std::cout << "Prime numbers up to 100 cached." << std::endl;
                break;
            }
            case 2: {
                int limit;
                std::cout << "Enter the limit for prime numbers: ";
                std::cin >> limit;
                prime_cache.generateAndCachePrimes(limit);
                std::cout << "Prime numbers up to " << limit << " cached." << std::endl;
                break;
            }
            case 3: {
                int number;
                std::cout << "Enter a number to check if it's prime: ";
                std::cin >> number;
                if (prime_cache.isPrime(number)) {
                    std::cout << number << " is a prime number." << std::endl;
                } else {
                    std::cout << number << " is not a prime number." << std::endl;
                }
                break;
            }
            case 4: {
                prime_cache.displayCachedPrimes();
                break;
            }
            case 5: {
                std::cout << "Exiting..." << std::endl;
                return 0;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    }
    return 0;
}


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


    BankAccount account1;
    account1.deposit(1000);
    account1.withdraw(500);
    account1.displayAccountDetails();

    BankAccount account2;
    account2.deposit(1500);
    account2.displayAccountDetails();

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