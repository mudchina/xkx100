// Room: /d/huangshan/wenquan.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "温泉");
	set("long", @LONG
黄山温泉古称汤泉，古人云“紫云峰下藏太阳，不施炉灶自成汤”，
更兼有医药功能名闻天下。因为曾多次涌出红色泉水，误为朱砂，所以
又称朱砂泉，多有山民在此建庐舍，设盆圩，游人沐浴后，无不精神百
倍。温泉西上便是慈光阁，北边远远可见观瀑亭。
LONG
	);
	set("exits", ([ 
		"northup"   : __DIR__"ciguang", 
		"eastup"    : __DIR__"guanpu",
		"southdown" : __DIR__"shanmen", 
	]));
	set("objects", ([
		__DIR__"obj/tangquan" : 1,
	]) );
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
