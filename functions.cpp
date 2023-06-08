#include "functions.h"
#include<iostream>
#include <fstream>
#include"global_Varaible.h"
using namespace std;
string BankPin="6767";


int Account_matching( string ACC_num)
{
    for(int i=0; i<=AccsizeInfile; i++)
    {
        if((ACC_num==(b[i].get_ACC_num())))
        {
            return i;
        }
    }
    return -1;
}

void printstar(char ch, int n)
{
    for(int i=1; i<=n; i++)
    {
        cout<<ch;
    }
    cout<<"\n";
}

void Disp_ATM_Menu()
{
    cout<<"    ATM MAIN SCREEN    \n";
    cout<<"[1] Inquire Balance \n";
    cout<<"[2] Withdraw \n";
    cout<<"[3] Deposit \n";
    cout<<"[4] View Account details \n";
    cout<<"[5] Change your Pin\n";
    cout<<"[6] Quit \n";
    cout<<"\n";
    cout<<"Enter Option:";
}



void ATM_resp(ACCOUNT &A,int choice)
{

    switch(choice)
    {
    case 1:
    {
        system("cls");
        cout<<"the balance is:"<<A.ACCOUNT::get_balance();
        break;
    }
    case 2:
    {
        system("cls");
        int amount;
        cout<<"\nEnter Amount to Withdraw:";
        cin>>amount;
        flush_inputt();
        A.ACCOUNT::Debit(amount);
        cout<<"the balance left is:"<<A.ACCOUNT::get_balance();
        break;
    }
    case 3:
    {
        system("cls");
        int amount;
        cout<<"\nEnter Amount to Deposit:";
        cin>>amount;
        flush_inputt();
        A.ACCOUNT::Credit(amount);
        cout<<"Now the balance is:"<<A.ACCOUNT::get_balance();
        break;
    }
    case 4:
    {
        system("cls");
        A.ACCOUNT::display();
        break;
    }
    case 5:
    {
        system("cls");
        A.ACCOUNT::change_pin();
        break;
    }
    }
}



void TopMENU()
{

    cout<<"     MAIN SCREEN    \n";
    cout<<"[1] ATM \n";
    cout<<"[2] BANK\n";
    cout<<"[3] Quit \n";
    cout<<"\n";
    cout<<"Enter Option:";
    int choice;
    cin>>choice;
    while(choice!=3)
    {
        switch(choice)
        {
        case 1:
        {

            system("cls");
            system("color 17");
            int customer=Customer_sel();
            system("cls");

            cout<<"\nWelcome "<<(string)(b[customer].get_Personal_info()).name<<endl;
            if (((b[customer].get_Card_no())=="None"))
            {
                cout<<"\nYou do not have debit card!!";
                cout<<"Go To bank and Create Debit Card!!\n";
                system("Pause");
            }
            else if(b[customer].check_pin(b[customer].get_ACC_num())==1 )
            {
                flush_inputt();

                Disp_ATM_Menu();
                int ATMchoice;
                cin>>ATMchoice;
                while(ATMchoice!=6)
                {
                    flush_inputt();

                    ATM_resp(b[customer],ATMchoice);
                    cout<<"\nPress Enter to get back to ATM Main Menu....";

                    if(getchar())
                    {
                        system("cls");
                        Disp_ATM_Menu();
                    }
                    cout<<"\n";
                    cin>>ATMchoice;
                }
            }


            break;
        }
        case 2:
        {
            system("cls");
            system("color 2F");
            cout<<"\nBank Login\n";
            if(check_Bank_pin()==1)
            {
                system("cls");

                Disp_Bank_Menu();
                int Bankchoice;
                cin>>Bankchoice;
                while(Bankchoice!=5)
                {
                    Bank_resp(Bankchoice);
                    cout<<"\nPress Enter to get back to Bank Main Menu....";
                    flush_inputt();
                    if(getchar()=='\n')
                    {
                        system("cls");
                        Disp_Bank_Menu();
                    }
                    cout<<"\n";
                    cin>>Bankchoice;
                }
                break;
            }
        }
        }
        system("cls");
        system("color F0");
        cout<<"     MAIN SCREEN    \n";
        cout<<"[1] ATM \n";
        cout<<"[2] BANK\n";
        cout<<"[3] Quit \n";
        cout<<"\n";
        cout<<"Enter Option:";
        cin>>choice;

    }

}


void printALL( )
{
    int i=0;
    for( i=0; i<AccsizeInfile; i++)
    {
        b[i].ACCOUNT::display();
    }

}


