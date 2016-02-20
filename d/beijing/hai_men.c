// /beijing/hai_men.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","海澄公府门");
	set("long", @LONG
这是一所巨宅，巨宅的大门紧紧关闭着，门上挂着一块大匾，匾上
写着“海澄公府”四个大字，虽然和鹿鼎公府同是公爵府，可是大小、
派头却大不相同，大门匾额上那“海澄公府”四字是黑字，一点也不起
眼。
LONG );
	set("exits", ([
		"east"  : __DIR__"xidan1",
		"south" : __DIR__"hai_dayuan",
	]));

	set("no_clean_up", 0);
	set("coor/x", -230);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
