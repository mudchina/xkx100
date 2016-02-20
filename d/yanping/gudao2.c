// Room: /d/yanping/gudao2.c
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
		"westdown" : __DIR__"gudao1",
		"eastdown" : __DIR__"gudao3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	set("coor/x", 1200);
	set("coor/y", -6300);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
