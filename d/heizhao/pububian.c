// Room: /heizhao/pububian.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "瀑布岸边");
	set("long", @LONG
瀑布日夜奔流，年深月久，在岩石间切了一道深沟，约有二丈
来高。站在岸上，只见那瀑布奔腾而去，水沫四溅，不由得目眩心
惊，瀑布一泻如注，直冲入下面深渊去。岸边系着一只铁舟。
LONG );
	set("outdoors", "taoyuan");
	set("resource/water", 1);
	set("exits", ([
		"south" : __DIR__"xiaowu",
		"enter" : __DIR__"ironboat",
	]));
	set("coor/x", -5020);
	set("coor/y", -1260);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}