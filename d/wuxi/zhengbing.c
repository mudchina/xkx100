// Room: /d/wuxi/zhengbing.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "征兵场");
	set("long", @LONG
这里是新兵征募处，门口有块木牌 (mupai)，里面挤满了人，有乳
臭未干的少年，更多的是身强力壮的青年人，每个的人脸上都是对未来
的憧憬。如果你想报效国家，征战沙场，或是出人头地，这是能实
现你梦想的地方。
LONG );
	set("outdoors", "wuxi");
	set("item_desc", ([
		"mupai" : HIR"
		
         精 忠 报 国

\n"NOR,
	]));
	set("exits", ([
		"north" : __DIR__"eastroad1",
	]));
	set("objects", ([
		__DIR__"npc/guan" : 1,
	]));
	set("coor/x", 380);
	set("coor/y", -810);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

