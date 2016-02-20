// Room: /city/chanzhisi.c

inherit ROOM;

void create()
{
	set("short", "禅智寺");
	set("long", @LONG
这是扬州最有名的一间寺庙，庙中香火极盛。又得当地官府权贵欣
赏，寺庙修得气势不凡，门口的牌楼显得十分地高大，上面的烫金匾牌
一新如洗。两边黄墙黑桅，也看得出是年年修缮。
LONG );
	set("exits", ([
		"north"  : __DIR__"chanzhidadian",
		"south"  : __DIR__"chanzhimenqian",
	]));
	set("objects", ([
		__DIR__"npc/kanmenseng": 1,
	]));
	set("coor/x", -20);
	set("coor/y", -9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}