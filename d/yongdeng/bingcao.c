// Room: /huanghe/bingcao.c
// Java Sep. 22 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "冰草湾");
	set("long", @LONG
冰草湾在营盘水的西南，平时人迹少至，因为当地沙漠里长着一
种神奇的药草----"冰草"而得名。据说这种药草能解百毒，所以偶有
人来采这种草，不过沙漠里常有毒虫出没，极为危险。
LONG );
	set("exits", ([
		"southwest" : __DIR__"shixiazi",
		"northeast" : __DIR__"yinpanshui",
	]));
	set("objects", ([
		__DIR__"npc/wugong" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "yongdeng");
	set("coor/x", -21000);
	set("coor/y", 18000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}