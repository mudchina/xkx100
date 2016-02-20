// Room: /d/yanping/road1.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "青石道");
	set("long", @LONG
一条青石道延伸南北，西边便是府衙的围墙，东边是青砖砌就的城
墙。延平府依山而建，城中街道只比城墙稍矮，而城墙外临江一侧，城
墙高厚，真算是金城汤池了。
LONG );
	set("exits", ([
		"north"     : __DIR__"dongmen",
		"south"     : __DIR__"yanfumen",
		"southwest" : __DIR__"road2",
	]));
	set("objects", ([
		"/d/village/npc/boy" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1520);
	set("coor/y", -6180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
