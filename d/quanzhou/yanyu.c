// Room: /d/quanzhou/yanyu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "万国烟雨楼");
	set("long", @LONG
「人道不思归，烟雨伴君眠」，傍湖而建，情趣盎然的万国烟雨楼
名虽酒楼，实是远近闻名的一景。楼分两层，一进大门，即可见园林中
亭台楼榭，假山流水，一池碧水，荷藕映红。环池漫步，客房绵延。
LONG );
	set("exits", ([
		"west"   : __DIR__"road2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("coor/x", 1870);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
