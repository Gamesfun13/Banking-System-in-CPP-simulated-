#ifndef EXCEPTION_CLASS_H
#define EXCEPTION_CLASS_H

#include<exception>
using namespace std;

class invalid_phone_no:public exception
{
public:
    const char* what() const noexcept override;
};


class invalid_NIC_no:public exception
{

public:
    const char* what() const noexcept override;
};


class invalid_Pin_code:public exception
{

public:
    const char* what() const noexcept override;
};

class Exceed_Limit:public exception
{

public:
    const char* what() const noexcept override;
};

class invalid_branch_code:public exception
{

public:
    const char* what() const noexcept override;
};


#endif // EXCEPTION_CLASS_H
