// Room: /wuliang/jianhugong.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "剑湖宫");
	set("long", @LONG
剑湖宫高居剑湖之侧，隔着剑湖，遥遥对着无量玉壁。这里是无
量剑掌门人日常起居之所。
LONG );
	set("exits", ([
		"southdown"  : __DIR__"road4",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));
	set("coor/x", -71000);
	set("coor/y", -79870);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}