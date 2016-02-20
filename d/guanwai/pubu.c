// /guanwai/pubu.c

inherit ROOM;

void create()
{
	set("short", "长白瀑布");
	set("long", @LONG
天池水从两百余尺高飞流跌落，轰鸣之声远传数里，水花直落大嶂
谷，与天然屏障玉壁、金壁相映，恰似白练当空，水柱扑向深深的谷底，
溅起几丈高的飞浪，犹如仙女散花，阳光照射下，虹飞氤跃，璀灿壮观
之极。古人诗云：“白河两岸景清幽，碧水悬崖万古留；疑似龙池喷瑞
雪，如同天际挂飞流。不须鞭石渡沧海，直可乘槎问斗牛？欲识林泉真
乐趣，明朝结伴再来游。”
LONG );
	set("exits", ([
		"southeast"  : __DIR__"damen",
		"westdown"   : __DIR__"xiaotianchi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6190);
	set("coor/y", 5200);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}