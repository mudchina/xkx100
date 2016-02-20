// Room: /d/hengshan/yuyang.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "玉羊游云");
	set("long", @LONG
在东峰峭壁崖顶上，白石累累，散布有致，在云雾拂动下，似有动
感，象正在吃草的羊只。这就是和“金鸡报晓”齐名的恒山胜景“玉羊
游云”。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"westdown"    : __DIR__"beiyuedian",
	]));
	set("outdoors","hengshan");
	set("no_clean_up", 0);
	set("coor/x", 40);
	set("coor/y", 3180);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}

