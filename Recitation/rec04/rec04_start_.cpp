/*
  rec04_start.cpp
 */

// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Task 1
// Define an Account struct
struct Account {
    string s_name;
    int s_number;
};

// Task 2
// Define an Account class
class Accounts {
    friend ostream& operator<<(ostream& os, const Accounts& acc);

public:
    Accounts(const string& name, int number): c_name(name), c_number(number) {};
    const string& get_name() const {return c_name;}
    int get_num() const { return c_number; }

private:
    string c_name;
    int c_number;
};
ostream& operator<<(ostream& os, const Accounts& acc);

// Task 3
// Define an Account and Transaction classes
class Transaction {
    friend ostream& operator<<(ostream& os, const Transaction& trans);

public:
    Transaction(const string& c_type, int c_amount) : type(c_type), amount(c_amount){};

private:
    string type;
    int amount;
};

class Accounts3 {
public:
    friend ostream& operator<<(ostream& os, const Accounts3& acc3);

    Accounts3(const string& name, int num) : acc3_name(name), acc3_num(num) {};

    int get_num () const { return acc3_num;}

    void deposit(int d_amount) {
        balance += d_amount;
        trans.emplace_back("Deposit", d_amount);
    }

    void withdraw(int w_amount) {
        if (balance > w_amount) {
            balance -= w_amount;
            trans.emplace_back("Withdraw", w_amount);
        } else {
          cout << "Account# " << acc3_num << " has only " << balance << '.';
          cout << " Insufficient for withdrawal of " << w_amount << '.' << endl;
        }
    }

private:
    string acc3_name;
    int acc3_num;
    int balance = 0;
    vector<Transaction> trans;
};

size_t findAcc(int acc_num, vector<Accounts3>& v_acc3);


// Task 4
// Define an Account with a nested public Transaction class
class Accounts4 {
public:
    friend ostream& operator<<(ostream& os, const Accounts4& acc);


    Accounts4(const string& name, int num) : acc4_name(name), acc4_num(num) {};

    int get_num () const { return acc4_num;}

    void deposit(int d_amount) {
        balance4 += d_amount;
        trans.emplace_back("Deposit", d_amount);
    }
    void withdraw(int w_amount) {
        if (balance4 > w_amount) {
            balance4 -= w_amount;
            trans.emplace_back("Withdraw", w_amount);
        } else {
            cout << "Account# " << acc4_num << " has only " << balance4 << '.';
            cout << " Insufficient for withdrawal of " << w_amount << '.' << endl;
        }
    }
        class Transaction {
            friend ostream& operator<<(ostream& os, const Transaction& trans);
        public:
            Transaction(const string& c_type, int c_amount) : type(c_type), amount(c_amount){};

        private:
            string type;
            int amount;
        };

private:
    string acc4_name;
    int acc4_num;
    int balance4 = 0;
    vector<Transaction> trans;
};




// Task 5
// Define an Account with a nested private Transaction class

