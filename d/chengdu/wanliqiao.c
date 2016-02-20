// Room: /d/chengdu/wanliqiao.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "万里桥");
	set("long", @LONG
这里便是万里桥了，此桥的得名来至一句“千里之行始于足下”，
据说当时的诗人便是在此吟出此句的。桥很宽，两边是汉白玉的栏杆，
扶手上雕着狮子头，数一数有三十六头之多。桥下便是南河，水流清澈
见底，一群小孩在水中嬉戏打闹。
LONG	);

	set("outdoors", "chengdu");
	set("exits", ([
		"west" : __DIR__"wangjianglou1",
		"east" : __DIR__"xuetao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8020);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}



