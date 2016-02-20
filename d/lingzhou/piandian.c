// Room: /d/lingzhou/piandian.c

inherit ROOM;

void create()
{
	set("short", "偏殿");
	set("long", @LONG
这里是后宫边上的偏殿，虽然不大却很整齐，有几把椅子和一张桌
子，是侍女们休息的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"garden",
		"east" : __DIR__"hougong",
	]));
	set("objects", ([
		__DIR__"npc/gongnu" : 2,
	]));
	set("coor/x", -17955);
	set("coor/y", 32120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