int main() {

    // Task 1: account as struct
    //      1a
    cout << "Task1a:\n";
    cout << "Filling vector of struct objects, define a local struct instance\n";
    cout << "and set fields explicitly: " << endl;
    ifstream ifs("accounts.txt");
    if(!ifs) {cerr << "Failed to open file."; exit(1);}

    vector<Account> v_acc1;
    Account acc_1;
    string name1;
    int number1;
    while (ifs >> name1 >> number1) {
        acc_1.s_name = name1;
        acc_1.s_number = number1;
        v_acc1.push_back(acc_1);
    }
    ifs.close();
    for (size_t i = 0; i < v_acc1.size(); i++) {
        cout << v_acc1[i].s_name << " \t" << v_acc1[i].s_number << endl;
    }

    //      1b
    cout << "Task1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n";
    v_acc1.clear();
    ifs.open("accounts.txt");
    string b_name;
    int b_num;
    while (ifs >> b_name >> b_num) {
        Account acc2{b_name, b_num};
        v_acc1.push_back(acc2);
    }
    for (size_t i = 0; i < v_acc1.size(); i++) {
        cout << v_acc1[i].s_name << " \t" << v_acc1[i].s_number << endl;
    }
    ifs.close();




    //==================================
    // Task 2: account as class
    //      2a
    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";
    ifs.open("accounts.txt");
    vector<Accounts> v_acc2a;
    string name2a;
    int num2a;
    while (ifs >> name2a >> num2a) {
        Accounts acc2a(name2a, num2a);
        v_acc2a.push_back(acc2a);
    }
    for (size_t i = 0; i < v_acc2a.size(); i++) {
        cout << v_acc2a.at(i).get_name() << " \t" << v_acc2a.at(i).get_num() << endl;
    }
    ifs.close();

    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";
    for (const Accounts& acc_temp: v_acc2a) {
        cout << acc_temp;
    }

    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";
    for (const Accounts& acc_temp: v_acc2a) {
        cout << acc_temp;
    }
    ifs.close();

    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";
    string name2d;
    int num2d;
    vector<Accounts> v_acc2d;
    ifs.open("accounts.txt");
    while (ifs >> name2d >> num2d) {
        v_acc2d.push_back(Accounts(name2d, num2d));
    }
    for (const Accounts& acc_temp: v_acc2d) {
        cout << acc_temp;
    }
    ifs.close();

    cout << "\nTask2e:\n";
    cout << "Filling vector of class objects, using emplace_back:\n";
    ifs.open("accounts.txt");
    string name2e;
    int num2e;
    vector<Accounts> v_acc2e;
    while (ifs >> name2e >> num2e) {
        v_acc2e.emplace_back(name2e, num2e);
    }
    for (const Accounts& acc_temp: v_acc2e) {
        cout << acc_temp;
    }
    ifs.close();




    cout << "==============\n";
    cout << "\nTask 3:\nAccounts and Transaction:\n";
    ifs.open("transactions.txt");
    if(!ifs) {cerr << "Failed to open file."; exit(1);}
    string command;
    string acc_name;
    int acc_num, amount;
    //vector<Transaction> v_trans;
    vector<Accounts3> v_acc3;
    while (ifs >> command) {
        if (command == "Account") {
            ifs >> acc_name >> acc_num;
            v_acc3.emplace_back(acc_name, acc_num);
        }
        else if (command == "Deposit") {
            ifs >> acc_num >> amount;
            size_t accInd = findAcc(acc_num, v_acc3);
            v_acc3[accInd].deposit(amount);
        }
        else if (command == "Withdraw") {
            ifs >> acc_num >> amount;
            size_t accInd = findAcc(acc_num, v_acc3);
            v_acc3[accInd].withdraw(amount);
        }
    }
    ifs.close();
    for (const Accounts3& temp: v_acc3) {
        cout << temp;
    }

    cout << "==============\n";
    cout << "\nTask 4:\nTransaction nested in public section of Account:\n";
    ifs.open("transactions.txt");
    if(!ifs) {cerr << "Failed to open file."; exit(1);}
    //vector<Transaction> v_trans;
    vector<Accounts4> v_acc4;
    while (ifs >> command) {
        if (command == "Account") {
            ifs >> acc_name >> acc_num;
            v_acc4.emplace_back(acc_name, acc_num);
        }
        else if (command == "Deposit") {
            ifs >> acc_num >> amount;
            for (Accounts4& acc : v_acc4) {
                if (acc.get_num() == acc_num) {
                    acc.deposit(amount);
                }
            }
        }
        else if (command == "Withdraw") {
            ifs >> acc_num >> amount;
            for (Accounts4& acc : v_acc4) {
                if (acc.get_num() == acc_num) {
                    acc.withdraw(amount);
                }
            }
        }
    }
    ifs.close();
    for (const Accounts4& temp: v_acc4) {
        cout << temp;
    }

    cout << "==============\n";
    cout << "\nTask 5:\nTransaction nested in private section of Account:\n";


}



ostream& operator<<(ostream& os, const Accounts& acc) {
//    os << acc.get_name() << " \t" << acc.get_num() << endl;
    os << acc.c_name << " \t" << acc.c_number << endl;
    return os;
}

ostream& operator<<(ostream& os, const Transaction& trans) {
//  Account# 6 has only 10. Insufficient for withdrawal of 100.
    os << " \t \t" << trans.type << ' ' << trans.amount;
    return os;
}

ostream& operator<<(ostream& os, const Accounts3& acc) {
    os << acc.acc3_name << " \t" << acc.acc3_num << ": " << endl;
    for (size_t i = 0; i < acc.trans.size(); i++) {
        os << acc.trans[i] << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, const Accounts4& acc) {
    os << acc.acc4_name << " \t" << acc.acc4_num << ": " << endl;
    for (size_t i = 0; i < acc.trans.size(); i++) {
        os << acc.trans[i] << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, const Accounts4::Transaction& trans) {
//  Account# 6 has only 10. Insufficient for withdrawal of 100.
    os << " \t \t" << trans.type << ' ' << trans.amount;
    return os;
}

size_t findAcc(int acc_num, vector<Accounts3>& v_acc3) {
    for (size_t i = 0; i < v_acc3.size(); i++) {
        if (v_acc3[i].get_num() == acc_num) {
            return i;
        }
    }
    return v_acc3.size();
}