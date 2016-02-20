// Room: /beijing/di_anmen.c

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "地安门");
	set("long", @LONG
这里就是地安门广场，灰色的城墙给人以庄严肃穆之感，再往南就
是皇宫后门。门前有座小桥，一条护城河绕城而过。越过小桥向南望去，
紫禁城的轮廓益发显得雄伟高大。一条笔直的大道横贯东西，东边是地
安门东街，西边是地安门西街。北边通往安定门。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west"  : __DIR__"di_an3",
		"east"  : __DIR__"di_an2",
		"south" : __DIR__"hbridge",
		"north" : __DIR__"anding",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -190);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
