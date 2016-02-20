// Room: /d/baituo/houyuan.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","后院");
	set("long", @LONG
这是僻静的后院，住着『欧阳克』的老奶妈『张妈』。由于年岁已
高，她已经不干活了，在这里静养。
LONG	);
	set("exits",([
		"southeast" : __DIR__"zhuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		__DIR__"npc/zhangma" : 1,
	]));
	set("coor/x", -50020);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

