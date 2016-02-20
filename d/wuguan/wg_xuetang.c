// wg_xutang.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "学堂");
	set("long", @LONG
这里是武馆内的一个小学堂，堂内阵阵朗朗读书声，一个先生在这
里认真的教着，这里放满了桌子和椅子。
LONG);
	set("exits", ([
		"west" : __DIR__"wg_shilu-1",
	]));
	set("objects", ([
		__DIR__"npc/wg_fang" : 1,
		__DIR__"npc/wg_hengshandizi" : 1,		
	]) );
	set("coor/x", 51);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


