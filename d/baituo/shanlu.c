// Room: /d/baituo/shanlu.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","山路");
	set("long", @LONG
这里是山上的泥路。四周是密密的丛林，偶有兽鸟踪迹。东南边一
条蜿蜒的小路通往山下的村庄。
LONG	);
	set("exits",([
		"northwest" : __DIR__"shanlu1",
		"southeast" : __DIR__"guangchang",
	]));
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set("coor/x", -50020);
	set("coor/y", 20000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
