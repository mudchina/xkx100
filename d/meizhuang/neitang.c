// /d/meizhuang/neitang.c
// Last Modified by winder on Apr. 10 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "偏房"); 
	set("long", @LONG
这是一间没有任何东西的房子，四壁空荡荡的，好象是一间刚修好
的，还没有来得及进行装饰的房间，正中的墙似乎连石灰浆都没有涂抹
好，胡乱贴了几张不知是谁的画稿。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"senlin1",
	]));

	set("no_clean_up", 0);
	set("item_desc", ([
		"wall": "一壁新墙。\n"
	]) ); 
	set("coor/x", 3490);
	set("coor/y", -1400);
	set("coor/z", 10);
	setup();
}
void init()
{
	add_action("do_push", "push");
}
int do_push(string arg)
{
	string dir;
	object me=this_player();

	if( !arg || arg=="" ) {write("你想推什么？\n");return 1;}

	if( arg=="wall" || arg=="墙" )
	{
		write("你使劲推了一下那堵新墙，墙壁居然悄然旋开。\n");
		if((int)me->query_skill("force",1)>=100)
		{
			write("顺着墙壁旋开的夹缝，你进到里面的密室。\n");
			me->move(__DIR__"mishi");
			return 1;
		}
		write("你试着推了一下墙壁，但什么都没有发生。\n");

		me->add("jing",-10);
		me->add("qi",-10);
		return 1;

	}
}
