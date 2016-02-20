// Room: /d/taishan/aishen.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "爱身崖");
	set("long", @LONG
位于日观峰南边，便是爱身崖。爱身崖原名舍身崖，它三面陡峭，
下临深渊。旧时常有人为祛父母病灾，祈求神灵，跳崖献身。明万历初
年巡抚何起鸣在崖侧筑墙阻拦，更名爱身崖。
LONG );
	set("exits", ([
		"up"        : __DIR__"zhanlutai",
		"north"     : __DIR__"riguan",
		"southwest" : __DIR__"xianren",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 370);
	set("coor/y", 760);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
