
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIY "ÀğÓã" NOR,({"liyu"}));
	set_weight(80);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»Î²»î±ÄÂÒÌøµÄÀğÓã¡£\n");
                set("unit", "Î²");
        }
}