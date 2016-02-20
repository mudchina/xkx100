// Room: /d/5lt/jiulou1.c

inherit ROOM;

void create()
{
	set("short", "悦华酒楼");
	set("long", @LONG
这里就是村里最豪华的悦华酒楼，宽敞明亮的大厅高朋满座，小二
哥满头大汗地招呼着所有嘉宾，不时传来阵阵欢歌笑语......
LONG );
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"sroad1",
		"up"   : __DIR__"jiulou2",
	]));
	set("coor/x", -160);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

