// Room: /d/taishan/sibeiya.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "斯碑崖");
	set("long", @LONG
玉女池侧有巨石高耸黝黑若鼎，明人查志隆题“天柱”，秦李斯篆
书《泰山刻石》曾嵌石内，俗称斯碑崖。
LONG );
	set("exits", ([
		"south" : __DIR__"yunuchi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 380);
	set("coor/y", 780);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
