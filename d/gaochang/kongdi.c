// Room: /d/gaochang/kongdi.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "空地");
	set("long", @LONG
突然之间，眼前豁然开朗，出现一大片空地，空地尽头处又有两扇
铁门，嵌在大山岩中。
LONG
	);

	set("outdoors", "gaochang");
	set("exits", ([
		"north" : __DIR__"shulin14",
		"east" : __DIR__"shijie1",
	]));
	set("objects", ([
		__DIR__"npc/supu" : 1,
		__DIR__"npc/aman" : 1,
	]));
	set("coor/x", -37000);
	set("coor/y", 10000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}