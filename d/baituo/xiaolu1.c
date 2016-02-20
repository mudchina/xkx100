// Room: /d/baituo/xiaolu1.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是一条上山的小路。小路两边杂草丛生，看来少有行人。不过
路泥却甚是平滑，倒象常有人来往一般。你不禁有点犹豫。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"northup"   : __DIR__"xiaolu2",
		"southwest" : __DIR__"dongjie",
		"northeast" : __DIR__"fendi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -49970);
	set("coor/y", 19990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
