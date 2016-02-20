// Room: /d/wuxi/westroad1.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "西新街");
	set("long", @LONG
这是一条宽阔的青砖街道，与东林路一起成为贯通无锡城东西的要
道。驿马、商贩来往不绝。常有小河穿街而过，人说“三步一桥”也不
为过。智慧的吴里工匠将桥梁与道路建筑巧妙地结合在一起，使人走在
这里一点也不觉得不便。南边是一家有名的钱庄，开在这条路上真是既
方便了生意人，又照顾了自己的营生，里面不时地传来稀哩哗啦的数钱
的声音。北面是一家当铺，细听可以听到里压低的讨价还价的声音。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"dangpu",
		"south" : __DIR__"qianzhuang",
		"west"  : __DIR__"westroad2",
		"east"  : __DIR__"guangchang",
	]));
	set("coor/x", 360);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}