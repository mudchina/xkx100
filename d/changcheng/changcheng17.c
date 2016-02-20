// Room: /d/changcheng/changcheng17.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "长城");
	set("long", WHT @LONG
你已经绕过了倒塌的城墙，有回到了长城上。站在坚实的城砖上，
你高兴的唱起歌来“万里长城永不倒。。。。。。”，歌声在空旷的山
上传了很远，很远。
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"westup"    :__DIR__"changcheng18",
		"southdown" :__DIR__"changcheng16",
	]));
	set("no_clean_up", 0);
	set("coor/x", -13000);
	set("coor/y", 11000);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}