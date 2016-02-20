// Room: /d/yanziwu/path19.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山涧小路");
	set("long", @LONG
小路穿过蔓陀峰下的山涧，两侧时而有流水滑落，把地上的路石染
成淡淡的绿色。山崖上是郁郁葱葱的松柏林，抬头仰望，时有飞鸟越顶
而过。北望下山路，下面是一块不大的草坪。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"qingfeng",
		"southdown" : __DIR__"path20",
		"westup"    : __DIR__"qiuyu",
	]));
	set("coor/x", 1200);
	set("coor/y", -1260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}