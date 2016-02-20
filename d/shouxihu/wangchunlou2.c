// Room: /yangzhou/wangchunlou2.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","望春楼");
	set("long",@LONG
望春楼楼上均为活动门窗，卸去则成露台，为赏月佳处。上悬郑板
桥墨迹“望春楼”匾，两柱悬挂张九龄李白集句楹联(lian)。
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIG"
        飞        双
        阁        桥
        凌        落
        芳        彩
        树        虹
\n"NOR,
	]));
	set("objects", ([
		"/d/city/npc/lady2" : 1,
	]));
	set("exits", ([
		"down" : __DIR__"wangchunlou",
	]));
	set("coor/x", -30);
	set("coor/y", 100);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
