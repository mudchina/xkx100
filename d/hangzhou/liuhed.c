// liuhed.c
// Date: Nov.1997 by Java
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "六和塔");
	set("long", @LONG
这里是六和塔的十三层。窗(window)外是浓妆淡抹的西子湖，塔
中玲珑八角，青砖砌地，雕栏飞檐间粘连了些许蛛网。这里是塔的最
高处，往外望去，西湖美景尽收眼底。
LONG);
	set("exits", ([
	    "down"  : __DIR__"liuhec",
	]));
	set("objects", ([
	    __DIR__"honghua/chen" :1,
//	    __DIR__"npc/qianlong" :1,
	]));
	set("item_desc", ([
	    "window": "从窗口望出去，钱江东去。近处农田中，有一农夫正荷锄耕耘。\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", 3890);
	set("coor/y", -1800);
	set("coor/z", 130);
	setup();
	replace_program(ROOM);
}
