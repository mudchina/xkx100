// Room: /d/lingzhou/huilang.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
这是连接前殿和后宫的回廊，两旁是朱红的廊柱，廊顶是飞檐琉璃
瓦，地上铺着白玉石板。西面通向西偏殿，北面打了个弯向东折向后宫。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"xidian",
		"east"  : __DIR__"yushanfang",
		"south" : __DIR__"ysdian",
		"north" : __DIR__"huilang2",
	]));
	set("objects", ([
		__DIR__"npc/shiwei" : 4,
	]));
	set("outdoors", "xixiagong");
	set("coor/x", -17960);
	set("coor/y", 32106);
	set("coor/z", 0);

	setup();
	replace_program(ROOM);
}
