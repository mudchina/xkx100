// Room: /d/yanziwu/path21.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山涧小路");
	set("long", @LONG
小路穿过蔓陀峰下的山涧，两侧时而有流水滑落，把地上的路石染
成淡淡的绿色。山崖上是郁郁葱葱的松柏林，抬头仰望，时有飞鸟越顶
而过。北边是一片巨岩，光秃的，在万顷湖光和周遭碧青山色环绕下，
好似一丸巨大的珍珠。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"east"   : __DIR__"path22",
		"enter"  : __DIR__"dong7",
	]));
	set("coor/x", 1200);
	set("coor/y", -1270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}