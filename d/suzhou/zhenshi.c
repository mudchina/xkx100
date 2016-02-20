// Room: /d/suzhou/zhenshi.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "枕石");
	set("long", @LONG
在山半腰有一块巨石，因石形如枕而得名枕石。相传东晋高僧，常
在此倚石阅经，倦则枕石休息。此石其形又象蜒蚰，故亦称“蜒蚰石”。
另因有“唐寅三笑姻缘”的传说，故又名“鸳鸯石”。这块大石，实系
海涌山遗物。
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"shijianshi",
	]));
	set("objects", ([
		"/d/taishan/npc/seng-ren" : 1,
	]));
	set("coor/x", 800);
	set("coor/y", -1000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
