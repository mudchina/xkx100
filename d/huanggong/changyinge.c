// changyinge.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "畅音阁");
	set("long", @LONG
这是宫内最大的戏台, 每逢年节和皇上生日, 帝皇后妃都来这里看
戏. 平日里偶尔太后也会来这点上几折子看看.
LONG
	);
	set("exits", ([
		"west"  : __DIR__"yangxin2",
		"south" : __DIR__"ningshougong",
	]));
	set("no_clean_up", 0);
	set("coor/x", -180);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}