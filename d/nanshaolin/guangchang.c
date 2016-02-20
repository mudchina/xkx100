// Room: /d/nanshaolin/guangchang.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void init();
int do_open();
int valid_leave();
string look_gate();

void create()
{
	set("short", "山门广场");
	set("long", @LONG
这里是南少林寺山门前的广场，整个广场由大块的青石铺成，极为
平坦。但因年代久远，都有些破损。丛丛小草从石板的缝隙中长了出来。
广场周围都是密密的马尾松林，四角上各放了几块石碑，字迹都甚为模
糊。正前方黄墙碧瓦，飞檐翘檩，正是南少林山门。
LONG);

	set("exits", ([
		"south" : __DIR__"shifang",
		"north" : __DIR__"shanmen",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6310);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
