//room: dadao1.c
inherit ROOM;

void create()
{
	set("short","青石大道");
	set("long",@LONG
这是一条青石铺成的宽敞大道，每块青石都是长约八尺，宽约三尺，
甚是整齐，堪称巧夺天工。道旁是郁郁葱葱的松树林，不时可以看到一
两只松鼠蹦蹦跳跳地跃向树林深处。往北望去，一座巨大的石堡巍然耸
立。
LONG );
	set("outdoors", "lingjiu");
	set("exits",([
		"north"    : __DIR__"dadao2",
		"westdown" : __DIR__"xianchou",
	]));
	set("objects",([
		__DIR__"npc/songshu" : 2,
	]));
	set("coor/x", -51000);
	set("coor/y", 30100);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}