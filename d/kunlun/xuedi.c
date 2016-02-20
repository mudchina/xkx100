// Room: /d/kunlun/xuedi.c
// Last Modified by winder on Jun. 29 2001
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "雪地");
	set("long", @LONG
雪地中央有个大雪堆，这大雪堆是农家积柴的草堆。这天寒地冻的
隆冬严寒里，尸体不会腐臭，天上有一头兀鹰在空中盘旋了几个圈子，
寻找机会以便飞下来啄食。
LONG );
	set("outdoors", "hongmei");
	set("exits", ([
		"south" : __DIR__"kekexili",
	]));
	set("objects", ([
		"/clone/misc/corpse" : 1,
	]));
	set("coor/x", -100000);
	set("coor/y", 20010);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
