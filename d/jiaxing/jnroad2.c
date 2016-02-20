// Room: /d/jiaxing/jnroad2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在江南的一条山路上，到处莺飞草长。时值春日，路旁的山坡
上开满了金黄色的油菜花。东面是江南名城嘉兴。西边就是天下名城苏
州府了。
LONG );
	set("exits", ([
		"south" : __DIR__"jnroad3",
		"north" : __DIR__"jnroad1",
		"east"  : __DIR__"jiaxing",
		"west"  : "/d/suzhou/dongmen",
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
	set("coor/x", 1000);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}