// Room: /d/chengdu/southchengmen.c
// Last Modifyed by Winder on Jan. 4 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "南城门");
	set("long", @LONG
成都南门，这年头天下不太平，再加上成都是蜀中重镇，是兵家守
卫之要冲，自然是盘查严密。厚厚青砖叠起的城墙上爬满了青藤，也不
知究竟有多少个年头了。守城的兵勇不怀好意的瞪着你，在此徘徊显也
易见不是什么好事，你不由得加快了步伐。
    道路南北延伸。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"north" : __DIR__"nanjie",
		"south" : __DIR__"nanheqiaos",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -8050);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

