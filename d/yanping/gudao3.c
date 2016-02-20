// Room: /d/yanping/gudao3.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "闽赣古道");
	set("long", @LONG
福建境内数不尽的山坎相连。密林幽谷相继，终日不见天光。山中
毒虫猛兽出没无常，行路艰辛。路边有一年轻汉子倚在树上，眯着眼打
量着你。
LONG );
	set("exits", ([
		"westup"    : __DIR__"gudao2",
		"northeast" : __DIR__"gudao4",
	]));
	set("objects", ([
		"/d/qingcheng/npc/jia" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1300);
	set("coor/y", -6300);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
