// Room: /d/gumu/liangong3.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIR"练功房"NOR);
	set("long", @LONG
里面又是一室，却和先一间处处对称，而又处处相反，乃是北窄南
宽，西圆东角，室顶也是刻满了无数符号。此处乃是古墓派祖师林朝英
的武功之秘。
LONG	);      
	set("no_clean_up", 0);
	set("coor/x", -3190);
	set("coor/y", -30);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_xiulian", "xiulian");
	add_action("do_tui", "tui");
	add_action("do_tui", "push");
}

int do_xiulian(string arg)
{
	mapping fam;
	object me = this_player();
	int c_exp, c_skill;

	if ( !arg ) 
		return notify_fail("你要参照哪里来修炼？\n");
	c_exp=me->query("combat_exp");
	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if (me->query("jing") < 20)
		return notify_fail("你精力不能集中，去稍作歇息吧。\n");
	if ((int)me->query_skill("literate", 1) < 30)
		return notify_fail("你丫斗字不识一箩筐，领悟个啥？\n");
	if (arg == "top")
	{
		if ((int)me->query_skill("sword", 1) < 20)
			return notify_fail("你基本剑法太差，无法研习玉女剑法。\n"); 
		if (me->query_skill("yunv-jian", 1) >= 1)
			return notify_fail("你已经学会玉女剑法，自己好好练吧。\n");      
		write("你仰视室顶的图纹，心中揣摩玉女剑法的精妙之处。\n");
		me->receive_damage("jing", 5);
		me->improve_skill("yunv-jian", 2);
		return 1;
	}
	if (arg == "southwall")
	{
		write("你抡掌劈向南方石壁，蓬一声被震退数步，手臂一阵酸麻。\n");
		c_skill=(int)me->query_skill("strike", 1);
		if (c_skill < 50)
			return notify_fail("你看了半天只觉莫测高深，什么也没有学会。\n");
		if (c_skill > 100)
			return notify_fail("你掌力雄浑，不该再死练蛮力了。\n");
		me->receive_damage("jing", 5 + random(15));
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("strike", random(me->query("int")));
		return 1;
	}
	if (arg == "northwall")
	{
		write("你挥拳直击北壁，石粉四溅，你也被自己的猛劲震退数步。\n");
		c_skill=(int)me->query_skill("unarmed", 1);
		if (c_skill < 50)
			return notify_fail("你看了半天只觉莫测高深，什么也没有学会。\n");
		if (c_skill > 100)
			return notify_fail("你拳力已刚猛无比，却无甚招数。\n");
		me->receive_damage("jing",5 + random(15));
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("unarmed", random(me->query("int")));
		return 1;
	}
	if (arg == "eastwall")
	{
		write("你绕东面石壁踏着剑步，用心揣摩壁上剑法精髓。\n");
		c_skill=(int)me->query_skill("sword", 1);
		if (c_skill < 50)
			return notify_fail("你看了半天只觉莫测高深，什么也没有学会。\n");
		if (c_skill > 100)
			return notify_fail("你对石壁上所述剑法已全然掌握，无须再费力了。\n");
		me->receive_damage("jing", 5 + random(15));
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("sword", random(me->query("int")));
		return 1;
	}
	if (arg == "westwall")
	{
		write("你虚拈手指，面对西面石壁，细心操练暗器的收发手势。\n");
		c_skill=(int)me->query_skill("throwing", 1);
		if (c_skill < 50)
			return notify_fail("你看了半天只觉莫测高深，什么也没有学会。\n");
		if (c_skill > 100)
			return notify_fail("你暗器收发随心，再不能提高于此。\n");
		me->receive_damage("jing", 5 + random(15));
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("throwing", random(me->query("int")));
		return 1;
	}
	return notify_fail("你无法参照那里来修炼。\n");
}

int do_tui(string arg)
{	
	object me=this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if ( arg == "westwall")
	{
		message_vision(YEL "$N伸手到半圆的弧底推了几下，一块大石缓缓移开，现出一扇洞门。\n"NOR,me);
		set("exits/out", __DIR__"liangong2");
		me->receive_damage("qi", 30);
		remove_call_out("close");
		call_out("close", 5, this_object());    
		return 1;
	}
	return notify_fail("你要推什么？\n");
}

void close(object room)
{
	message("vision",HIY"大石慢慢退回了原位，又挡住了出口。\n"NOR, room);
	room->delete("exits/out");
}

