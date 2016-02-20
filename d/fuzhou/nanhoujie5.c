// Room: /d/fuzhou/nanhoujie5.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "南后街");
	set("long", @LONG
街的两边行人熙熙攘攘，个个喜气洋洋。街的两旁店铺林立，真是
一个购物的好地方。街边建筑古朴，都有百年来历了，飞檐青瓦，看来
很有韵味。街面榕树参天，把阳光遮得严严实实的，真是不愧“榕城”
之名。东边通往安民巷，西边是光禄坊。
LONG );

	set("exits", ([
		"west"  : __DIR__"guanglufang",
		"east"  : __DIR__"anminxiang",
		"south" : __DIR__"nanhoujie6",
		"north" : __DIR__"nanhoujie4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "fuzhou");
	set("coor/x", 1835);
	set("coor/y", -6350);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
