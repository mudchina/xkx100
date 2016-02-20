// muwu2.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
        set("short", "小木屋");
        set("long", @LONG
这是一间不是很大的木头屋子，这里看起来象个药室，室中摆放着
各种不同的配药的用具和一些已经配好了的药。
LONG );
	set("exits", ([
		"south" : __DIR__"xiaodao3",
	]));
	set("objects", ([
		CLASS_D("xiaoyao")+"/xuemuhua" : 1,
//		__DIR__"npc/yaotong": 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 80);
	set("coor/y", -480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}