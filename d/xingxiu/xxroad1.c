// Room: /d/xingxiu/xxroad1.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，尘土飞扬。东面是一座大城池，看城墙上
旗帜飘扬，好象就是兰州了。西面望去一片黄土和荒野。
LONG );
	set("exits", ([
	    "east"  : "/d/lanzhou/westgate",
	    "west"  : __DIR__"xxroad2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "silu");
	set("coor/x", -9500);
	set("coor/y", 2700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
