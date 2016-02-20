// Room: /d/yanping/gudao1.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "闽赣古道");
	set("long", @LONG
进入江西，还是不尽的山坎和密林幽谷，终日不见天光。放眼山中
毒虫猛兽出没无常，行路艰辛。一到这里就闻到一股腥风扑鼻而来。
LONG );
	set("exits", ([
		"northwest" : "/d/henshan/hsroad2",
		"eastup"    : __DIR__"gudao2",
	]));
	set("objects", ([
		__DIR__"npc/huananhu" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1100);
	set("coor/y", -6200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
