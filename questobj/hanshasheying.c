// hanshasheying.c 含沙射影

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name("含沙射影", ({ "han sha she ying", "hssy" }) );
	set_weight(500);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是五毒教的奇门暗器「含沙射影」，样子象一条腰带，可以束在腰间。\n带中间有一个扁扁的小铁盒。\n") ;
		set("unit", "个");
		set("value", 0);
		set("material", "iron");
		set("armor_prop/armor", 3);
	}
	setup();
}

void init()
{
}
