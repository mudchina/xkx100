// Room: /d/quanzhou/cangjingge.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "藏经阁");
	set("long", @LONG
藏经阁是开元寺的最高处，建在一个小山坡上。阁分两层，阁下有
一小门紧闭。登阁凭栏，看双塔凌空，点坛俯地，饶富诗意。阁上藏经
近万卷。
LONG );
	set("exits", ([
		"southdown" : __DIR__"jietang",
		"northdown" : __DIR__"houshanmen",
	]));
	set("objects", ([
		__DIR__"npc/sengren" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6470);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
