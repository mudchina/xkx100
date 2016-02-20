// Room: /d/baituo/xiaolu3.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是一条上山的小路。小路两边杂草丛生，看来少有行人。不过
路泥却甚是平滑，倒象常有人来往一般。听说东北方有山贼出没，要格
外小心。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"northeast" : __DIR__"xiaolu4",
		"southdown" : __DIR__"xiaolu2",
	]));
	set("objects",([
		__DIR__"npc/shanzei1" : 1,
	]));
	set("coor/x", -49970);
	set("coor/y", 20010);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
