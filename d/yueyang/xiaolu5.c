// Room: /d/yueyang/xiaolu5.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "山中路");
	set("long", @LONG
你走在君山的山中小路上。君山，岛呈圆形，旁高中低，由七十二
峰组成，峰峰皆灵秀，处处尽清幽。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"xiaolu4",
		"southwest" : __DIR__"liuyijing",
	]));
	set("coor/x", -1680);
	set("coor/y", 2320);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
