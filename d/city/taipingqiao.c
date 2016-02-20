// Room: /yangzhou/taipingqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","太平桥");
	set("long",@LONG
太平桥极为别致，桥对称二主拱，主拱间一小圆拱，两边各一肩拱，
富于不同一般的韵律。太平桥两侧围石栏板，间以望柱，中间镶石额「
太平桥」。太平桥横卧于官河之上，远望之如美人的两弯柳眉；明月当
空时，两拱之下各一月影，如美人之妙目顾盼流转，为扬州一奇景。当
此时，你不禁对所谓“天下三分明月夜，无奈二分在扬州”感触不已。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"caohenanjie",
		"east"  : __DIR__"nanmendajie",
	]));
	set("objects", ([
		__DIR__"npc/geji" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}