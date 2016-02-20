// Room: /d/baituo/datiepu.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "打铁铺");
	set("long", @LONG
这里是一家打铁铺，铁匠忙着打制铁制兵器，卖给江湖侠客。
LONG	);
	set("exits", ([
		"north" : __DIR__"dongjie",
	]));
	set("objects",([
		__DIR__"npc/smith" : 1,
	]));
	set("coor/x", -49980);
	set("coor/y", 19970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
