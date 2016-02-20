// Room: /wuliang/road2.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG
这里是剑湖宫内的甬道。西通正厅，东面是个很大的花园。甬道
廊檐边看下去，就是无量山景形胜了。
LONG );
        set("outdoors", "wuliang");
	set("exits", ([
		"east"  : __DIR__"huayuan",
		"west"  : __DIR__"zhengting",
	]));
	set("objects", ([
		__DIR__"npc/wu" : 1,
	]));
	set("coor/x", -70990);
	set("coor/y", -79890);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}