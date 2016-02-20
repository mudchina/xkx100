// Room: /d/xingxiu/songmoya.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIM"颂摩崖"NOR);
	set("long", @LONG
颂摩崖又名黄龙碑。周围山势陡峭，两山对峙，一泓中流，两峡旁
有潭，渊深莫测。俗传有黄龙自潭飞出，因名黄龙潭。潭左侧摩崖成碑。
汉隶真迹，笔触遒劲，刀刻有力，记叙了开天井道的过程。往东南是仇
池山，往西则是石门。
LONG);
	set("outdoors", "silu");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : __DIR__"silk2",
		"westdown" : __DIR__"silk3",
	]));
	set("coor/x", -21000);
	set("coor/y", 600);
	set("coor/z", 100);
	setup();
}
#include "/d/xingxiu/job2.h";

