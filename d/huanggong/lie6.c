// Room: /d/huanggong/lie6.c

inherit ROOM;

void create()
{
	set("short", "上林囿");
	set("long", @LONG
这是西苑的一片广袤的大猎场, 疾风吹劲草, 大有草枯鹰眼疾的非
凡气派.
LONG
	);

	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 4 */
		"east"  : "/d/beijing/hbridge",
		"west"  : __DIR__"lie6",
		"north" : __DIR__"lie5",
		"south" : __DIR__"lie6",
	]));
	set("no_clean_up", 0);

	set("coor/x", -260);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
