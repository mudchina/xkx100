// Room: /d/fuzhou/ximendajie.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "西小街");
	set("long", @LONG
青石板路笔直地伸展出去，直通西门。街北望去，好一片的潋滟水
色，街南却是一片丛林，佛号钟呤，悠远传音。
LONG );
	set("exits", ([
		"west"  : __DIR__"ximen",
		"east"  : __DIR__"xidajie",
		"north" : __DIR__"xihu",
		"south" : __DIR__"xichansi",
	]));
	set("objects", ([
		__DIR__"npc/cui": 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 1820);
	set("coor/y", -6300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
