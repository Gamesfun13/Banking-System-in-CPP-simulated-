#include "Exception_class.h"

const char * invalid_phone_no::what() const noexcept
{
    return "\nPhone number invalid";

}

const char * invalid_branch_code::what() const noexcept
{
    return "\nInvalid Branch code entered!!!";

}
const char * invalid_NIC_no::what() const noexcept
{
    return "\nInvalid NIC Number entered!!!";

}
const char * invalid_Pin_code::what() const noexcept
{
    return "\nInvalid pin Entered!!!";

}

const char * Exceed_Limit::what() const noexcept
{
    return "\nLimit Exceed, Plz write under 20 characters!!!";

}
