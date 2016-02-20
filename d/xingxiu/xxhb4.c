// Room: /d/xingxiu/xxhb4.c
// Last Modified by Winder on Apr. 25 2001

inherit ROOM;
void create()
{
	set("short", "海边荒路");
	set("long", @LONG
一条崎岖的小路，东面是方圆几百里，一望无际的星宿海，靠西是
一片山石。这里荒无人烟，寒风凛冽。枯树败草间，不时有毒虫出没。
你感到有点乏力，歇了一口气再往前走。
LONG);
	set("exits", ([
		"east"   : __DIR__"xxhb2",
		"westup" : __DIR__"shanshi",
	]));
	set("objects", ([
		__DIR__"npc/boshou"  : 1,
		__DIR__"npc/xxdizi" : 1,
	]));
	set("outdoors", "xingxiu");
	set("coor/x", -50200);
	set("coor/y", 20400);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

