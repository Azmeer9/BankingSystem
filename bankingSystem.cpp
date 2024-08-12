#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class bankAccount {
protected:
    int balance;
    int accno;
    string name;
public:
    bankAccount() {
        balance = 0;
        accno = 0;
    }
    void setBalance(int bal) {
        balance = bal;
        cout << "User Balance is: " << balance << endl;
    }
    void setAccno(int no) {
        accno = no;
        cout << "User AccNo is : " << accno << endl;

    }
    void setName(string n) {
        name = n;
        cout << "Name :" << name << endl;
    }
    int getBalance() {
        return balance;
    }
    int getAccno() {
        return accno;
    }
    string getName() {
        return name;
    }
    void deposit(int am) {
        balance += am;
        cout << " Balance after deposit: " << balance << endl;

    }
    void withdraw(int am) {
        balance -= am;
        cout << " Balance after withdraw: " << balance << endl;


    }
};

class savingAcc : public bankAccount {
private:
    int interest;

public:
    savingAcc() {
        interest = 0;
    }

    void addInterest() {
        interest = getBalance() / 50;
        cout << "Interest on your Current Balance is: " << interest << endl;

      //  deposit(interest);  

        cout << "Interest added. New balance is: " << getBalance()- interest << endl<<"\n \n \n";

    }
};

class checkingAcc : public savingAcc {
private:
    int limit;

public:
    checkingAcc(int lim) {
        limit = lim;

    }
    void withdraw(int am) {
        if (getBalance() + limit >= am) {
            if (getBalance() >= am) {
                savingAcc::withdraw(am);
            }
            else {
                cout << "Transaction declined. Insufficient funds." << endl;
            }
        }
        else {
            cout << "Transaction declined. Insufficient funds." << endl;
        }
    }
};

int main() {

    ifstream fin;
    ofstream fout;
    fout.open("Records.txt");
    
    checkingAcc obj(10000);  // limit is 10k 
    
    //char q = { '\0' };

    int b = 0;
    string naam;
    int a = 0;
    int wcash = 0;
    int dcash = 0;
    cout << "**********WELCOME TO THE BANKING SYSTEM********** \n";
    cout << "\n Press any key if you want to Continue: \n";
    char choice;
    while (true) {
        cout << "Press 'Q' if you want to Quit: \n Press 'S' to Enter your Record:  \n ***ENTER*** :-";
        cin >> choice;
        if (choice == 'q' || choice == 'Q') {
            break;
        }

        int b = 0;
        string naam;
        int a = 0;
        int wcash = 0;
        int dcash = 0;

        cout << "Enter Initial Amount : ";
        cin >> b;
        cout << "\n Enter your name : ";
        cin >> naam;
        cout << "\nEnter Your Account # : ";
        cin >> a;
        cout << "\nEnter Amount You want to WITHDRAW: ";
        cin >> wcash;
        cout << "\nEnter Amount You want to DEPOSIT: ";
        cin >> dcash;

        obj.setBalance(b);
        obj.setName(naam);
        obj.setAccno(a);
        obj.withdraw(wcash);
        obj.deposit(dcash);
       // obj.addInterest();


        fout << "Account Number: " << a << endl;
        fout << "Name: " << naam << endl;
        fout << "Initial Balance: " << b << endl;
        fout << "Withdrawal: " << wcash << endl;
        fout << "Deposit: " << dcash << endl;
        fout << "Final Balance: " << obj.getBalance() << endl;
        fout << "------------------------" << endl;
    }

    fout.close();

  //obj.addInterest();

    return 0;
}
