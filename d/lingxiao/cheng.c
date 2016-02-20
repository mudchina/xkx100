// Room: /d/lingxiao/cheng.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","居室");
	set("long",@LONG 
这是成自学的房间。成自学虽和其他三位师弟一样，由白自在代师
授艺，但在四位师兄弟中，他和白自在关系最好。同时他为人方正，刚
严不曲，最得白自在信任，所以白自在在失踪以前，把凌霄城的寒玉牌
交给他保管。这间屋子整洁典雅，只在桌上放着一卷未写完的帛卷。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"zoulang4", 
	]));
	set("objects", ([  
		__DIR__"npc/cheng" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -30990);
	set("coor/y", -8830);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

