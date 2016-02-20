// Room: /d/huanggong/ciningmen.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "慈宁门");
	set("long", @LONG
这是皇宫中太后起居宫院慈宁宫的院门. 门内是个小院, 院里小花
园里有个荷花塘, 后面连着慈宁宫. 
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([
		"east"     : __DIR__"longzongmen",
		"west"     : __DIR__"dao8",
		"north"    : __DIR__"cininggong",
		"south"    : __DIR__"bukufang",
	]));
	set("objects", ([
		__DIR__"npc/dongjinkui" :1,
	]));
	set("coor/x", -220);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}