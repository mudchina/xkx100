// /d/meizhuang/xiaowu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "琴堂");
	set("long", @LONG
你进了这间琴堂以后，发现这里竟然和你想象的差别很大，这里虽
然不能说是金碧辉煌，但到处都是玉制的物器，玉桌，玉椅，玉屏风，
玉茶壶，玉杯......数不胜数。墙上挂着一根绿玉萧和一具白玉瑶琴。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"out"   : __DIR__"xiaoyuan",
		"north" : __DIR__"neishi",
	]));
	set("objects", ([ /* sizeof() == 2 */
		CLASS_D("heimuya")+"/gong" : 1,
	]));

	set("coor/x", 3510);
	set("coor/y", -1420);
	set("coor/z", 20);
	setup();
}
