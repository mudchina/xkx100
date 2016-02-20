// Room: /d/huanggong/qinandian.c
inherit ROOM;

void create()
{
	set("short", "钦安殿");
	set("long", @LONG
钦安殿位于御花园内, 殿顶为平顶四坡式, 周围有汉白玉石栏板. 
殿内供奉玄武大帝, 殿旁有鱼池假山, 奇花异树. 北边穿过御花园垒石
砌就的堆秀山, 就是皇宫的北门神武门了.
LONG
	);
	set("exits", ([
		"north"     : __DIR__"shenwumen",
		"south"     : __DIR__"yuhuayuan2",
	]));
	set("coor/x", -200);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}