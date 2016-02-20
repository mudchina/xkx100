// Room: /d/qilian/bulangpo2.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "不狼坡");
	set("long", @LONG
山势越来越凶险，遍是齐腰杂草，连山狼也不便行动，唯见山野兔
和几只苍鹰翱翔於空。往西北四十余里，可遥见一岭，蜿蜒连绵数百里，
满眼翠绿，名大通岭。
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"northwest" : __DIR__"datongling",
		"southdown" : __DIR__"bulangpo1",
	]));
	set("objects", ([
		"/d/wudang/npc/yetu": 2,
	]));
	set("coor/x", -9900);
	set("coor/y", 2900);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}