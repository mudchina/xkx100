// yaofen.c 药粉

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("药粉", ({ "yao fen" , "yao", "fen" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包专治内伤的药粉。\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("你要吃什么药？\n");
	return notify_fail("只有专练可对付‘化骨绵掌’的武功的人才需要服这种药。\n");

}

