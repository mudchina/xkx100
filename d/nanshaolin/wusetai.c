// Room: /d/nanshaolin/wusetai.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIG"无色台"NOR);
	set("long", @LONG
这里是无色禅师的灵台内部，灵室显得十分空旷。正中有一张灵案
(lingan)，上书“洛钟东应”四个大字，乃是无色大师生前亲手所书。
笔势遒劲，大舒大展如同一套极高明的拳法。虽然置身暗室，你却觉的
灵台一片空明，似有光芒自心底发出。
LONG );
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_study","study");
}
int do_study(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("cuff", 1), exp = me->query("combat_exp");
	if (arg!="lingan") return 0;
	if (!living(me)) return 0;
        message("vision", me->name()+"正在专心的学习灵案上的书法。\n", environment(me), ({me}) );
	if (lvl < 30)
	{
		write(HIR"你看着案上的书法，心中似有所悟，但毕竟拳法修为尚浅，什么也没领悟到。\n"NOR);
		return 1;
	}
	if (lvl * lvl * lvl / 10 < exp)
	{
		write(HIR"你看着案上的书法，心中似有所悟，但毕竟经验尚浅，什么也没领悟到。\n"NOR);
		return 1;
	}
	if (lvl > 100)
	{
		write("你已尽数领悟透了案上书法的含义。\n");
		return 1;
	}
        if (lvl >= 30 && lvl <= 100 && arg=="lingan" )
	{
		if ((int)me->query("jing")<30)
		{
			me->unconcious();     
			return 0;
		}
		me->receive_damage("jing", 30);
		me->improve_skill("cuff", (me->query("int"))*3/2);
		write("你看着案上那笔走龙蛇般的大字，对基本拳法有所领悟。\n");
		return 1;
	}
}

