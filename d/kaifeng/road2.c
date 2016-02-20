// /kaifeng/road2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
这条横贯南北的街道是皇上出巡时的要道，北起宣德门南至南盈门，
两边店铺不断。街道东面是有名的稻香居。
LONG);
	set("no_clean_up", 0);
	set("outdoors", "kaifeng");
	set("exits", ([
		"north" : __DIR__"road3",
		"south" : __DIR__"zhuque",
		"west"  : __DIR__"gongyuan3",
		"east"  : __DIR__"daoxiang1",
	]));

	setup();
	replace_program(ROOM);
}
