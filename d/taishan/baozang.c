// Room: /d/taishan/baozang.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "宝藏岭");
	set("long", @LONG
这里是泰山的又一个名胜。岭上有一座状似狮子的巨石，称为狮子
崖。最出名的还是要数在东北面的东岳庙，也称上岳庙，是古代封禅的
地方，那里有一块唐玄宗的纪泰山铭。
LONG );
	set("exits", ([
		"northwest" : __DIR__"bixia",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", 760);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
