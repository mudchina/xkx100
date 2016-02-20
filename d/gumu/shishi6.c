// Room: /d/gumu/shishi6.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIC"石室"NOR);
	set("long", @LONG
室中也无特异之处，你抬头仰望，但见室顶密密麻麻的写满了字迹
符号，你看了一会，但觉奥妙难解。室顶西南角绘著一幅图，似与武功
无关，凝神细看，倒像是幅地图。石室右下方好象可以往下(down)走。
LONG	);
	set("item_desc", ([
		"down" : HIB"黑乎乎的，看不真切。\n"NOR,
	]));
	set("exits", ([
		"up" : __DIR__"shiguan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3000);
	set("coor/y", -40);
	set("coor/z", 60);
	setup();
}

void init()
{
	add_action("do_look", "look");
	add_action("do_look", "kan"); 
	add_action("do_walk", "walk");
	add_action("do_walk", "zou");
}

int do_look(string arg)
{
	object me=this_player();

	if ( arg =="map")
	{
		write(HIY"你凝望著那幅图，心中不由大喜，原来那绘的正是出墓的秘道。\n"NOR);
		me->set_temp("map", 1);
		return 1;
	}
	return notify_fail("你要看什么？\n");
}

int do_walk(string arg)
{ 
	object me=this_player();

	if ( arg =="down")
	{
		if(!me->query_temp("map"))
			return notify_fail("你伸脚想往下走，但是犹豫再三，又伸回了脚。\n");
		write(HIM"你东转西弯，越走越低。同时脚下渐渐潮湿，暗中隐约望去，到处都是\n岔道。再走一会，道路奇陡，竟是笔直向下。下降了约莫半个时辰，这\n路渐平了，只是湿气却也渐重，到后来更听到了淙淙水声，路上水没至\n踝。越走水越高，自腿而腹，渐与胸齐。\n"NOR);
		me->delete_temp("map");
		me->move(__DIR__"anhe1");
		return 1;
	}
	return notify_fail("你在石室里踱来踱去，不知如何是好？\n");
}
