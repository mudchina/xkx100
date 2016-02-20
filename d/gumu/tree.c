// Room: /d/gumu/tree.c
// Last Modifyed by Winder on Jan. 14 2002
 
#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", HIG"树上"NOR);
	set("long", @LONG 
这里是树上，你突然发现树叶中有些动静，哇。。。。。。！！！
毛骨悚然！一条碗口粗细的巨蟒倒悬在树干上，张开大口，正要向你扑
来！
LONG	);
	set("outdoors", "gumu");
	set("objects",([
		__DIR__"npc/dumang" : 1,
	]));
	set("exits", ([ 
		"down" : __DIR__"xuanya",
	]));
	set("coor/x", -3220);
	set("coor/y", 40);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

