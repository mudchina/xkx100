// Room: /d/wuyi/dahongpao.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "大红袍");
	set("long", @LONG
这里就是卧龙潭被杀的九条恶龙的归宿地。峡谷两侧为九座嶙峋突
兀的峰岩，犹如九条巨龙腾空欲飞，故称“九龙窠”。大红袍茶树就根
植在九龙窠的岩壁上。岩顶终日有水滴落，云岚雾气，滋润着这几株康
熙皇帝御赐红袍披挂的“茶中之王”。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north"      : __DIR__"path11",
		"northwest"  : __DIR__"path10",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -4950);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

