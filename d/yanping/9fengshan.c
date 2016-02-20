// Room: /d/yanping/9fengshan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "九峰山");
	set("long", @LONG
九峰山隔西溪与府城相望。因九峰重叠居周遭诸峰之冠，故名。山
上环境幽静，树木苍郁。“九峰月朗”为延平八景之一。宋代的大儒李
侗、朱熹曾在这里讲学，赞美九峰景致为“九朵芙蓉”、“九叠翠屏”。
LONG );
	set("exits", ([
		"east"      : __DIR__"shuyuan",
		"southup"   : __DIR__"baoyunsi",
		"northdown" : __DIR__"fuqiao2",
	]));
	set("objects", ([
		"/d/huashan/npc/youke" : 2,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1480);
	set("coor/y", -6220);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
