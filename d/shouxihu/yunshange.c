// Room: /yangzhou/yunshange.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","云山阁");
	set("long",@LONG
云山阁，面南五楹，阁高于地面不及一丈，中间设台阶上下，外中
柱悬挂书魏嘉瑛联(lian)。
LONG );
	set("item_desc", ([
		"lian" : HIG"
        槛        阁
        前        外
        春        秋
        色        声
        长        蜀
        堤        岭
        柳        松
\n"NOR,
	]));

	set("exits", ([
		"south"     : __DIR__"lianxingsi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 70);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}