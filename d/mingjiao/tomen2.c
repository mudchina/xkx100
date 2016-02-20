// Room: /d/mingjiao/tomen2.c
// Date: Java 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "青石阶");
    set("long", @LONG
松林渐渐开阔，面前出现了一条宽广的石板道，笔直通向前方。沿
道稀稀落落地种着几棵柏树，却显得高大挺拔，蝤龙般的枝干向天空高
高伸展着。由此向南远远望去，是一座红砖碧瓦的恢宏大宅。
LONG );
    set("exits", ([
		"west"  : __DIR__"tomen1",
		"east"  : __DIR__"shanjiao",
		"south" : __DIR__"mjsimen",
    ]));
    set("objects", ([
		__DIR__"npc/gaoshanwang": 1,
    ]));
    set("no_clean_up", 0);
    set("outdoors", "mingjiao");
	set("coor/x", -51000);
	set("coor/y", 800);
	set("coor/z", 0);
	setup();
    replace_program(ROOM);
}