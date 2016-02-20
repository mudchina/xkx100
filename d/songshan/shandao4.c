// Room: /d/songshan/shandao4.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "嵩岳山道");
	set("long", @LONG
你走在嵩岳山道，青松翠柏，山风岚雾，时来飘荡。远望山下犬吠
鸡啼，顿起仙凡之感。
LONG );
	set("exits", ([
		"northup"   : __DIR__"fawangsi",
		"southeast" : __DIR__"songyuesi",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/zhang": 1,
	]));
	set("outdoors", "songshan");
	set("coor/x", -30);
	set("coor/y", 800);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
