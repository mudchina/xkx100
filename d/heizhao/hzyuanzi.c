// Room: /heizhao/hzyuanzi.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "黑沼院子");
	set("long", @LONG
墙里是个院子，分为两半，左一半是实土，右一半却是水塘。
跨过院子，往北通向内堂，堂前是个月洞，仍无门扉。
LONG );
	set("outdoors", "heizhao");
	set("no_clean_up", 0);

	set("exits", ([
		"out"   : __DIR__"shanlu5",
		"north" : __DIR__"hzneitang",
	]));
	set("coor/x", -5100);
	set("coor/y", -1490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}