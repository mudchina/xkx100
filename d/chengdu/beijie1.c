// Room: /d/chengdu/beijie1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。北边是北城门通向城
外。南边显得很繁华热闹。东边是一座两层的楼阁，挂着“陈麻婆豆腐”
的招帘，门额上悬挂一方横匾“麻到为止”四字擦得闪闪发亮，乃是苏
大胡子的手笔。阵阵辣椒香味扑鼻而来，让你垂涎欲滴。
    西南方有个如画的小潭。
LONG	);
	set("exits", ([
		"east"      : __DIR__"chenmapo",
		"north"     : __DIR__"beijie",
		"south"     : __DIR__"beijie2",
		"southwest" : __DIR__"huanhuaxi2",
	]));
	set("outdoors", "chengdu");
	set("coor/x", -8050);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


