// Room: /wuliang/road3.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG
这里是剑湖宫内的甬道。东通正厅，西面是通往后山的小路。甬
道廊檐边看下去，就是无量山景形胜了。
LONG );
        set("outdoors", "wuliang");
	set("exits", ([
		"west"  : __DIR__"road5",
		"east"  : __DIR__"zhengting",
	]));
	set("objects", ([
		__DIR__"npc/yu" : 1,
	]));
	set("coor/x", -71010);
	set("coor/y", -79890);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}