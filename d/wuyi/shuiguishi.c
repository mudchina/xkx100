// Room: /d/wuyi/shuiguishi.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "水龟石");
	set("long", @LONG
七曲北角，有两块重叠的岩石，以其独特的情态和逼真的形状，把
一对上下水龟嬉戏的灵性舒展得淋漓尽致：一只潜在水里，只露出脑袋
和脊背。另一只爬在它的脊背上，朝水下伸出长长的脖颈。两块无识的
石块腾动着生命的律动，让人惊叹称绝。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northwest" : __DIR__"7qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1350);
	set("coor/y", -5020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

