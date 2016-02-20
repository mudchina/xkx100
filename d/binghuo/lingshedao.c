// Room: /binghuo/lingshedao.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "灵蛇岛海滩");
	set("long", @LONG
这是个树木葱翠的大岛，岛上奇峰挺拔，耸立着好几座高山。岛
西端山石直降入海，并无浅滩，往来船只近岸泊就。
LONG );
	set("outdoors", "lingshe");
	set("exits", ([
		"east"  : __DIR__"lingsheroad1",
	]));
	set("objects", ([
		__DIR__"npc/yinli" : 1,
	]));
	setup();
	replace_program(ROOM);
}

