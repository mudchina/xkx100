// Room: /d/quanzhou/liandanshi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "练胆石");
	set("long", @LONG
这是立崖上的一方窄石 (stone)，正处风口。人立其上，但觉狂风
撕扯，面如刀割，头晕目眩，摇摇欲坠。相传这是明朝抗倭英雄俞大猷
少年时的练胆石，上有他题刻的「恩重如山」四个字。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("item_desc", ([
		"stone" :"只见窄石耸立在崖上，任狂风暴哮始终不倒，你不禁感叹造物之奇。\n",
	]));
	set("exits", ([
		"eastdown"  : __DIR__"shanlu2",
		"northwest" : __DIR__"qianshouyan",
	]));
	set("coor/x", 1840);
	set("coor/y", -6410);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
