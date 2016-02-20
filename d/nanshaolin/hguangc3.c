// Room: /d/nanshaolin/hguangc3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "后殿广场");
	set("long", @LONG
这里是后殿广场，由整块大青石板拼成的地面上有几处凹凸的踏痕，
似是以前有高手施展内功所遗留的印记。西南是一片松树林。
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"west"      : __DIR__ "hguangc2",
		"north"     : __DIR__ "hguangc5",
		"southeast" : __DIR__ "songshu1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1830);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

