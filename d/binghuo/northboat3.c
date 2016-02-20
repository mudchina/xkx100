// Room: /binghuo/northboat3.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "破帆船");
	set("long", @LONG
帆船这时只剩后帆吃风，那船歪斜倾侧，在海面上狂舞乱跳，后
桅向左横斜，帆边已碰到水面。船上水手全给海浪卷走了！周围漆黑
一团，船身格格格的响个不停，随时都能碎裂。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

