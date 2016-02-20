// Room: /d/yanziwu/garden.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
这里是蔓陀山庄的花园，鸣莺啼柳，草碧花浓，果然是江南好春色。
尤其引人注目的是园中的几盆茶花，在大理虽非上品，在江南却委实难
得。一道溪水潺潺，自园中穿过，顺带聚出一弯小湖。
LONG );
	set("outdoors", "mantuo");
	set("exits", ([
		"north"  : __DIR__"yunjin1",
		"south"  : __DIR__"path4",
		"east"   : __DIR__"path5",
		"west"   : __DIR__"path25",
	]));
	set("objects", ([
		"/d/dali/obj/chahua1": 1,
	]));
	set("coor/x", 1230);
	set("coor/y", -1270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}