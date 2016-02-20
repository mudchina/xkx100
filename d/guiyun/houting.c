// Room: /d/guiyun/houting.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","后厅");
	set("long",@LONG
这是归云庄的后厅。也是庄主处理家中私事的地方。东边是一间书
房，入口处放着一扇大屏风；西面则是主人的卧房。
LONG
);
	set("exits",([
		"east"  : __DIR__"shufang",
		"west"  : __DIR__"wofang",
		"north" : __DIR__"zoulang3",
	]) );
	set("objects",([
		__DIR__"npc/yahuan" : 1,
	]));  
	setup();
	replace_program(ROOM);
}
