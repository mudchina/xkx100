// Room: /d/kunlun/huayuan1.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "花园");
	set("long",@long
这里是昆仑派的花园。廊边花木扶疏，竹影参差，山泉急湍，竟然
富有江南园林的情趣。西面是静修室。
long);
	set("exits",([
		"north" : __DIR__"jiuqulang1",
		"south" : __DIR__"shilu1",
		"west"  : __DIR__"jingxiushi",
		"east"  : __DIR__"lianwu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40080);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}