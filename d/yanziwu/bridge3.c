// Room: /d/yanziwu/bridge3.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "十二回栏");
	set("long", @LONG
十二回栏是一座通往莲韵塘中倦心亭的十二曲桥。桥墩和栏杆均为
石砌，桥面却是圆木铺张着。透过数指宽的木间隙，可以看到桥下清清
的水、红红的荷、和跳动着的蛙。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"path16",
		"south"  : __DIR__"juanxin",
	]));
	set("coor/x", 1220);
	set("coor/y", -1210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}