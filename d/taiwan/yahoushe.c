// Room: /d/taiwan/yahoushe.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "雅猴社");
	set("long", @LONG
雅猴社又称阿猴社，乃得名自西拉雅平埔族马卡道支族阿侯社之社
名音译。马卡道族原生活于打狗社，明未清初时，因汉人入垦，只得弃
地东迁，另行建社，是为雅猴社。
LONG );
	set("exits", ([
		"west" : __DIR__"dagougang",
	]));
	set("objects", ([
		__DIR__"npc/makadaoman": 1,
		__DIR__"npc/makadaowoman": 1,
		__DIR__"npc/makadaokid": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2520);
	set("coor/y", -7070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

