// Room: /d/xingxiu/xinglongshan.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;

void create()
{
	set("short", "兴隆山");
	set("long", @LONG
此山东西两面山坡上，天然林密布，有云杉、松、桦、柳、杨等乔
木及灌木丛。峰峦叠翠，四季长青。上有太白、玉液泉，汇成小溪山涧，
清流潺潺。中有大峡河，清澈见底，南北穿越峡谷。地阴潮湿，气温较
低，为游览避暑胜地。
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"northdown" : __DIR__"shimen",
	]));
	set("objects", ([
		__DIR__"npc/yang" : 2,
	]));
	set("coor/x", -22000);
	set("coor/y", 500);
	set("coor/z", 100);
	setup();
}
#include "/d/xingxiu/job2.h";
