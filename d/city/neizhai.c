// Room: /city/neizain.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "内宅");
	set("long", @LONG
这里是衙门的内宅，住着知府的家眷。外人到此就该止步了。
LONG );
	set("exits", ([
		"south" : __DIR__"zhengtang",
	]));
	set("objects", ([
		__DIR__"npc/yuhuan" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 3);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}