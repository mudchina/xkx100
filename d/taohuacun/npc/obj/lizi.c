
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(RED "Àõ×Ó" NOR,({"lizi"}));
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»ÀºÀõ×Ó¡£\n");
                set("unit", "Àº");
        }
}