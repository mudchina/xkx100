// Room: /d/suzhou/xidajie2.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
你走在西大街上，感到这里的街面要比别处的干净、整洁。大概因
为靠近衙门、兵营可受保护的缘故，富人们都喜欢住在这里。东边静悄
悄地没有几个行人，西边是西城门通往郊外。南边是玄妙观，北边是一
个书堂。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"xidajie1",
		"west"      : __DIR__"ximen",
		"north"     : __DIR__"shuchang",
		"south"     : __DIR__"xuanmiao",
	]));
	set("coor/x", 830);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
