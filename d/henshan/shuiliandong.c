// Room: /d/henshan/shuiliandong.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "水帘洞");
        set("long", @LONG
水帘洞在紫盖峰下，在吐雾和香炉两峰之间。紫盖峰之水经山涧汇
入紫盖仙洞中，深不可测，水满则溢，飞瀑高二十余丈，数叠垂帘，飘
泄而下，蔚为壮观。明张居正诗曰:  "误疑瀛海翻琼波，莫拟银河倒碧
流，自是湘妃深隐处，水晶帘挂五云头。" 以赞叹这衡山大四绝之一的
 "水帘洞之奇" 。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westdown"    : __DIR__"shanlu12",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "henshan");
	set("coor/x", -280);
	set("coor/y", -1080);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
