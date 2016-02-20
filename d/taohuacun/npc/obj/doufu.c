#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW "¶¹¸¯" NOR,({"doufu"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "¼¸¿éÏÊÄÛµÄ¶¹¸¯¡£\n");
                set("unit", "Ð©");
        }
}