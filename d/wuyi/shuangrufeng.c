// Room: /d/wuyi/shuangrufeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "双乳峰");
	set("long", @LONG
双乳峰又名并蒂峰、鼓子峰，为八曲最高峰。远远望去，丰满挺拔
而柔美，无不让人惊叹和称奇造化天工之所钟。峰的两面岩壁上，有一
岩洞，可容数十人，相传为吴道人修炼所在，洞右小穴内还存放着有关
道人的遗蜕。这个洞就叫“吴公洞”。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northwest"  : __DIR__"path9",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -4960);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

