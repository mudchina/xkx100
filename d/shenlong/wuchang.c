// /d/shenlong/wuchang.c
// Last Modified by winder on Aug. 18 2002
 
inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这是一个宽大的练武场，有几个手执短剑的少年少女在这里练功。
旁边站着几人，有男有女，年纪轻的三十来岁，老的已有六七十岁，身上
却不带兵刃。南边是一条走廊。
LONG );
	set("exits", ([
		"south" : __DIR__"zoulang",
	]));
	set("objects", ([
                "/d/shaolin/npc/mu-ren": 5,
	]));
	setup();
	replace_program(ROOM);
}
