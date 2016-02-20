// Room: /d/huangshan/zuishi.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "醉石");
	set("long", @LONG
这是李白醉酒卧眠的醉石，石上一人形依稀可见，观其形状恰似酒
至酣处，石侧有醉石二字，笔力遒劲，边上立有牌坊一座，历代文人题
字皆在此处。由醉石继续南行便是试剑石。
LONG
	);
	set("exits", ([ 
		"west"      : __DIR__"shijian",
		"eastup"    : __DIR__"banshan",
		"northdown" : __DIR__"sandie",
		"southeast" : __DIR__"qingluan",
	]));
	set("objects", ([
		__DIR__"obj/stone2" : 1,
	]) );
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
