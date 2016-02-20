// muwu3.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "工匠屋");
	set("long", @LONG
这里也是一间木屋，屋子中的摆设十分简单，但是却有很多工具，
锯子啦，刨子啦，锤子啦。满地的木屑，一看就知道是一个工匠的家。
看！我们的巧匠正忙着呢，不过不知道他又在做什么呢？
LONG );
	set("exits", ([
		"north" : __DIR__"mubanlu",
	]));
	set("objects", ([
		CLASS_D("xiaoyao")+"/fengasan": 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 90);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
} 