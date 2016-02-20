// Room: /wuliang/road6.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "后山小路");
	set("long", @LONG
走出十余里，已经到无量山峰的后山，只听得水声淙淙，前面有
条山溪。寻声来到溪旁，溪水清澈异常，远近地下撒满枯枝，脚步走
动，格格做响。
LONG );
        set("outdoors", "wuliang");
	set("exits", ([
		"south"   : __DIR__"road5",
		"northup" : "/d/xiaoyao/pubu",
	]));
	set("objects", ([
		__DIR__"npc/gan" : 1,
		__DIR__"npc/ge"  : 1,
	]));
	set("coor/x", -71020);
	set("coor/y", -79880);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}