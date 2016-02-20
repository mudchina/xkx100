// Room: /d/yanziwu/shiwu.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "石屋");
	set("long", @LONG
这间石屋是蔓陀山庄的花肥房，屋里一个弓腰曲背的老婆子手中拿
着一柄雪亮的长刀，她容貌丑陋，目光中尽是煞气，两根尖尖的犬齿露
了出来，便似要咬人一口，登觉说不出的恶心难受，身旁一锅沸水，煮
得直冒水气。
LONG );
	set("exits", ([
		"west"   : __DIR__"path6",
	]));
	set("objects", ([
		__DIR__"npc/yan" : 1,
	]));
	set("coor/x", 1260);
	set("coor/y", -1270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}