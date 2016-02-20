// Room: /d/shaolin/cjlou.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "藏经楼");
	set("long", @LONG
大明寺藏经之富，天下罕有其匹。这里都是密密麻麻，高及顶棚的
书架，书架间仅有容身一人通行的空隙。几排大书架中间，间隔地放着
数丈长的书桌。
LONG );
	set("exits", ([
		"south" : __DIR__"daxiongbaodian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 180);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}