// wg_zhangfang.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "帐房");
	set("long", @LONG
这里是武馆内的一个帐房，室内一个帐房先生在这里认真地做着帐。
武馆内的大小收支都在这里打理。
LONG);
	set("exits", ([
		"east" : __DIR__"wg_shilu-1",
	]));
	set("objects", ([
		__DIR__"npc/wg_fan" : 1,
		__DIR__"npc/wg_huashandizi" : 1,
	]) );
	
	set("coor/x", 31);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


