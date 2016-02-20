// /d/meizhuang/shijie.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "孤山石阶");
	set("long", @LONG
你向孤山边的石阶上行去，一路欣赏着湖边长曳的杨柳。不知不觉
地转了几个弯，却见遍地都是梅树，老干横斜，枝叶茂密，想像初春梅
花盛开之日，香雪如海，定然观赏不尽。
LONG
	);
	set("outdoors", "meizhuang");
	set("exits", ([ /* sizeof() == 2 */
		"eastdown" : "/d/hangzhou/gushan",
		"north"	   : __DIR__"xiaolu",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1460);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
