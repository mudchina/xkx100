// Room: /d/quanzhou/portroad4.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "港口路");
	set("long", @LONG
这是用大块花岗石铺成的宽敞大道，平坦结实。路上马车都拉着沉
重的货物南来北往。不少马队都有镖师保护，看来都是价值不菲的货物。
南边是安海港，东边是船坞，东南边则是永宁港。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"east"      : __DIR__"chuanwu",
		"south"     : __DIR__"anhaigang",
		"northwest" : __DIR__"portroad3",
		"southeast" : __DIR__"yongninggang",
	]));
	set("objects", ([
		"/d/taishan/npc/tangzi" : 1,
		__DIR__"npc/kuli" : 2,
	]));
	set("coor/x", 1860);
	set("coor/y", -6620);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
