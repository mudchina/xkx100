// datefile for assign job
// Last Modified by winder on Jul. 12 2002

#include <dbase.h>

void create()
{
        seteuid(0);
}

void setup()
{
        seteuid(getuid(this_object()));
}
