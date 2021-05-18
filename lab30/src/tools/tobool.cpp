#include "tobool.h"

string bool_output(bool b)
{
    return (b) ? ("есть") : ("нет");
}

string BoolToString(bool b)
{
    return (b) ? ("true") : ("false");
}

bool StringToBool(string str)
{
    if ( str == "true" )
        return true;
    else
        return false;
}