// Room: /d/quanzhou/xiyuan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "戏院");
	set("long", @LONG
这里是南方戏曲中心，四面八方的戏迷每天都涌入此地一睹为快。
戏院里戏种繁多，曲目精彩。计有南音，梨园戏，提线木偶，高甲戏等
饮誉四方的珍贵艺术。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"zhaiqu2",
		"east"      : __DIR__"zhaiqu1",
	]));
	set("coor/x", 1830);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
