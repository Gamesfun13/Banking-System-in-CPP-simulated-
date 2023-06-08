#ifndef BANK_H
#define BANK_H


class Bank
{

public:
    int startingBaLance=0;
    double limit=10000;
    bool flag_FirstDeposit=true;
    Bank();
    virtual ~Bank()=default;
    virtual bool Debit(double )=0;
    virtual bool Credit(double )=0;
    virtual double get_balance()=0;
    virtual void display()=0;
    virtual void SetLimit(double NewLimit)=0;
    virtual double GetLimit()=0;

};

#endif // BANK_H
