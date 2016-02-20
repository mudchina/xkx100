// Room: /city/hangou2.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "古邗沟边");
	set("long", @LONG
离开扬州北门，沿着古老的邗沟向北而行，就是上楚州转汴京的大
路。这条大路和古邗沟是并行的，可以看到古邗沟中舟楫点点，往来穿
梭。扬州作为水陆交通的大都会，古邗沟是将其同南北大运河相连接的
重要渠道，所以沟中的船只非常的稠密。
LONG );
	set("exits", ([
		"southwest" : __DIR__"beimen",
		"east"      : __DIR__"hangou1",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 110);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}