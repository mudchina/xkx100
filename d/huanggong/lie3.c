// Room: /d/huanggong/lie3.c

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
		"west"  : __DIR__"lie2",
		"east"  : __DIR__"lie3",
		"north" : __DIR__"lie3",
		"south" : __DIR__"lie4",
	]));
	set("no_clean_up", 0);

	set("coor/x", -250);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}