// Room: /d/quanzhou/houshanmen.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "后山门");
	set("long", @LONG
走到藏经阁后，东北边有扇小门。这就是开元寺的后山门。门外是
个城隍庙。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southup"     : __DIR__"cangjingge",
		"northeast"   : __DIR__"chenghuangmiao",
	]));
	set("coor/x", 1830);
	set("coor/y", -6460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
