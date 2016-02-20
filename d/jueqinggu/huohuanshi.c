// Room: /d/jueqinggu/huohuanshi.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "火浣室");
	set("long", @LONG
这是一座烧砖瓦的大窑，越过砖壁，炽热更盛，两名粗工正在搬堆
柴炭，两人上身赤膊，下身只穿一条牛头短裤，兀自全身大汗淋漓。
LONG
	);

	set("exits", ([
		"west" : __DIR__"huilang1",
		"enter" : __DIR__"huohuanshi1",
	]));
	set("objects", ([
		__DIR__"npc/puren" : 1,
	]));
	set("coor/x", -540);
	set("coor/y", -370);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}

