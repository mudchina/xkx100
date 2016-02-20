// Room: /d/henshan/nantian.c
// Date: Nov.1997 by Venus

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "南天门");
        set("long", @LONG
到了南天门，才能望到衡山第一的祝融峰。南天门是花岗岩的石碑
坊，中门镌有 "南天门" 三字横额，左右二门的门楣上，分别刻有 "行
云" ， "施雨" 。楹联(lian)破陋，显见岁月已久。
LONG);
        set("exits", ([
            "northeast" : __DIR__"shiziyan",
            "southup"   : __DIR__"denggaotai",
            "eastup"    : __DIR__"liuyunping",
            "southwest" : __DIR__"shanlu13",
            "northwest" : __DIR__"shanlu14",
        ]));
        set("item_desc", ([
            "lian" :
"\n
        门              路
        可              承
        通              绝
        天              顶

        仰              俯
        观              瞰
        碧              翠
        落              微
        星              峦
        辰              屿
        近              低\n\n",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -320);
	set("coor/y", -1020);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
