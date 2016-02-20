// Room: /wuliang/huayuan.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
这是一个园子，庭院清幽，茶花争放，山石古拙，苍松翠竹，景
致煞是宜人。东面通往一间小屋，西边是一条长长的甬道通向正厅。
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"xiaowu",
		"west"  : __DIR__"road2",
	]));
	set("objects", ([
		"/clone/medicine/nostrum/mangguzhuha": random(2),
	]));
	set("coor/x", -70980);
	set("coor/y", -79890);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}