// Room: /d/wuyi/jiutanfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "酒坛峰");
	set("long", @LONG
酒坛峰位于五曲以南的更衣台西侧，又名天柱峰。岩峰峻峭挺立，
宛如倒立的酒坛。相传这是铁拐李在此一怒踢翻的酒坛，流淌的琼浆至
今余香不断。不过，女士们却宁可叫它醋坛峰。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"gengyitai",
	]));
	set("objects", ([
		"/d/taishan/npc/seng-ren" : 1,
	]));
	set("coor/x", 1350);
	set("coor/y", -5030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

