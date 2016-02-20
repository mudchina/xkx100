// Room: /yangzhou/beiliuxiang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","北柳巷");
	set("long",@LONG
一条窄窄的小巷，不时有小轿进进出出。小巷的两边楼阁都是高高
的挑着对红灯笼，挂着青布幕帘，几个年轻女子斜靠着楼门，对过往的
行人暧昧的笑着。南面的巷口立着个木牌坊，上面题着「北柳巷」。这
里便是扬州的秦楼楚馆聚集之地。
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"south"  : __DIR__"matou",
		"north"  : __DIR__"caiyijiekou",
		"west"   : __DIR__"lichunyuan",
		"east"   : __DIR__"meixiangyuan",
	]));
	set("objects", ([
		__DIR__"npc/popi1" : 1,
	]));
	set("coor/x", 40);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}