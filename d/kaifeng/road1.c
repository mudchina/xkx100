// /kaifeng/road1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
这条道横贯南北，北到宣德门，南至南盈门，是以前皇上出巡时常
走的道所以修得也是格外平整。道两边店铺不断。向南再过去不远。经
过石拱门就是相国寺，北面是朱雀门。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"west"    : __DIR__"yaopu",
		"north"   : __DIR__"zhuque",
		"southup" : __DIR__"gongmen",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
