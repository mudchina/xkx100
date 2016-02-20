
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("²İÓã",({"caoyu"}));
	set_weight(80);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»Î²»î±ÄÂÒÌøµÄ²İÓã¡£\n");
                set("unit", "Î²");
        }
}