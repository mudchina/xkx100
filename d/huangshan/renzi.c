// Room: /d/huangshan/renzi.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "人字瀑");
	set("long", @LONG
黄山三名瀑之一，又名飞雨泉。人字瀑位于紫云，朱砂两峰间的山
坳之中，由于倾泄到半山之时，忽有巨石从山中斜插而出，所以半途一
分为二，形成一个人字，宛若两条飞舞的玉龙，分道扬镳，直落崖下。
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"qingluan",
	]));
	set("objects", ([
		__DIR__"npc/xiangke" : 3,
	]) );
	set("resources/water",1);
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
