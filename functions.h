#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include"ACCOUNT.h"
using namespace std;

int Account_matching( string ACC_num);
void printstar(char ch, int n);
void Disp_ATM_Menu();
void ATM_resp(ACCOUNT &A,int choice);
void TopMENU();
void refresh_file();
void printALL();
int Customer_sel();
void Disp_Bank_Menu();
void Bank_resp(int choice);
void flush_inputt();
int check_Bank_pin();


#endif // FUNCTIONS_H
