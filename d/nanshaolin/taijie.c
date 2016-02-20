// Room: /d/nanshaolin/taijie.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "台阶");
	set("long", @LONG
这里是一段向上的台阶，全部用整条的青石铺设而成，台阶两侧的
扶栏上雕刻着佛经上的名言警句。这里一个人也没有，显得很寂静，看
来寺中的僧人也不常到这里来。
LONG );
	set("exits", ([
		"northup" : __DIR__"lxting",
		"south"   : __DIR__"houdian",
	]));
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6170);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

