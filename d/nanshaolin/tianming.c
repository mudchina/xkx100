// Room: /d/nanshaolin/tianming.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",CYN"天鸣禅台"NOR);
	set("long", @LONG
一间宽敞空旷的石室，室中只有一张石床，四壁如素。抬头望去，
梁上雕着一只石鹰，振翅欲飞。鹰爪间垂下几条粗如儿臂的大绳。大师
是无色无相等的师叔。前辈高僧当年执掌少林佛法渊深，名震天下。天
鸣大师晚年修为更为精进，为重新修订少林爪法(claw)绝技。于此石室
内闭关经年，坐化于此。其绝世武功湮没于空室之中。
LONG );
	set("exits", ([
		"out" : __DIR__"fota2",	 
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_claw","claw");
}
int do_claw(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("claw", 1), exp = me->query("combat_exp");
	if (arg!="sheng") return 0;
	if (!living(me)) return 0;
	message("vision", me->name()+"身形飘起，一式振翅迎风，向大绳上抓去。\n", environment(me), ({me}) );
	if (lvl<30)
	{
		write(HIR"你手上乏力，虽然抓住大绳，但随既酸软，连忙放开。\n"NOR);
		return 1;
	}
	if (lvl * lvl * lvl / 10 < exp)
	{
		write(HIR"你经验太浅，没法够着大绳。\n"NOR);
		return 1;
	}
	if (lvl>100)
	{
		write(HIR"你用力过猛，大绳从中断绝。\n"NOR);
		return 1;
	}
	if (lvl >= 30 && lvl <= 100 && arg=="sheng" )
	{
		if ((int)me->query("jing")<30)
		{
			me->unconcious();     
			return 0;
		}
		me->receive_damage("jing", 30);
		me->improve_skill("claw", (me->query("int"))*3/2);
		write(HIR"你攀住大绳，手爪上使力向上，直到鹰下，你仰望神鹰体态，只觉对爪法颇有领悟。\n"NOR);
		return 1;
	}
}

