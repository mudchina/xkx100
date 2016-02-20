// /guanwai/tiyun.c

inherit ROOM;

void create()
{
	set("short", "梯云峰");
	set("long", @LONG
玉柱峰北，有一山峰，峰脊出梯河瀑布，远望如腾白如云，纵列如
梯，故名梯云峰。
LONG );
	set("exits", ([
		"south"      : __DIR__"yuzhu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6170);
	set("coor/y", 5170);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}