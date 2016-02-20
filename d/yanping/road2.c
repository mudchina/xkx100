// Room: /d/yanping/road2.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "卵石道");
	set("long", @LONG
一条鹅卵石道延伸东西，马车在道上踢蹋穿行。北边便是延平府衙
了，东边通往延福门。延平府依山而建，城中街道只比城墙稍矮，而城
墙外临江一侧，城墙高厚，真算是金城汤池了。
LONG );
	set("exits", ([
		"west"      : __DIR__"road3",
		"east"      : __DIR__"yanfumen",
		"south"     : __DIR__"yanshoumen",
		"north"     : __DIR__"yamen",
		"northeast" : __DIR__"road1",
	]));
	set("objects", ([
		"/d/village/npc/girl" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1480);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
