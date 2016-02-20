// Room: /d/quanzhou/portroad3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "港口路");
	set("long", @LONG
这是用大块花岗石铺成的宽敞大道，平坦结实。路上马车都拉着沉
重的货物南来北往。不少马队都有镖师保护，看来都是价值不菲的货物。
东北边是海外交通使节府，北边接着顺济桥。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"northeast" : __DIR__"shibosi",
		"southeast" : __DIR__"portroad4",
		"north"     : __DIR__"shunjiqiao",
	]));
	set("objects", ([
		"/d/taishan/npc/tangzi" : 2,
		"/d/fuzhou/npc/biaotou" : 1,
	]));
	set("coor/x", 1850);
	set("coor/y", -6610);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
