// Room: /d/gumu/zhongting.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "中厅");
	set("long", @LONG
这处是古墓派弟子参见掌门之处，此刻古墓传人小龙女及神雕大侠
杨过早已名颂江湖，这对璧人不但武功已成一派宗师，两人矢志不渝之
深情更令世人倾慕不已。厅内只一张长桌，两把石椅。
    厅上方有一块匾额(bian).
LONG	);
	set("exits", ([
		"east"  : __DIR__"mudao06",
		"west"  : __DIR__"mudao05",
		"south" : __DIR__"mudao08",
		"north" : __DIR__"mudao17",
	])); 
	set("item_desc", ([
		"bian" :  HIR"
             ※※※※※※※※※※※※※※※※※※※※
             ※※※※　                      ※※※※
             ※※※※    此情不悔 天荒地老   ※※※※
             ※※※※                        ※※※※
             ※※※※※※※※※※※※※※※※※※※※\n"NOR,
	]));
        set("objects", ([
                CLASS_D("gumu")+"/longnv" : 1,
        ]));
        set("valid_startroom",1);
        set("coor/x", -3200);
	set("coor/y", 10);
	set("coor/z", 90);
	setup();
        "/clone/board/gumu_b"->foo();
}

void init()
{ 
	add_action("do_jump","zong");
	add_action("do_jump","tiao");
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me = this_player();

	if (arg!="bian")
		return notify_fail("要往哪里跳？\n");
	if(me->query_skill("yunv-shenfa", 1) < 10)
		return notify_fail("你玉女身法功力不够，跳不上匾额。\n");
	message_vision(HIY"$N凝气守中，平空拔起数丈，轻轻落在匾额之后。\n"NOR,me);
	me->move(__DIR__"bianhou"); 
	return 1; 
}

