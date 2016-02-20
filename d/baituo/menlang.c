// Room: /d/baituo/menlang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","门廊");
	set("long", @LONG
这是个门廊，门廊的飞檐上挂着一串串的小铜铃，在清风中发出清
脆动听的铃声。
LONG	);
	set("exits",([
		"north" : __DIR__"tangwu",
		"south" : __DIR__"liangong",
	]));
	set("objects",([
		__DIR__"npc/guanjia" : 1,
	]));
	set("outdoors","baituo");
	set("coor/x", -50010);
	set("coor/y", 20050);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

