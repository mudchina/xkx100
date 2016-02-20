
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(YEL"ÅÅ¹Ç"NOR,({"chop","paigu"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿éĞÂÏÊµÄÖíÅÅ¹Ç¡£\n");
                set("unit", "¿é");
        }
}