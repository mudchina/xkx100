
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(YEL "»Æ¹Ï" NOR,({"cuke","huanggua"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»Àº»Æ¹Ï¡£\n");
                set("unit", "Àº");
        }
}