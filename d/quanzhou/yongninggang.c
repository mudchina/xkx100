// Room: /d/quanzhou/yongninggang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "永宁港");
	set("long", @LONG
永宁港是泉州三大港口之一。这里港阔水深，风平浪静。极目远眺，
海天一色，蔚蓝无暇。岸边停靠着密密麻麻的各种船只。南边的姑嫂塔
流传着一个感人的故事。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south"       : __DIR__"gushaota",
		"northwest"   : __DIR__"portroad4",
	]));
	set("objects", ([
		__DIR__"npc/kuli" : 1,
		"/d/taishan/npc/tiao-fu" : 1,
	]));
	set("coor/x", 1870);
	set("coor/y", -6630);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
