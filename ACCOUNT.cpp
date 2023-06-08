#include "ACCOUNT.h"
#include <cstring>
#include<iostream>
#include "functions.h"
#include <structures.h>
#include"Exception_class.h"

long unsigned  Acc_Count=10924234;

ACCOUNT::ACCOUNT():Bank(),balance(0)
{
    strcpy(P.name,"None");
    strcpy(P.address,"None");
    strcpy(P.phone_No,"None");
    strcpy(P.NIC,"None");
    strcpy(A.Acc_At_Bank,"None");
    strcpy(A.Acc_number,"None");
    strcpy(A.branch_Code,"None");
    balance=0;

}
void ACCOUNT::set_values(string N, string Ad, string ph, string nic, string acc_B,string acc_n, string B,double bal)
{
    strcpy(P.name,N.c_str());
    strcpy(P.address,Ad.c_str());
    strcpy(P.phone_No,ph.c_str());
    strcpy(P.NIC,nic.c_str());
    strcpy(A.Acc_At_Bank,acc_B.c_str());
    strcpy(A.Acc_number,acc_n.c_str());
    strcpy(A.branch_Code,B.c_str());
    balance= bal;
    ///Card no and pin are by default none
}
void ACCOUNT::set_values(string N, string Ad, string ph, string nic, string acc_B,string acc_n, string B,double bal,string No,string p)
{
    strcpy(P.name,N.c_str());
    strcpy(P.address,Ad.c_str());
    strcpy(P.phone_No,ph.c_str());
    strcpy(P.NIC,nic.c_str());
    strcpy(A.Acc_At_Bank,acc_B.c_str());
    strcpy(A.Acc_number,acc_n.c_str());
    strcpy(A.branch_Code,B.c_str());
    balance= bal;
    C.set_values(No,p);
}
bool ACCOUNT::Credit(double x)
{

    if (x<=0)
    {
        cout<<"\nBalance input was invalid, balance remain unchanged.\n";
    }
    else if(x<startingBaLance && flag_FirstDeposit==0)
    {
        flag_FirstDeposit=false;
        cout<<"\nYou have to deposit equal or more than starting balance.\n";
    }
    else
    {
        balance+=x;
        cout<<"\nYour credited amount: "<<x<<endl;
        return true;
    }
    return false;
}
bool ACCOUNT::Debit(double x)
{
    if (x<=0)
    {
        cout<<"\nBalance input was invalid, balance remain unchanged.\n";
    }
    else if(balance<x)
    {
        cout<<"\nDebit amount exceeded account balance.\n";
    }
    else if(x>limit)
    {
        cout<<"\nDebit amount exceed the maximum Limit.\n";
    }
    else
    {
        balance-=x;
        cout<<"\nYour withdrew amount: "<<x<<endl;
        return true;
    }
    return false;
}
void ACCOUNT::display()
{
    cout<<"\nName :" << P.name <<"\tAddress :"<<P.address;
    cout<<"\nNIC :" << P.NIC <<"\tPhone :"<<P.phone_No;
    cout<<"\nBank :" << A.Acc_At_Bank <<"\tBranch code :"<<A.branch_Code<<endl;
    cout<<"Account number :"<<A.Acc_number<<"\t balance :"<<balance;
    C.Card::display();
}
int ACCOUNT::get_values()
{
    int flag=1;
    string Name_temp;
    string Address_temp;
    string Phone_No_temp;
    string NIC_temp;

    string Acc_At_Bank_temp;
    string branch_Code_temp;

    string pin_temp;

    while(flag==1)
    {
        try
        {
            cout<<"\nEnter Name\n";
            cout<<"Should Be less than 20 characters\n";
            cin>>Name_temp;
            flush_inputt();
            if(Name_temp=="Q" || Name_temp=="q")
            {
                return -1;
            }
            if(Name_temp.size()>=20)
            {
                throw Exceed_Limit();
            }
            cout<<"\nEnter Address\n";
            cout<<"Should Be less than 20 characters\n";
            cin>>Address_temp;
            flush_inputt();
            if(Address_temp.size()>=20)
            {
                throw Exceed_Limit();
            }

            cout<<"\nEnter NIC Number\n";
            cout<<"Should Be 13 digits\n";
            cin>>NIC_temp;
            flush_inputt();
            if(NIC_temp.size()!=13)
            {
                throw invalid_NIC_no();
            }

            cout<<"\nEnter Phone Number\n";
            cout<<"Should Be 11 digits\n";
            cin>>Phone_No_temp;
            flush_inputt();
            if(Phone_No_temp.size()!=11)
            {
                throw invalid_phone_no();
            }

            cout<<"\nEnter the bank Name\n";
            cout<<"Should Be less than 20 characters\n";
            cin>>Acc_At_Bank_temp;
            flush_inputt();
            if(Acc_At_Bank_temp.size()>=20)
            {
                throw Exceed_Limit();
            }

            cout<<"\nEnter Branch code\n";
            cout<<"Should Be less than 4 digits\n";
            cin>>branch_Code_temp;
            flush_inputt();
            if(branch_Code_temp.size()>=5)
            {
                throw invalid_branch_code();
            }



            cout<<"\nEnter initial Deposit\n";
            float bal;
            cin>>bal;
            Credit(bal);
            flush_inputt();

            cout<<"Do you want to create Debit card (y/n): ";
            char ch=getchar();
            if(ch=='y')
            {
                cout<<"\nEnter pin code\n";
                cout<<"Should Be 4 digits\n";
                cin>>pin_temp;
                flush_inputt();
                if(pin_temp.size()!=4)
                {
                    throw invalid_branch_code();
                }
                else
                {
                    C.create_Card_no();
                    C.set_pin(pin_temp);
                }

            }


            strcpy(P.name,Name_temp.c_str());
            strcpy(P.address,Address_temp.c_str());
            strcpy(P.phone_No,Phone_No_temp.c_str());
            strcpy(P.NIC,NIC_temp.c_str());
            strcpy(A.Acc_At_Bank,Acc_At_Bank_temp.c_str());
            strcpy(A.branch_Code,branch_Code_temp.c_str());

            flag=-1;

        }
        catch(exception &e)
        {
            flag=1;
            cout<<e.what();
            cout<<"\nEnter Detail again and carefully.";
            system("Pause");
            system("cls");
            cout<<"\nEnter Detail again and carefully.";
            cout<<"\nif want to exit write Q in the Name section.";
        }


    }
    create_Acc_no();
    display();
    system("pause");
    return 1;

}




