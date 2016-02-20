// Room: /d/fuzhou/biaojunz.c
// Date: may.12 1998 Java

inherit ROOM;

void create()
{
	set("short", "内宅");
	set("long", @LONG
福威镖局内宅装点的十分华贵。花梨木桌上放着一尊精致的振鬃长
嘶的玉马，右首太师椅上好大一张豹皮把整张椅子遮得严严实实。
LONG );
	set("exits", ([
		"east"  : __DIR__"biaojuzt",
	]));
	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));
	set("coor/x", 1829);
	set("coor/y", -6297);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
