// Room: /yangzhou/nanmendajie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "南门大街");
	set("long", @LONG
南门大街宽二十余丈，青砖铺地，东侧有一两丈宽、一丈深的排水
沟，街的中心种着槐树隔开道路，行人分左右而行。西边是官河，也叫
草河，岸边依次种着杨柳和碧桃、街西是太平桥，街东是城守署。由于
城守署在此的缘故，行人大多匆匆而过。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"taipingqiao",
		"east"  : __DIR__"hejiajie",
		"south" : __DIR__"nanmen",
		"north" : __DIR__"shilijie7",
	]));
	set("objects", ([
		"/d/village/npc/girl" : random(5),
	]));
	set("coor/x", 10);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}