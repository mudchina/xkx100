// Room: /d/lingxiao/roomwang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","居室");
	set("long",@LONG 
这里与其说是一间卧室，不如说是一间练功室。地上铺满了浑圆的
黄豆，怎么也站不住。室内立了八根梅花桩，一名身挂披风的男子正在
上面纵跃如飞，看得人眼花缭乱。他正是凌霄城的六代弟子汪万翼。他
的轻功卓绝，在凌霄城数一数二，甚至与白自在不相上下，谁也不知道
他是怎么学上来的，也许可以向他问问这件事。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"zoulang1", 
	]));
	set("objects", ([  
		__DIR__"npc/wang1" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8880);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

