// /d/beihai/yuegu.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "阅古楼");
	set("long", @LONG
阅古楼平面为一马蹄形，有廊二十五楹，左右围抱。内有蟠龙升天
式楼梯。壁砌三希堂法帖 (tie)石刻。山坡上点缀假山、庭阁，高下曲
折有致，如亩鉴室、烟云尽态亭、水精域、甘露殿、蟠青室、揖山亭等。
LONG
	);
	set("item_desc", ([
		"tie" : "王羲之《快雪时晴帖》，王献之《中秋帖》，王徇《迫远帖》\n",
	]));
	set("exits", ([
		"southup"   : __DIR__"qingxiao",
		"northeast" : __DIR__"yilan",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 4100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