int Customer_sel()
{

    int i=0;
    int ch;
    for( i=0; i<AccsizeInfile; i++)
    {
        cout<<i<<"."<<(string)(b[i].get_Personal_info()).name<<" Entered his card"<<endl<<endl;
    }
    cout<<"\nSelect a choice : ";

    while(!(ch<AccsizeInfile))
    {
        cin>>ch;
        if(ch>=AccsizeInfile)
        {
            cout<<"Invalid Option. Enter Again\n";
        }
    }
    return ch;
}


void refresh_file()
{
// delete b;
    b=new ACCOUNT[AccsizeInfile];
    ifstream infile;
    infile.open("accountFile1.txt",ios::in|ios::binary);
    infile.seekg(0,ios::beg);
    infile.read((char *)b,AccsizeInfile*sizeof(ACCOUNT));
    infile.close();

}


void Disp_Bank_Menu()
{
    cout<<"    Bank MAIN SCREEN    \n";
    cout<<"[1] Create Account \n";
    cout<<"[2] Set limits on account \n";
    cout<<"[3] Display Account details \n";
    cout<<"[4] Create Debit card \n";
    cout<<"[5] Quit \n";
    cout<<"\n";
    cout<<"Enter Option:";
}

void Bank_resp(int choice)
{

    switch (choice)
    {
    case 1:
    {
        flush_inputt();
        system("cls");
        ACCOUNT A;
        int x=A.ACCOUNT::get_values();
        if(x==1)
        {
            ofstream outfile;
            outfile.open("accountFile1.txt", ios::out| ios::app |ios::binary);
            outfile.write((char *)(&A),sizeof(A));
            outfile.close();
            AccsizeInfile++;
            refresh_file();
        }
        break;
    }
    case 2:
    {
        system("cls");
        string ACC_numm;
        cout<<"\nEnter your Account number :";
        cout<<"\nEnter with spaces as in account number: ";
        flush_inputt();
        getline(cin,ACC_numm);
        int match_no=Account_matching(ACC_numm);
        if(match_no>=0)
        {
            int N;
            cout<<"\nAccount Matched!!";
            cout<<(string)(b[match_no].get_Personal_info()).name<<endl;
            cout<<"\nCurrent limit : " <<b[match_no].ACCOUNT::GetLimit();
            cout<<"\nEnter the Limit:";
            cin>>N;
            b[match_no].ACCOUNT::SetLimit(N);
            cout<<"\n Limit set :"<<b[match_no].ACCOUNT::GetLimit();
        }
        else
        {
            cout<<"\nSorry we got no match, Try again.";
        }
        break;
    }
    case 3:
    {
        system("cls");
        string ACC_numm;
        cout<<"\nEnter your Account number :";
        cout<<"\nEnter with spaces as in account number: ";
        flush_inputt();
        getline(cin,ACC_numm);
        int match_no=Account_matching(ACC_numm);
        if(match_no>=0)
        {
            b[match_no].ACCOUNT::display();
        }
        else
        {
            cout<<"\nSorry we got no match, Try again.";
        }
        break;
    }
    case 4:
    {
        system("cls");
        string ACC_numm;
        cout<<"\nEnter your Account number :";
        cout<<"\nEnter with spaces as in account number: ";
        flush_inputt();
        getline(cin,ACC_numm);
        int match_no=Account_matching(ACC_numm);

        if(match_no>=0)
        {
            cout<<"\nAccount Matched: "<<b[match_no].get_Personal_info().name;
            if(b[match_no].get_Card_no()=="None")
            {
                cout<<"\nPin Should Be 4 digits";
                b[match_no].create_card();
            }
            else
            {
                cout<<"\nYou Already have debit card";
            }
        }
        else
        {
            cout<<"\nSorry we got no match, Try again.";
        }
        break;
    }

    }

}

void flush_inputt()
{
    while(getchar()!='\n');
}

int check_Bank_pin()  //Verify BAnk pin function
{
    int i = 0;
    string pin;
    cout << "Please enter pin" << endl;
    flush_inputt();
    for (i = 0; i < 3; i++)
    {
        //Cannot exceed three attempts

        getline(cin,pin);

        if (BankPin==pin)
        {
            system("cls");
            cout << "Login to " << "Bank Successful " << endl
                 << "welcome!" << endl;
            return 1;
        }
        else
        {
            cout << "Incorrect pin, please re-enter" << endl;
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
