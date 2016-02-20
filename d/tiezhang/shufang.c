// Room: /d/tiezhang/shufang.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"书房"NOR);
	set("long", @LONG
这里是铁掌帮内的书房。自从上代帮主上官剑南仙逝后，这个书房
就少有人来。靠墙壁的书架上满是灰尘，窗户也被一块破帘子遮住一半
多，风刮着老动，也不见有多少光亮进来。
LONG	);
	set("exits", ([ 
		"south"      : __DIR__"zoulang2",
	]));
	set("objects", ([ 
		BOOK_DIR"spear_book" : random(2),
	]));
	set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -1950);
	set("coor/z", 30);
	setup();
	
}
