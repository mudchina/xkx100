#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC "Ð¡Öí¶ú¶ä" NOR,({"erduo"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿éÐ¡Öí¶ú¶ä¡£\n");
                set("unit", "¿é");
        }
}