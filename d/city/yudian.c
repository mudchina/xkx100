// Room: /city/huadian.c

inherit ROOM;

void create()
{
	set("short", "玉器店");
	set("long", @LONG
草河街上常见的店铺之一。这里是玉器店，店面不大，装饰简朴。
但这里卖的货物却绝不简单。通常你在这里能买到你所要的各种档次的
玉器，所以虽然这里地方并不显眼，远近的客商都愿到这里来办货。
    玉器店的老板正笑脸相迎。
LONG );
	set("objects", ([
		__DIR__"npc/yufan" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"caohecexiang",
	]));
	set("coor/x", -25);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}