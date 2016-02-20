// Room: /d/mingjiao/shanjiao.c
// Date: Java 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "昆仑山下");
	set("long", @LONG
这里是千里昆仑的东麓，远望苍天浩浩，白云悠悠。东方沃野千里，
楚天辽阔；西面高山巍巍，迤逦万里。叱咤武林八百年的明教就座落在
这群山之中。明教----是多少武林豪杰所向往的地方，在那里，有无数
生死相许的好兄弟，无论是正是邪。就在这西方的群山之后，等待着你
去谱写又一曲武林传奇。
LONG );
	set("exits", ([
		"west"      : __DIR__"tomen2",
		"east"      : __DIR__"gebitan5",
		"northwest" : "/d/kunlun/zhenyuanqiao",
	]));

	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", 800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}