// hanshuitan.c 寒水潭
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_qian(string arg);

void create()
{
	set("short", "寒水潭");
	set("long", @LONG
这里是草地的边缘，青草已经很稀疏了，仍然有一二玉蜂来回地飞
过寻觅食物。你的面前是一个清波荡漾的大水潭 (tan)，阳光映照下，
水面泛起了一道七色彩虹，望着这般美景，你俗念尽消。
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"northwest" : __DIR__"caodi2",
	]));
	set("objects", ([
		__DIR__"npc/yufeng" : random(3),
	]));
	set("item_desc", ([
		"tan": "潭水很清，隐约可以见过水底的怪石嶙峋，一二游鱼倏地从水底游过，又不知道躲到哪块石头后面藏身去了。\n",
	]) );
	set("coor/x", -3200);
	set("coor/y", 30);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