void ACCOUNT::create_card()
{
    C.input_pin();
}
void ACCOUNT::create_Acc_no()
{
    char X[8]="PK HBB ";
    char Temp[9];
    sprintf(Temp,"%lu",Acc_Count);
    Acc_Count=Acc_Count+1;
    strcpy(A.Acc_number,strcat(X,Temp));

}
double ACCOUNT::get_balance()
{
    return ACCOUNT::balance;
}

int ACCOUNT::check_pin(string Account_no )  //Verify account password function
{
    int i = 0;
    string pin;
    cout << "Please enter pin" << endl;
    flush_inputt();
    for (i = 0; i < 3; i++)
    {
        //Cannot exceed three attempts

        getline(cin,pin);

        if (( ! strcmp(Account_no.c_str(), A.Acc_number))&&( !strcmp(pin.c_str(),C.pin)))
        {
            system("cls");
            cout << "Login to " << (string)A.Acc_At_Bank << " ATM successfully!" << endl
                 << "welcome!" << endl;
            return 1;
        }
        else
        {
            cout << "Incorrect account or password, please re-enter" << endl;
            if (i >= 2)
            {
                cout << "You have tried more than three times and have been frozen" << endl;
                //Output press any key to continue
                cout<<"\n Press Enter to Exit, Try again";
                getchar();
            }
        }
    }
    return 0;
}

void ACCOUNT::SetLimit(double NewLimit)
{
    limit=NewLimit;
}

double ACCOUNT::GetLimit()
{
    return limit;
}

string ACCOUNT::get_ACC_num()
{
    return (string)A.Acc_number;
}
struct personal_info  ACCOUNT::get_Personal_info()
{
    return P;
}


void ACCOUNT::change_pin()	// //Modify password function
{
    string new_pin1, new_pin2, pwd;
    cout << "Please enter the Current pin: ";
    cin >> pwd;
    cout << endl;
    if (pwd == C.pin)
    {
        cout << "Please enter a new pin: ";
        cin >> new_pin1;
        cout << endl;
        cout << endl;
        while (new_pin1 == C.get_pin() || new_pin1.size()!=4)
        {
            cout << "The pin Should not be the same as old and Not be less than or greater than $ characters: ";
            cin >> new_pin1;
            cout << endl;
        }
        cout << "Please enter the new pin again: ";
        cin >> new_pin2;
        cout << endl;
        while (new_pin1 != new_pin2)
        {
            cout << "Different from the first input, please input again: ";
            cin >> new_pin2;
            cout << endl;
        }
        C.Card::set_pin( new_pin2);
        cout << "\npin has been updated! " << endl;
        cout << endl;
    }
    else if (pwd != C.get_pin())
    {
        cout << "Wrong pin, try again ";
    }
    system("pause");//Output press any key to continue
    system("cls");//Clear screen function
}




string ACCOUNT::get_Card_no()
{
    return (string) C.Card_No;
}
