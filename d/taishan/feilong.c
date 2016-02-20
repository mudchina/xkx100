// Room: /d/taishan/feilong.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "飞龙涧");
	set("long", @LONG
斗母宫东有听泉山房及龙泉亭，供游人小憩赏景。亭下涧内“三潭
叠瀑”如龙飞舞，名飞龙涧。游人立于潭间，流水声似丝竹奏鸣。
LONG );
	set("exits", ([
		"northwest" : __DIR__"doumo",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 410);
	set("coor/y", 590);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
