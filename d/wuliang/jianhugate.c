// Room: /wuliang/jianhugate.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "剑湖宫门");
	set("long", @LONG
这里就是无量剑派的剑湖宫了。“无量剑”原分东、北、西三宗
，北宗近数十年来已趋式微，东西二宗却均人才鼎盛。“无量剑”于
五代后唐年间在南诏无量山创派，掌门人居住无量山剑湖宫。
LONG );
	set("outdoors", "wuliang");
	set("exits", ([
		"enter"     : __DIR__"road1",
		"southdown" : __DIR__"shanlu9",
	]));
	set("objects", ([
		__DIR__"npc/wuliangdizi" : 1,
	]));
	set("coor/x", -71000);
	set("coor/y", -79960);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
