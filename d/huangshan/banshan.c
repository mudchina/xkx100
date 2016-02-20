// Room: /d/huangshan/banshan.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "半山寺");
	set("long", @LONG
黄山险峻，过去少有人烟，最早来此者多为出家苦修的僧人，所以
黄山之上寺庙甚多。半山寺就因为出了一位擅长山水的大画家“雪庄和
尚”而名声居众寺之首。至今寺内尚有其真迹留传。由半山寺西行下山
便是醉石，继续攀爬可去天都峰。
LONG
	);
	set("exits", ([ 
		"northup"   : __DIR__"guanyin",
		"westdown"  : __DIR__"zuishi",
		"southdown" : __DIR__"qingluan",
	]));
	set("outdoors", "huangshan");
	replace_program(ROOM);
	setup();
	replace_program(ROOM);
}
