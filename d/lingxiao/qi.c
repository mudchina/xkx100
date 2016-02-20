// Room: /d/lingxiao/qi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","居室");
	set("long",@LONG 
这是齐自勉的房间。齐自勉性格风雅，为人飘逸。墙上挂着李白的
《将进酒》，是齐自勉亲手所书，字迹豪放奔放，走的是张旭狂草的路
子，从这依稀也能看出主人武功的性情。照壁上一幅《雪月夜行图》，
是他当年一夜奔波八百里，灭掉太行三十寨的荣事。桌上燃着一束檀香，
散发出恬静的气息。一张焦尾琴摆在桌上，主人正在自斟自饮，自得其
乐。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"zoulang4", 
	]));
	set("objects", ([  
		__DIR__"npc/qi" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

