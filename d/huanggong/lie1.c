// Room: /d/huanggong/lie1.c

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
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"dadao",
		"west"  : __FILE__,
		"north" : __DIR__"lie2",
		"south" : __FILE__,
	]));
	set("coor/x", -260);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}