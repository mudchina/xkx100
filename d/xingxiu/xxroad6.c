// Room: /d/xingxiu/xxroad6.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "山间平地");
	set("long", @LONG
山间平地，地上是嫩绿的小草，周围布了几棵桦树，山边有一眼清
泉。草地上树着几个毒僵尸，显是星宿弟子练功所用。
LONG );

	set("resource/water", 1);
	set("objects", ([
		__DIR__"npc/obj/yangrou" : 3,
		__DIR__"npc/dujiangshi" : 5
	]));
	set("exits", ([
	    "south" : __DIR__"xxroad5",
	]));
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	set("coor/x", -51000);
	set("coor/y", 20130);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
