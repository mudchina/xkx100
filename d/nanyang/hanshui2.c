// Room: /d/nanyang/hanshui2.c
// Last Modified by winder on Nov. 20 2001

inherit RIVER;

void create()
{
	::create();
	set("short", "汉水北岸");
	set("long", @LONG
汉水北岸也是相当热闹，自北岸渡口往北，一条笔直的官道直通南
阳。此地民风淳朴，路旁夹柳成阴，酒厮林立，且都有一面大大的「酒
」旗迎风飘扬，蔚为壮观。也有不少小贩沿路叫买，语多难辨，却也令
人盛情难却。
LONG );

	set("exits", ([
		"north" : __DIR__"nanmen",
	]));
	set("outdoors", "nanyang");
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 400);
	set("coor/z", 0);
	set("to",__DIR__"hanshui1");
	setup();
}
