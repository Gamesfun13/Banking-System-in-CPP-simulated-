#ifndef CARD_H
#define CARD_H
#include<string>

using namespace std;
class Card
{
private:
    char Card_No[20];
    char pin[5];
public:
    friend class ACCOUNT;
    Card():Card_No("None"),pin("None") {};
    void set_values(string No, string p);
    void input_pin();
    void create_Card_no();
    void display();
    string get_pin();
    void set_pin(string p);

};

#endif // CARD_H
