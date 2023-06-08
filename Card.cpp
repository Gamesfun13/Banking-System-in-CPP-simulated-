#include "Card.h"
#include<cstring>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>

long unsigned Card_Count=90009922;

void Card::set_values(string No, string p)
{
    strcpy(Card_No,No.c_str());
    strcpy(pin,p.c_str());
}
void Card::input_pin()
{
    cout<<"\nEnter pin\n";
    cin.get(pin,5);
    if ((strlen(pin))!=4)
    {
        strcpy(pin,"None");
        cout<<" \nInvalid pin, try again";
    }
    else
    {
        create_Card_no();
        //display();
    }
}
void Card::create_Card_no()
{

    char Temp[9];
    sprintf(Temp,"%lu",Card_Count);
    Card_Count=Card_Count+1;

    strcpy(Card_No,Temp);

}
void Card::display()
{
    cout<<"\nCard Number :" << Card_No <<"\tPin assigned :"<<pin<<endl;
}

string Card::get_pin()
{
    return (string)pin;
}

void Card::set_pin(string p)
{
    strcpy(pin,p.c_str());
}

