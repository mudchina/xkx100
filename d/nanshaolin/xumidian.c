// Room: /d/nanshaolin/xumidian.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", CYN"须弥殿"NOR);
	set("long", @LONG
一间宽敞的佛殿四壁空荡荡的，正中是一张青石屏风，绘有一座
高耸入云的险峰，白云缭绕，峰脚下则是一枚芥子。想是取佛家须弥
芥子之典故，佛法修为可将须弥之巨容入芥子之中。屏风前摆着几个
蒲团，几位僧人正自对着屏风反睛内视，勤修内功。
LONG );
	set("exits", ([
		"east" : __DIR__"dabeidian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
}

void init()
{
	this_player()->set_temp("ns_times", 10);
	add_action("do_neishi", "neishi");
}

int do_neishi()
{
	object ob, me = this_player();
	int lvl = me->query_skill("force", 1), exp = me->query("combat_exp");

	me->add_temp("mx_times", -1);	
	message_vision("$N盘膝坐下闭目垂帘意守丹田修炼内功。\n", me);
	if ((int)me->query("jing")<20)
	{
		write(RED"你太累了精力无法集中。\n"NOR);
		return 1;
	} 
	if (lvl >= 30 && lvl <= 100 && present("xisui", me) )
	{
		me->receive_damage("jing", 20);
		me->improve_skill("force", me->query("int"));
		tell_object(me, RED"你内视静想一股内息自曲骨，中极，关元，石门直通而上。\n经过一个小周天运行贮于气海膻中。\n"NOR);
	}
	else tell_object(me,RED"你越想越糊涂，内息乱窜，只好站起身来。\n"NOR);
	return 1;
} 

int valid_leave(object me, string dir)
{
	if(me->query_temp("mx_times") >= 0 ) me->delete_temp("mx_times");
	return ::valid_leave(me, dir);
}
