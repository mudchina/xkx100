// Room: /d/tiezhang/juebi1.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "绝壁");
	set("long", @LONG
你走到这里，发现前面已经没有路了。你面前是一座立陡的山峰，
高耸入云，看不到尽头。石壁上生长着很多松树，疾风吹来，沙沙作响。
看来想上峰顶，只能爬上去了。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"shangu2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2010);
	set("coor/y", -1880);
	set("coor/z", 50);
	setup();
}

void init()
{
	add_action("do_zhua","zhua");
	add_action("do_climb","climb");
}

int do_zhua(string arg)
{
	object me;
	me=this_player();
    
	if (arg =="松树")
	{
		write("你牢牢的抓住石壁上的松树。\n");
		this_player()->set_temp("marks/抓1", 1);
		return 1;
	}
	return notify_fail("你要抓什么？\n");
}

int do_climb(string arg)
{
	mapping fam;
	object me;
	me=this_player();

	if ( (int)me->query_skill("dodge", 1) < 30)
		return notify_fail("你的轻功不够，无法爬上去。\n");

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "铁掌帮")
		return notify_fail("你非本帮弟子，不能上峰！\n");

	if (!me->query_temp("marks/抓1") )
		return notify_fail("无处攀缘，好象爬不上去。\n");
	if (arg =="up")
	{
		write("你吸了口气，小心的向上爬去。\n");
		message("vision",me->name() + "向上一纵突然不见了。\n", environment(me), ({me}) );
		me->move(__DIR__"juebi2");
		message("vision", me->name() + "爬了上来。\n", environment(me), ({me}) );
		me->delete_temp("marks/抓1");
		if ((int)me->query_skill("dodge",1)>100)
			write("你觉得很难从中领悟到轻功身法。\n");
		else
		{
			me->receive_damage("qi", 40);
			me->improve_skill("dodge",me->query("int"));
		}
		return 1;
	}
	return notify_fail("你要往哪儿爬？\n");
}
