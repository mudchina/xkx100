// Room: /d/wuyi/tiancheng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "天成禅院");
	set("long", @LONG
虎啸庵高居虎啸岩上，明代即为武夷山释道中心。清代康熙四十六
年，由于从浙江宁波天童寺来了一位名声显赫的泉声和尚，并进庵任主
持，虎啸庵才正式易名为「天成禅院」。据虎啸岩望去，其秀无比，其
峻无双，它的险要曾令不少游人生畏，望而却步。明代释真炽在诗中写
道：「极目皆图画，居然与世违。」
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"huxiaoyan",
	]));
	set("objects", ([
		"/d/hangzhou/npc/seng": random(3),
	]));
	set("coor/x", 1390);
	set("coor/y", -5040);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

