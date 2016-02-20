// Room: /yangzhou/ninghaiqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","宁海桥");
	set("long",@LONG
宁海桥是一座新建的联拱石桥，座落在小秦淮河上，是连接扬州新
旧两城的要道，因此修的极为宽阔平整，可供四辆马车同时并行。桥名
由欧阳修亲笔题写，悬在桥的两侧。桥的东南边有一个码头，许多船只
停靠着。西边是扬州旧城的甘泉街。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"ganquanjie",
		"east"  : __DIR__"matou",
	]));
	set("objects", ([
		SHOP_DIR"hesanqi" : 1,
		"/d/village/npc/kid" : random(5),
	]));
	set("coor/x", 30);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
