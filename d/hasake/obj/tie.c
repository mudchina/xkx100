#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"快雪时晴帖"NOR, ({ "kuaixueshiqing tie", "tie"})); 
       
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "张");
                set("weight", 300);
		set("long", "这是晋王羲之所写之帖，纸册本，纵二三寸，横一四寸。\n");
		set("material", "paper");
		}
	setup();
}