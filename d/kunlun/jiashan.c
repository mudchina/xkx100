// Room: /d/kunlun/jiashan.c
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "假山");
	set("long", @LONG
穿过了九曲廊就到了这里，黄色的山拔地而起，山峰俊俏，山间古
柏，山顶小亭，山中还有小院、石桥、石室等，气势磅礴。为江南山石
中所少见。
LONG );
	set("exits",([
		"east"      : __DIR__"qishi",
		"west"      : __DIR__"houting",
		"southwest" : __DIR__"jiuqulang5",
		"northwest" : __DIR__"huayuan",
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119980);
	set("coor/y", 40120);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}