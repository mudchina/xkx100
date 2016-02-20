// Room: /d/taishan/daimiao.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "岱庙");
	set("long", @LONG
泰山脚下岱庙，是东岳福神东华帝君的道场。从南到北依次贯穿正
阳门、配天门、仁安门、天贶殿、后寝宫、厚载门，东侧辅以汉柏院、
东御座，西侧佐以唐槐院、雨花道院，极其宏大壮丽，东岳大帝的灵感
可见。往北就是岱宗坊。
LONG );
	set("exits", ([
		"north" : __DIR__"daizong",
		"south" : __DIR__"yaocan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", 500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
