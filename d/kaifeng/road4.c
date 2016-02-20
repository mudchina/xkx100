// /kaifeng/road4.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "州桥");
	set("long", @LONG
这座高高的桥如同彩虹初降人间，三十六道石阶直通桥面桥下就是
水流奔涌的大运河。桥上人来如梭河中巨舟横过。切然在桥下看去，人
行于高波之上，令人心颤不已。
LONG);
	set("exits", ([
		"southdown" : __DIR__"road3",
		"northdown" : __DIR__"road5",
	]));
	set("objects", ([
		__DIR__"npc/walker" : 1,
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
