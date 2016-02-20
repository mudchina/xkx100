// Room: /d/hengshan/jinlongxia.c
// Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short", "金龙峡");
	set("long", @LONG
金龙峡又称唐峪，是进入恒山的入口。恒山一名太恒山，或称玄岳，
是五岳中的北岳，道教以之为“第五小洞天”。它横亘三百余里，如一
队行进中的队列，昔人以为“恒山如行”来相对“泰山如坐”，“华山
如立”，“嵩山如卧”和“衡山如飞”。
LONG
	);
	set("exits", ([
		"southeast"  : __DIR__"cuipinggu1",
		"northeast"  : "/d/beijing/road6",
	]));
	set("objects", ([
		CLASS_D("hengshan")+"/jing" : 1,
	]));
	set("outdoors", "hengshan");
//	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 3200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

