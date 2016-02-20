// Room: /d/songshan/songyueta.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "嵩岳寺塔");
	set("long", @LONG
嵩岳寺塔为密檐式砖塔，高达十余丈，外廓十二面，内室八方四门，
十五层密檐塔刹向上收紧，优美绝伦。
LONG );
	set("exits", ([
		"east" : __DIR__"songyuesi",
	]));
	set("objects", ([
		__DIR__"npc/dizi" :1,
	]));
	set("outdoors", "songshan");
	set("coor/x", -30);
	set("coor/y", 790);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
