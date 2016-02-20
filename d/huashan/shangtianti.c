// shangtianti.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "上天梯");
	set("long", @LONG
此处绝险，必须面壁挽索，贴身探足前进，步不登高，故名“上天
梯”。北面是下山的路，往南面是金锁关。西面上去可以通达北峰云台
峰。
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"westup"    : __DIR__"canglong",
		"southup"   : __DIR__"jinsuo",
		"northdown" : __DIR__"husun",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");
	set("coor/x", -870);
	set("coor/y", 210);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
