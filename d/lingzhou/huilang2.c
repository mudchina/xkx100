// Room: /d/lingzhou/huilang2.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
这是御花园外的回廊，两旁是朱红的廊柱，廊顶是飞檐琉璃瓦，地
上铺着白玉石板。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"huilang",
		"north" : __DIR__"garden",
	]));
	set("no_clean_up", 0);
	set("outdoors", "xixiagong");

	set("coor/x", -17960);
	set("coor/y", 32110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
