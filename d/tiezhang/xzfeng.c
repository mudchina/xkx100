// Room: /d/tiezhang/xzfeng.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"小指峰"NOR);
	set("long", @LONG
你已登上了小指峰的峰顶。纵目远眺，但见远处四峰已淹没在浓浓
的迷雾之中。这里的高度恰在云雾之中，你只能看清身前几米的景物。
渐渐的，你的衣服已被水气沁湿，凉风袭来，冻得你瑟瑟发抖。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"southdown" : __DIR__"pubu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2070);
	set("coor/y", -1900);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}