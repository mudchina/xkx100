// Room: /binghuo/shulin4.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "大树林");
	set("long", @LONG
这里已近岛北，这岛方圆极广，延伸至北，不知尽头，走出二十
余里，只见一片浓密的丛林，老树参天，阴森森的遮天蔽日。
LONG );
	set("outdoors", "binghuo");
	set("exits", ([
		"southwest" : __DIR__"yuanye1",
	]));
	set("objects", ([
		__DIR__"npc/bear": 1,
	]));
	setup();
	replace_program(ROOM);
}

