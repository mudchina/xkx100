// Room: /d/lingxiao/meiroad2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void init();
int pick(string);
void create()
{
	set("short","梅道");
	set("long",@LONG 
这也是一条充满梅花清香的小道。与殿外不同的是，这儿种满了梅
树，而且全是如鲜血般灿烂的红梅，花瓣片片飘落，落到洁白的雪地上，
就如一个温婉和顺的美人，在给自己的心上人刺绣时，不小心刺破了手
指而流出的一滴血，浸到了白绢上一样。一只通体雪白的雪鹤在地上翩
然起舞，逍遥自得。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"stone",
		"east"  : __DIR__"meiroad1",
	]));
	set("objects", ([
		__DIR__"npc/xuehe" : 1,
		__DIR__"obj/ban" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
}

void init()
{
	add_action("do_pick","pick");
}

int do_pick(string arg)
{
	object ob, me = this_player();

	if (!arg || arg!="hua" && arg!="flower")
		return notify_fail("你要摘什么？\n");
	ob=new(__DIR__"obj/mei");
	ob->move(me);
	message_vision("$N从路旁的树上摘了一朵"+ob->query("name")+"。\n"NOR,me);
	return 1;
}

