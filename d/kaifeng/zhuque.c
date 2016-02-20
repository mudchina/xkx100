// /kaifeng/zhuque.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "朱雀门");
	set("long", @LONG
这是内城的城门，高大的城墙用大青砖弥合米汁而成，时间的冲刷
使得墙砖变为铁青色。东西两边是角楼，南面不远处就是大相国寺的八
宝琉璃殿。
LONG);
	set("exits", ([
		"south" : __DIR__"road1",
		"north" : __DIR__"road2",
		"westup" : __DIR__"jiaolou1",
		"eastup" : __DIR__"jiaolou2",
	]));
	set("objects", ([
		__DIR__"npc/guanbing" : 2,
		__DIR__"npc/walker" : 1,
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
