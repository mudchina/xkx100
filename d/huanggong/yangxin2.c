// Room: /d/huanggong/yangxin2.c

inherit ROOM;

void create()
{
	set("short", "养性殿");
	set("long", @LONG
皇上退位后, 做了太上皇就居住在此. 太上皇不再来问朝政, 就在
此休息, 静心养性. 直至寿终正寝.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"leshou",
		"east"  : __DIR__"changyinge",
	]));
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}