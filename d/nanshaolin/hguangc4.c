// Room: /d/nanshaolin/hguangc4.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "后殿广场");
	set("long", @LONG
这里是后殿广场，由整块大青石板拼成的地面上有几处凹凸的踏痕，
似是以前有高手施展内功所遗留的印记，东面是后殿。
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"east" : __DIR__ "houdian",
		"south" : __DIR__ "hguangc1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

