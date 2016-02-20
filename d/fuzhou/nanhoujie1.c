// Room: /d/fuzhou/nanhoujie1.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "南后街");
	set("long", @LONG
街的两边行人熙熙攘攘，个个喜气洋洋。街的两旁店铺林立，真是
一个购物的好地方。街边建筑古朴，都有百年来历了，飞檐青瓦，看来
很有韵味。街面榕树参天，把阳光遮得严严实实的，真是不愧“榕城”
之名。西边是衣锦坊，东边通往杨桥巷。
LONG );

	set("exits", ([
		"east"  : __DIR__"yangqiaoxiang",
		"west"  : __DIR__"yijinfang",
		"south" : __DIR__"nanhoujie2",
		"north" : __DIR__"xidajie1",
	]));
	set("objects", ([
		"/d/village/npc/seller" : 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 1835);
	set("coor/y", -6310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
