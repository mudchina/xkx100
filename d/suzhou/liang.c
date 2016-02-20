// Room: /d/suzhou/.c
// Last Modified by winder on Mar. 8 2001

inherit ROOM;

void init()
{
//	add_action("lingwu","lingwu");
	add_action("do_jump","jump");
}

void create()
{
	set("short", "梁上");
	set("long",@long
这是碧水亭上的房梁，上面画满了希奇古怪的字画。
long
        );
	set("outdoors","suzhou");
	set("no_clean_up", 0);
	set("coor/x", 800);
	set("coor/y", -1200);
	set("coor/z", 10);
	setup();
}

int lingwu(string arg)
{
	object me=this_player();
	string special;
	int bl,sl;

	if (!living(me)) return 0;
	if (!arg) return notify_fail("你要领悟什么？\n");
	if (!find_object(SKILL_D(arg)))
// 	if (!find_object(SKILL_D(arg)))
		return notify_fail("没有这种技能。\n");
	if (!me->query_skill(arg,1))
		return notify_fail("你不会这种技能。\n");
	if (!(special=me->query_skill_mapped(arg)))
		return notify_fail("你只能从特殊技能中领悟。\n");
	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") ||
		me->query("jing")*100/me->query("max_jing") < 20)
	{
		me->receive_damage("jing",bl/2);
		return notify_fail("你没办法集中精神。\n");
	}
	sl=me->query_skill(special,1);
	if (bl > sl)
		return notify_fail("你的"+CHINESE_D->chinese(special)+"造诣不够，无法领悟更深一层的"+CHINESE_D->chinese(arg)+"。\n");
	write("你对着字画瞑思苦想，对"+CHINESE_D->chinese(arg)+"的体会又深了一层。\n");
	me->receive_damage("jing",bl/2);
	me->improve_skill(arg,sl/5+1);
	return 1;
}
int do_jump(string arg)
{
	object me = this_player();

	if (arg !="down") return notify_fail("你要到那去？\n");
	if( arg=="down")
	{
		write("你纵身跳下了房梁。\n");
		message("vision", me->name() + "一纵身跳下了房梁。\n", environment(me), ({me}) );
		me->move(__DIR__"bishuiting");
		message("vision", me->name() + "从上面跳了下来。\n", environment(me), ({me}) );
	}
	return 1;
}
