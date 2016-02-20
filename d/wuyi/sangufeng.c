// Room: /d/wuyi/sangufeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "三姑峰");
	set("long", @LONG
三姑峰为一座上方开裂为三块巨岩的峰丛，状如三个站立的仙姑。
山下有一深潭，名叫龙潭。从潭中流下的泉水，就叫三姑泉。相传远古
大旱，禾苗干枯，百姓万般焦苦，百般求雨而苍天充耳不闻。三个仙姑
在百姓几近绝望之时，挺身施助，终致甘霖。但三位仙女也不能再还仙
身，化石成山，用留人间。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"path5",
		"southdown" : __DIR__"path4",
		"southwest" : __DIR__"huanguyan",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke" : 1,
	]));
	set("coor/x", 1400);
	set("coor/y", -4950);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

