// Room: /d/yanziwu/hongxia2.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"红霞二楼"NOR);
	set("long", @LONG
红霞楼上陈设淡雅有致。一幅中堂绘的是一丛盛开的茶花，两旁一
副木联，写的是：“春沟水动茶花白，夏谷云生荔枝红”。
LONG );
	set("exits", ([
		"down"     : __DIR__"hongxia1",
	]));
	set("objects", ([
		__DIR__"obj/chahua14" :1,
		__DIR__"npc/xiaoming" :1,
	]));
	set("coor/x", 1250);
	set("coor/y", -1250);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}