// shedu.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat","eat");
}

void create()
{
	set_name("蛇毒囊", ({"she dunang" ,"dunang"}));

	set("unit", "个");
	set("long", "这是一个毒蛇的毒囊。\n");
	set("value", 100);
//	set("no_drop", "这样东西不能离开你。\n");
	set_weight(100);

	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	object ob = this_object();
	if (arg != "she dunang" && arg !="dunang") return 0;
	tell_object(me,  "你想死啊，用suicide比较快一点。\n" );
	return 1;
}
