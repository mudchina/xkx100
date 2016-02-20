// Room: /yangzhou/shuiyun.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","水云胜概");
	set("long",@LONG
水云胜概位于长春桥西，莲花桥东，昔为清黄履暹别墅，为黄园的
北半部分。面南三楹，中间悬孙轶青题写的“水云胜概”匾，外柱悬挂
李白、杜甫诗句集联(lian)。外廊设木板坐栏。
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIG"
        桃        野
        花        竹
        飞        上
        绿        青
        水        霄
\n"NOR,
	]));

	set("exits", ([
		"east"      : __DIR__"changchunqiao",
		"south"     : __DIR__"lianhuaqiao",
		"southwest" : __DIR__"baitaqingyun",
		"southdown" : __DIR__"pingtai3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}