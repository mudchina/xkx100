// Room: /d/songshan/houting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "后庭");
	set("long", @LONG
这里是峻极禅院花院内的后庭。庭院中青石铺地、古柏森森，四周
是本派首脑人物的起居之处，向来少有人来。北面是独尊坛。
LONG );
	set("exits", ([
		"north" : __DIR__"duzuntan",
		"south" : __DIR__"huayuan",
		"east"  : __DIR__"woshi",
		"west"  : __DIR__"danfang",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/ding" : 1,
	]));
	set("outdoors", "songshan");
	set("coor/x", -20);
	set("coor/y", 930);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
