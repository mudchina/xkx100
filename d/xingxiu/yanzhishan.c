// Room: /d/xingxiu/yanzhishan.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", RED"胭脂山"NOR);
	set("long", @LONG
胭脂山因山石赭红似胭脂而得名。这里水草丰美，宜于畜牧。冰雪
融化，清流缓缓而下，汇集成渠。山下绿草如茵的马营草场滩，是久负
盛名的牧场。
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"southdown" : __DIR__"shimen",
		"southeast" : __DIR__"silk3",
		"northwest" : __DIR__"rentou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -22000);
	set("coor/y", 800);
	set("coor/z", 100);
	setup();
	set("yushi_count", 1);
}
#include "/d/xingxiu/job2.h";

