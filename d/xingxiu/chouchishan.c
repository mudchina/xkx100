// Room: /d/xingxiu/chouchishan.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"仇池山"NOR);
	set("long", @LONG
这里绝壁峭峙，孤险云高，山峰拔地而起，直刺蓝天。山顶平田千亩，风
景秀美，物产丰饶，气候温和，泉水多，胜迹遍山。仇池石色赭红，吸水性能
强，适宜养育小树花卉。远远可以看见东南边有一座雄伟的关隘。
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"southeast" : __DIR__"silk1",
		"north"     : __DIR__"silk2",
		"southwest" : __DIR__"shuiliandong",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20000);
	set("coor/y", 500);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

