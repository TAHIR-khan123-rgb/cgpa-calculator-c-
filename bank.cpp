#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    string detail;
    time_t timestamp;

    Transaction(string t, double a, string d = "") {
        type = t;
        amount = a;
        detail = d;
        timestamp = time(nullptr);
    }

    void display() const {
        cout << put_time(localtime(&timestamp), "%Y-%m-%d %H:%M:%S");
        cout << " | " << type << " | ₹" << amount << " | " << detail << endl;
    }
};

class Account {
    string accNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(string accNo) : accNumber(accNo), balance(0) {}

    void deposit(double amount) {
        balance += amount;
        transactions.emplace_back("Deposit", amount);
    }

    void withdraw(double amount) {
        if (amount > balance) throw runtime_error("Insufficient balance");
        balance -= amount;
        transactions.emplace_back("Withdrawal", amount);
    }

    void transfer(Account &target, double amount) {
        withdraw(amount);
        target.deposit(amount);
        transactions.emplace_back("Transfer", amount, "to " + target.getAccNumber());
        target.transactions.emplace_back("Transfer", amount, "from " + accNumber);
    }

    void showTransactions(int limit = 5) const {
        int start = max(0, int(transactions.size()) - limit);
        for (int i = start; i < transactions.size(); ++i)
            transactions[i].display();
    }

    void showInfo() const {
        cout << "Account: " << accNumber << "\nBalance: ₹" << balance << "\nRecent Transactions:\n";
        showTransactions();
        cout << endl;
    }

    string getAccNumber() const { return accNumber; }
};

class Customer {
    string name, customerId;
    vector<Account> accounts;

public:
    Customer(string n, string id) : name(n), customerId(id) {}

    void createAccount(string accNumber) {
        accounts.emplace_back(accNumber);
    }

    Account* getAccount(string accNumber) {
        for (auto &acc : accounts)
            if (acc.getAccNumber() == accNumber)
                return &acc;
        throw runtime_error("Account not found.");
    }

    void displayAccounts() const {
        cout << "\nCustomer: " << name << " (ID: " << customerId << ")\n";
        for (const auto &acc : accounts)
            acc.showInfo();
    }
};