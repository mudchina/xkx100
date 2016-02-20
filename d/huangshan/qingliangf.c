// Room: /d/huangshan/qingliangf.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "清凉峰");
	set("long", @LONG
清凉台上行就是清凉峰，峰顶平坦，有一块著名巧石，形似猴子，
云雾时节，云海茫茫，便是“猴子观海”了，一旦云开天朗时候，又叫
“猴子望太平”。望太平，是因为猴子正前方是旧时的太平县。
LONG
	);
	set("exits", ([ 
		"eastdown" : __DIR__"qingliang",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
