// table.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("桌子", ({ "zhuo zi", "table", "zhuo" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
                set("long", "这是一张很普通的桌子。\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

int is_container() { return 1; }

void init()
{
	object ob;
	ob=new(__DIR__"qiancenggao");
	ob->move(this_object());
	ob=new(__DIR__"wandouhuang");
	ob->move(this_object());
	ob=new(__DIR__"shaomai");
	ob->move(this_object());
	ob=new(__DIR__"shaobing");
	ob->move(this_object());
}

