// Room: /d/baituo/xiaolu2.c
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
		"northup"   : __DIR__"xiaolu3",
		"southdown" : __DIR__"xiaolu1",
	]));
	set("objects",([
		__DIR__"npc/man" : 1,
	]));
	set("coor/x", -49970);
	set("coor/y", 20000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
