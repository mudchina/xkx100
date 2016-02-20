// /d/shenlong/zhulin1 竹林1
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
面前是一片翠绿的竹林，这儿安静多了，一阵凉风吹过，竹叶沙沙
作响。偶尔有几个人走过，都诚惶诚恐的样子，你不由得倒吸了一口凉
气，把挂在嘴边的话又咽了回去。南面是一个竹房，北面又是一片竹林，
东面是一所竹堂。
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"west"  : __DIR__"shibanlu",
		"enter" : __DIR__"qianlong",
		"south" : __DIR__"yaofang",
		"north" : __DIR__"zhulin2",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/yin" : 1,
	]));
	setup();

	replace_program(ROOM);
}
