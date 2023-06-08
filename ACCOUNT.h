#ifndef ACCOUNT_H
#define ACCOUNT_H

#include"Bank.h"
#include"structures.h"
#include"Card.h"

using namespace std;
class ACCOUNT:public Bank
{
protected:
    struct personal_info P;
    struct Account_info A;
    double balance;
    Card C;
public:
    //ACCOUNT():Acc_At_Bank("None"),branch_Code("None"), phone_No("none"), Acc_number("none"),balance(0), Card(NULL) {};

    ACCOUNT();
    ~ACCOUNT() {};
    void set_values(string N, string Ad, string ph, string nic, string acc_B,string acc_n, string B,double bal);
    void set_values(string N, string Ad, string ph, string nic, string acc_B,string acc_n, string B,double bal,string No,string p);
    bool Credit(double x);
    bool Debit(double x);
    void display();
    int get_values();
    void create_card();
    void create_Acc_no();
    double get_balance();
    int check_pin(string Account_no ) ; //Verify account password function
    void SetLimit(double NewLimit);
    double GetLimit();
    string get_ACC_num();
    struct personal_info get_Personal_info();
    void change_pin();
    string get_Card_no();

};

#endif // ACCOUNT_H
