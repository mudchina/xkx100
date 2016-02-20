// Room: /d/taishan/tianshen.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "天绅岩");
	set("long", @LONG
斗母宫北行不远，渐入空山，山路越来越不好走了。忽见前有石桥
横跨，名注水流桥。桥西北危崖耸立，飞瀑散珠，如带若帘，名天绅岩，
俗称水帘洞。岩顶山坳北侧有明代钟惺、林古度、吴惟明三人即兴合作
《水帘诗》摩刻。天绅岩东北有群石峭列如笋，题刻“万笏朝天”，锐
锋丛生，景观独特。
LONG );
	set("exits", ([
		"north"     : __DIR__"dengxian",
		"southdown" : __DIR__"doumo",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 610);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
