// Room: /heizhao/shanlu8.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你继续循着陡路上岭，道路已经十分狭窄，有些地方根本认不
出是路了。路旁山峰插天，山风翠树甚是清幽。
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"shanlu7",
		"westup"    : __DIR__"shanlu9",
	]));
	set("coor/x", -5010);
	set("coor/y", -1290);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}