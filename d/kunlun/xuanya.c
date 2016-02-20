// Room: /d/kunlun/xuanya.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit ROOM;
int do_jump(string arg);
void create()
{
	set("short", HIY"悬崖"NOR);
	set("long", @LONG
你来到悬崖之上，突然在对而传来几声狼嗥，甚是凄厉可怖。只见
对面几只大灰狼仰起头，向着你张牙舞爪的嗥叫，想是要食之果腹，只
是之间有一条深不见底的万丈峡谷，无法过来。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"eastdown" : __DIR__"xschongling1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "hongmei");
	set("coor/x", -100030);
	set("coor/y", 20010);
	set("coor/z", 70);
	setup();
}
void init()
{
	add_action("do_jump","jump");
}
int do_jump(string arg)
{
        object me;
        me = this_player();
        if( arg=="down" &&me->query_kar()>=20)
        {
		if (me->query_skill("dodge",1)>=50)
		{
			message("vision", me->name() + "一个纵身，跳下了悬崖。\n", environment(me), ({me}) );
			write(HIR"\n你向下一跳，直向万丈深渊掉去！！！\n\n"NOR);
			write(HIR"\n你下落的速度太快，冲开弥漫之雾，直向下堕！！！\n\n"NOR);
			write(HIR"\n你只觉身旁风声虎虎，身子不断的向下摔落......\n偶尔见到峭壁上有树枝伸出，便想去抓，但下落之\n力太大，树枝喀喇的一声断了！！！\n\n"NOR);
			write(HIY"\n但，你的下落速度慢了一点，急忙使一招“乌龙绞柱”，牢牢的抱住了松树。\n\n"NOR);
        	        me->move(__DIR__"songshu");
                	message("vision", me->name() + "死死的抱住了这棵小松树。\n", environment(me), ({me}) );
		}
		else {
	                message("vision", me->name() + "一个纵身，跳下了悬崖。\n", environment(me), ({me}) );
			write(HIR"\n你向下一跳，直向万丈深渊掉去！！！\n\n"NOR);
			write(HIR"\n你下落的速度太快，冲开弥漫之雾，直向下堕！！！\n\n"NOR);
			write(HIR"\n你只觉身旁风声虎虎，身子不断的向下摔落......\n偶尔见到峭壁上有树枝伸出，便想去抓，但下落之\n力太大，树枝喀喇的一声断了！！！\n"NOR);
			write(HIR"\n                ."NOR);
			write(HIR"\n                ."NOR);
			write(HIR"\n                .\n\n"NOR);
                	me->move(__DIR__"xuedi");
		        me->unconcious();
       	        	message("vision", me->name() + "从悬崖上摔了下来。\n", environment(me), ({me}) );
		}
		return 1;
	}
	if( arg=="down" &&me->query_kar()<20)
        {
		if (me->query_skill("dodge",1)>=20)
		{
	                message("vision", me->name() + "一个纵身，跳下了悬崖。\n", environment(me), ({me}) );
			write(HIR"\n你向下一跳，直向万丈深渊掉去！！！\n\n"NOR);
			write(HIR"\n你下落的速度太快，冲开弥漫之雾，直向下堕！！！\n\n"NOR);
			write(HIR"\n你只觉身旁风声虎虎，身子不断的向下摔落......\n偶尔见到峭壁上有树枝伸出，便想去抓，但下落之\n力太大，树枝喀喇的一声断了！！！\n"NOR);
			write(HIR"\n                ."NOR);
			write(HIR"\n                ."NOR);
			write(HIR"\n                .\n\n"NOR);
        	        me->move(__DIR__"xuedi");
			me->unconcious();
	                message("vision", me->name() + "从悬崖上摔了下来。\n", environment(me), ({me}) );
		}
		else
		{
			message("vision", me->name() + "一个纵身，跳下了悬崖。\n", environment(me), ({me}) );
			write(HIR"\n你向下一跳，直向万丈深渊掉去！！！\n\n"NOR);
			write(HIR"\n你下落的速度太快，冲开弥漫之雾，直向下堕！！！\n\n"NOR);
			write(HIR"\n你只觉身旁风声虎虎，身子不断的向下摔落......\n偶尔见到峭壁上有树枝伸出，便想去抓，但下落之\n力太大，树枝喀喇的一声断了！！！\n"NOR);
			write(HIR"\n                ."NOR);
			write(HIR"\n                ."NOR);
			write(HIR"\n                .\n\n"NOR);
	                me->move(__DIR__"xuedi");
		        me->set_temp("last_damage_from", "跳下悬崖" + "摔");
			me->die();
        	        message("vision", me->name() + "从悬崖上摔了下来。\n", environment(me), ({me}) );
		}
		return 1;
	}
}

