// /d/yixing/clxiaowu.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
这是帮众们酗酒赌钱的的小屋，正中的方桌上杯盘狼籍，有人醉倒
在一旁，不醒人事。隔扇后面另有一张赌桌，几个帮众正在吆五喝六地
赌钱。屋内烛光摇曳，似乎没有人注意你进来。
LONG );
	set("exits", ([
		"east" : __DIR__"clzoulang2",
	]));
	set("objects",([
		__DIR__"npc/cl_bangzhong3" : 1,
	]));
	set("resource/water", 1);
	setup();
	replace_program(ROOM);
}
