#include<iostream>
#include <cstdlib>
#include<fstream>
#include <exception>

#include"global_Varaible.h"
#include"ACCOUNT.h"
#include"functions.h"
#include"structures.h"
#include"Card.h"
#include"Bank.h"
//#include"ACCOUNT.h"

/* Setting->Compiler->have g++ follow the c++11 IS0 C++ language standard should be
checked on.
*/


using namespace std;


int main()
{
    system("color F0");
    ofstream AccountFile;
    AccountFile.open("accountFile1.txt",ios::out| ios::binary );
    ACCOUNT c[3];
    c[0].set_values("John Doe", "123 Main Street", "555-1234", "1234567890123", "Bank of America", "US BOA 1234567890", "789", 5000, "1234 5678", "9876");
    c[1].set_values("Jane Smith", "456 Elm Street", "555-5678", "1234567890124", "Wells Fargo", "US WF 0987654321", "456", 2000, "4321 8765", "6543");
    c[2].set_values("Bob Johnson", "789 Oak Street", "555-9012", "1234567890125", "Chase Bank", "US CB 5678901234", "123", 10000, "5678 9012", "2109");

    AccountFile.tellp();
    AccountFile.write((char *)(c),3*sizeof(ACCOUNT));
    AccountFile.close();
    try
    {
        refresh_file();
    }
    catch(exception e )
    {
        cout<<e.what();
    }
    TopMENU();
    return 0;
}





