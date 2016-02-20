// Room: /d/jiaxing/jnroad4.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在江南的一条山路上，到处莺飞草长。时值春日，路旁的山坡
上开满了金黄色的油菜花。北面是江南名城嘉兴。向南则进入福建武夷
山区。东面有一个供路人休息的小茶亭。
LONG );
	set("exits", ([
		"north"   : __DIR__"jxnanmen",
		"west"    : __DIR__"jnroad3",
		"southup" : "/d/yanping/xianxialing",
		"east"    : __DIR__"chating",
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
	set("coor/x", 1500);
	set("coor/y", -2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
