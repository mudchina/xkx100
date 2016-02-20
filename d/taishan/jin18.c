// Room: /d/taishan/jin18.c
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "紧十八盘");
	set("long", @LONG
你爬在紧十八盘上，抬头只能看到前面的人的鞋底，低头穿裆则只
见到后面人的发顶。在这里每走十来步便要稍一休息。西崖上有巨岩悬
空，侧影佛头侧枕，高鼻秃顶，慈颜微笑，名迎客佛。
　　十八盘岩层陡立，在不足两里地内升高近一里。明人赋《十八盘》
诗：“拔地五千丈，冲霄十八盘。径从穷处见，天向隙中观。重累行如
画，孤悬峻若竿。生平饶胜具，此日骨犹寒。”
LONG );
	set("exits", ([
		"northup"   : __DIR__"nantian",
		"southdown" : __DIR__"shengxian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 760);
	set("coor/z", 190);
	setup();
	replace_program(ROOM);
}
