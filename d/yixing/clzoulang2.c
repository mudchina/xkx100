// /d/yixing/clzoulang2.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里往来的人少了些，西面不断传来阵阵吵闹之声，有时还夹杂着
怒骂和尖叫。空中弥漫着烟酒的气味。地上显得甚是肮脏，抛弃着一些
油腻的残羹剩菜。
LONG );
	set("exits", ([
		"east"  : __DIR__"clhuayuan",
		"west"  : __DIR__"clxiaowu",
		"south" : __DIR__"clzoulang1",
		"north" : __DIR__"clxiaoting",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yixing");
	setup();

	replace_program(ROOM);
}

