// Room: /d/nanshaolin/chufang1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
炊烟缭绕，蒸汽腾腾，香味扑鼻而来。靠墙是一排数丈长的灶台，
支着十来口大锅，最大的一口饭锅上方竟有人从梁上悬空而下，手持木
棍在搅拌。除了烧饭的僧人外，几位火工头陀忙着劈柴运薪，灶下炉火
熊熊。一位中年僧人正来回催促着。
LONG );
	set("exits", ([
		"south" : __DIR__"chufang2",
                "west"  : __DIR__"fanting1",
	]));
	set("objects",([
		__DIR__"npc/shaofan-seng" : 1,
                __DIR__"npc/hg-toutuo" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

