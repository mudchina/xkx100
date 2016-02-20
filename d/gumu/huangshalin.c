// huangshalin.c
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_move(string arg);

void create()
{
	set("short", "黄沙岭");
	set("long", @LONG
此处位於终南山西部。只见远处王曲原上，孤立着一座由荒沙堆积
而成的山岭，波纹为奇特。据当地人说，这是在商朝，一位名叫陆亚仙
的人，用法力遣来一股黄沙而成。往东是一片密林。
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"east" : __DIR__"mumen",
	]));
	set("coor/x", -3230);
	set("coor/y", 30);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
