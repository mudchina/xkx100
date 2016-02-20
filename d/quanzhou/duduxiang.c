// Room: /d/quanzhou/duduxiang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "都督巷");
	set("long", @LONG
这是泉州的一条小巷，清净整洁。远远可见巷底红墙高砌，把守森
严，显然不是普通的住家。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"west" : __DIR__"northroad3",
		"east" : __DIR__"dudufu",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 1860);
	set("coor/y", -6500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
