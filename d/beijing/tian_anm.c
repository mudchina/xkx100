// Room: /beijing/tiananmen.c

#include <room.h>

inherit ROOM;


void create()
{
	set("short", "天安门广场");
	set("long", @LONG
这里就是天安门广场，灰色的城墙给人以庄严肃穆之感，再往北就
是皇宫了。皇宫正门前有座小桥，一条护城河绕城而过。越过小桥向北
望去，紫禁城的轮廓益发显得雄伟高大。一条笔直的大道横贯东西，东
边是东长安街，西边是西长安街。南边是一条繁华的大道，从那往下有
一座天桥，据说游人很多。
LONG );
	set("exits", ([
		"south" : __DIR__"nandaj1",
		"north" : __DIR__"bridge",
		"west"  : __DIR__"xichang1",
		"east"  : __DIR__"dongcha1",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "beijing");
	set("coor/x", -200);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
