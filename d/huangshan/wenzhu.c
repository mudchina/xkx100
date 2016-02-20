// Room: /d/huangshan/wenzhu.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "文殊院");
	set("long", @LONG
相传当年普门法师所建，供奉着文殊菩萨，所以叫文殊院，当年香
火盛极一时，可惜后来因武林正邪势力在玉屏峰决战，殃及文殊院，寺
中从此一蹶不振。游人至今仍可从墙壁的痕迹遥想当年一战的惨烈。
LONG
	);
	set("exits", ([ 
		"southwest" : __DIR__"yingke",
		"east"      : __DIR__"yixian",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
