// Room: /d/quanzhou/portroad2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "港口路");
	set("long", @LONG
这是用大块花岗石铺成的宽敞大道，平坦结实。路上马车都拉着沉
重的货物南来北往。不少马队都有镖师保护，看来都是价值不菲的货物。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"south" : __DIR__"houzhu",
		"north" : __DIR__"portroad1",
	]));
	set("objects", ([
		"/d/taishan/npc/tangzi" : 1,
		"/d/taishan/npc/tiao-fu" : 1,
		__DIR__"npc/kuli" : 1,
		__DIR__"npc/langren" : 1,
	]));
	set("coor/x", 1880);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
