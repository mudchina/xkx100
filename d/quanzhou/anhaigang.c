// Room: /d/quanzhou/anhaigang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "安海港");
	set("long", @LONG
安海港是泉州三大港口之一。这里港阔水深，风平浪静。极目远眺，
海天一色，蔚蓝无暇。岸边停靠着密密麻麻的各种船只。东边有座姑嫂
塔。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"east"  : __DIR__"gushaota",
		"north" : __DIR__"portroad4",
	]));
	set("objects", ([
		__DIR__"npc/kuli" : 1,
		"/d/taishan/npc/tiao-fu" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6630);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
