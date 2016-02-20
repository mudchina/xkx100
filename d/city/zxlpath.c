// Room: /city/zxlpath.c
// YZC 1995/12/04 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "醉仙楼大堂");
	set("long", @LONG
这是醉仙楼大堂，来来往往的人客和跑堂小二，夹杂着三个宴会厅
刺耳的呼叫声，碰杯声，打闹声，赖酒声，热闹非凡。你在三个宴会厅
前打量着进哪个凑个热闹，蹭点白食。
    每月十五日晚间比武结束，店铺拍卖大会便在这里举行。届时，万
商云集，直欲一试高低。如果你想发财，可不要错过哦。
LONG);
	set("exits", ([
		"east"   : __DIR__"meigui",
		"north"  : __DIR__"furong",
		"south"  : __DIR__"mudan",
		"west"   : __DIR__"zuixianlou2",
	]));
        set("no_fight","1");
	set("no_beg", 1);
	set("coor/x", 21);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
	SHOP_DIR"situheng"->come_here();
}
