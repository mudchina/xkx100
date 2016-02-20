// Room: /d/nanshaolin/kuhuiping.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",CYN"苦慧坪"NOR);
	set("long", @LONG
你心智一清原发现自己竟在一座崖壁之上，两面高岩中藏广壑，壑
底云气蒙蒙，其深无际。岩壁间横着几条羊肠野径，素无人踪。岩壁上
满生杂草藤蔓，地势异常险峻。苦慧禅师当年负气私自离寺出走，想是
自此密径离去，创下了西域少林一派。据说后世高僧已将密径堵绝，从
此处再无出路，只余当年苦慧攀过的蔓藤野径，留待后人。
LONG );
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));
	set("outdoors","nanshaolin");
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_pan","pan");
}
int do_pan(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("leg", 1), exp = me->query("combat_exp");
	if (arg!="teng") return 0;
	if (!living(me)) return 0;
	message("vision", me->name()+"双腿攀住了蔓藤，向野径爬去。\n", environment(me), ({me}) );
	if (lvl<30)
	{
		write(HIR"你腿上无力，只攀住一下变被摔脱。\n"NOR);
		return 1;
	}
	if (lvl * lvl * lvl / 10 < exp)
	{
		write(HIR"你经验不足，只攀住一下变被摔脱。\n"NOR);
		return 1;
	}
	if (lvl>100)
	{
		write(HIR"你双腿尚未攀到，身形已借腿力飘上了小径。\n"NOR);
		return 1;
	}
	if (lvl >= 30 && lvl <= 100&&arg=="teng" )
	{
		if ((int)me->query("jing")<30)
		{
			me->unconcious();
			return 0;
		}
		me->receive_damage("jing", 30);
		me->improve_skill("leg", (me->query("int"))*3/2);
		write(HIR"你双腿一纵已攀住了蔓藤，全身借腿力缓缓移向小径，你自觉腿力颇有精进。\n"NOR);
		return 1;
	}
}

