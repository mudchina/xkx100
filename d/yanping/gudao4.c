// Room: /d/yanping/gudao4.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "闽赣古道");
	set("long", @LONG
福建境内数不尽的山坎相连。密林幽谷相继，终日不见天光。山中
毒虫猛兽出没无常，行路艰辛。
LONG );
	set("exits", ([
		"southwest" : __DIR__"gudao3",
		"northeast" : __DIR__"ximen",
	]));
	set("objects", ([
		__DIR__"npc/wubushe" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1400);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
