// Room: /yangzhou/baitafokan.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","白塔佛龛");
	set("long",@LONG
白塔佛龛。塔基方形，砖砌，建于平台上，底为方形折角，四面八
角。下为束腰。砖雕须弥座，每面各置三龛，每龛各砖雕一生肖像，象
征周天十二时辰。须弥座上有半圆突起的莲瓣座和承托塔身的环带形金
刚图，从而使塔身从方形须弥座自然而柔和地过渡到圆形塔身。塔身形
若古瓶，面南中空，设“眼光门”，内供白衣大士像。
LONG );
	set("exits", ([
		"down" : __DIR__"baitataji",
		"up"   : __DIR__"baitabaosha",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 50);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}