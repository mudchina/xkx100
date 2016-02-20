// Room: /d/gumu/shiguan.c
// Last Modifyed by Winder on Jan. 14 2002

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIB"石棺内"NOR);
	set("long", @LONG
棺盖内侧似乎写得有字，凝目瞧去，果见是十六个大字：「玉女心
经，技压全真。重阳一生，不弱于人。」这十六个字以浓墨所书，笔力
苍劲，字体甚大。其时棺盖只推开了一半，但斜眼看去，仍是清清楚楚。
LONG	);
	set("exits", ([ 
		"out" : __DIR__"lingshi",
	]));
	set("no_clean_up", 0);
	set("no_fight",1);
	set("coor/x", -3000);
	set("coor/y", -40);
	set("coor/z", 70);
	setup();
}

void init()
{
	add_action("do_dian", "use");
	add_action("do_dian", "dian");
	add_action("do_turn", "turn");
	add_action("do_turn", "zhuan");
	add_action("do_ti", "ti");
	add_action("do_search","search");
}

int do_dian(string arg)
{
	object ob,me=this_player();

	if ( arg == "fire")
	{
		if(!objectp(ob = present("fire", me)))
			return notify_fail("你没有火折，点什么？\n");
		message_vision(HIR"只听见“呲 ---”的一声，$N点亮了手中的火折。\n\n"NOR,me);
		write(HIY"再看那十六个字时，只见其后还写得有许多小字：破解玉女心经之法，吾置之于此室之下，后人有缘，一观便知 ......重阳真人 .....\n"NOR);
		me->set_temp("marks/古墓1", 1);
		return 1;
	}
	return 0;
}

int do_search()
{
	object me = this_player();

	if (!me->query_temp("marks/古墓1")) return 0;
	if (me->query_temp("gumu1") < 8)
	{
		message_vision(HIY"$N点亮火折，仔细地在石棺内四下摸索。\n"NOR,me);
		me->add_temp("gumu1",1);
		return 1;
	}
	message_vision(HIR"$N觉得手下一沉，果然摸到个可容一手的凹(ao)处。\n"NOR,me);
	me->delete_temp("marks/古墓1");
	me->delete_temp("gumu1");
	me->set_temp("marks/古墓2", 1);
	return 1;
}

int do_turn(string arg)
{
	object me=this_player();
	string dir;
	if (!me->query_temp("marks/古墓2")) return 0;
	if (!arg||arg=="") return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if( arg=="ao" )
	{
		write("你要把凹处往哪里转？\n");
	}
	if( sscanf(arg, "ao %s", dir)==1 )
	{
		if( dir=="left")
		{
			message_vision(HIG"$N将凹处往左转动几下，果然有些松动。\n"NOR, me);
			me->delete_temp("marks/古墓2");
			me->set_temp("marks/古墓3", 1);
		}
		else
			return notify_fail("你将凹处胡乱转了几下，结果什么也没发生。\n");
	}
	return 1;
}

int do_ti(string arg)
{
	object me =this_player();

	if (!me->query_temp("marks/古墓3")) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if ( arg =="up")
	{
		message_vision(YEL "$N紧紧握住了凹处向上一提，只听喀喇一响，棺底石板应手而起，$N猝不及防，翻身跌入下层石室。\n"NOR,me);
		me->delete_temp("marks/古墓3");
		me->move(__DIR__"shishi6");
		return 1;
	}
	return notify_fail("你往哪里提？\n");
}
