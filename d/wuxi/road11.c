// Room: /d/wuxi/road11.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "鼋头渚");
	set("long", @LONG
太湖三万六千顷，无限风光在鼋头。来到这里，你不由地惊叹人
间竟有如此风景绝佳之处。只见奇山异石，突入太湖碧波之中，层层
巨石 (shi)，半卧湖面，惊涛拍岸，黛浪细腾。登峰远眺，只觉万顷
水波叠泛金沤，穷尽目力，心境阔然。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("item_desc", ([
		"shi" : "四个苍劲有力的大字：  "HIG"包孕吴越\n"NOR,
	]));
	set("exits", ([
		"east"   : __DIR__"road12",
		"north"  : __DIR__"road10",
	]));
	set("coor/x", 370);
	set("coor/y", -880);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}