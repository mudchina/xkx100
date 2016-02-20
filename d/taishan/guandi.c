// Room: /d/taishan/guandi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "关帝庙");
	set("long", @LONG
一天门坊前路西是关帝庙，祀三国时蜀汉名将关羽。明清时山西盐
商常在此聚会祭祀，奉福神，故又名山西会馆。庙东院有古柏一株，墙
外碣书“汉柏第一”。
LONG );
	set("exits", ([
		"northeast" : __DIR__"yitian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 390);
	set("coor/y", 550);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
