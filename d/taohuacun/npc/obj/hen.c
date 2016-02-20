#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL "Ä¸¼¦" NOR,({"hen"}));
	set_weight(200);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»Ö»ÄÛÄ¸¼¦¡£\n");
                set("unit", "Ö»");
        }
}