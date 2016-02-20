// Room: /d/wuyi/mantingfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "幔亭峰");
	set("long", @LONG
大王峰北侧的幔亭峰，俗称铁佛峰，为仙家招宴之所。此峰丹霞峻
拔，苍松环簇，宛如一个巨大的翠屏。山的半壁“幔亭”二字，为明代
吴思学所书。山顶地势平坦，中有一块状如香鼎的巨石，名叫宴仙坛。
相传武夷君和皇太姥、魏王子骞在此设幔亭宴会乡人。“幔亭”之名由
此而来。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"huanguyan",
		"southdown" : __DIR__"path3",
	]));
	set("objects", ([
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("coor/x", 1390);
	set("coor/y", -4970);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

