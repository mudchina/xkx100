// Room: /d/suzhou/.c
// Last Modified by winder on Mar. 8 2001

inherit ROOM;

void create()
{
	set("short", "内宅");
	set("long", @LONG
这里是衙门的内宅，住着知府的家眷。外人到此就该止步了。
LONG
	);

	set("exits", ([
		"south" : __DIR__"yamen",
	]));
	set("no_clean_up", 0);
	set("coor/x", 840);
	set("coor/y", -995);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

