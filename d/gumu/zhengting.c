// zhengting.c 正厅
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "正厅");
	set("long", @LONG
这里是古墓的正厅，本来应该停放灵柩棺木之类的东西，却不知道
被人般到哪里去了。厅正中端摆着一张大石椅，厅角上摆放着一些石头
做成的橱柜，中间是一张大石桌。
LONG	);
	set("exits", ([
		"west"  : __DIR__"mudao15",
		"east"  : __DIR__"mudao14",
		"north" : __DIR__"mudao11",
		"south" : __DIR__"mudao16",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", -40);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

