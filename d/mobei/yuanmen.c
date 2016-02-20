// Room: /d/mobei/yuanmen.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "辕门");
	set("long", @LONG
辕门把兵营和居民帐篷分隔开来。原木的辕门边有守卫监视通行的
每一个人。两排旌旗迎风招展，一条直道向北通向铁木真的营帐。
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"buluo1",
		"north" : __DIR__"road1",
	]));
	set("coor/x", -210);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
