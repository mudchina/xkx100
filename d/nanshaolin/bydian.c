// Room: /d/nanshaolin/bydian.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "白衣殿");
	set("long", @LONG
这是白衣殿，供奉白衣观音大士。大士高居须弥座上，手托净瓶，
眉含微愁，唇绽浅笑，仿佛对人间疾苦既存忧心，又觉释怀。殿中放了
红木大香案，香案上供品齐备，香火十分旺盛。
LONG );
	set("exits", ([
		"west" : __DIR__"kchang",
	]));
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1830);
	set("coor/y", -6100);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}



