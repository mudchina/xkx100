// mudao15.c 墓道
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"墓道"NOR);
	set("long", @LONG
这里是古墓中的墓道，四周密不透风，借着墙上昏暗的灯光，你能
勉强分辨出方向。墙是用整块的青石砌合起来的，接合得甚是完美，难
以从中找出一丝缝隙。灯光照在青石壁上，闪烁着碧幽幽的光点。
LONG	);
	set("exits", ([
		"east" : __DIR__"zhengting",
		"west" : __DIR__"woshi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3210);
	set("coor/y", -40);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
