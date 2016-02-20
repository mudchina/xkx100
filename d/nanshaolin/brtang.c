// Room: /d/nanshaolin/brtang.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"般若堂"NOR);
	set("long", @LONG
你面前是一座很大的院落，周围用高墙围住，院门匾额上写着『般
若堂』三个大字。这里是少林弟子精研天下各家各派武功的所在。有很
多年轻的僧人进进出出，院内传来阵阵呼喝练功的声音。
LONG );
	set("exits", ([
		"west" : __DIR__"stoneroad3",
		"east" : __DIR__"lwc16",
	]));
	set("outdoors", "nanshaolin");
	set("objects",([
		CLASS_D("nanshaolin") + "/dahen" : 1,
		__DIR__"npc/xiao-ku" : 1
	]));
	set("coor/x", 1840);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "南少林派") && dir == "east" &&
		objectp(present("xuannan dashi", environment(me))))
		return notify_fail("玄难喝道：般若堂乃本派弟子习武之处，你非本派弟子，不能入内。\n");
		
	return ::valid_leave(me, dir);
}
