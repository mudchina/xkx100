// Room: /d/wudujiao/huxue2.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "虎穴深处");
	set("long", @LONG
这里是岩洞的深处，几只刚生下几个月的小虎崽正在洞中嬉戏，洞
内角落里有一堆白骨，你仔细一看，竟然是一具人类的遗骨。
LONG
	);

	set("exits", ([
		"north" : __DIR__"huxue1",
	]));
	set("objects", ([
		__DIR__"npc/laohu2": 3,
	]));

	set("coor/x", -45000);
	set("coor/y", -80010);
	set("coor/z", -10);
	setup();
}
void init()
{
	add_action("do_search","search");
	add_action("do_train","rain");
}

int do_search(string arg)
{
	object me=this_player();
	object ob;
	if( (!arg) ||!((arg == "bone") || (arg == "遗骨")))
		return notify_fail("你要搜索什么？\n");

	if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type"
)!="staff" && (string)ob->query("skill_type")!="blade" && (string)ob->query("ski
ll_type")!="sword" ) )
		return notify_fail("没有工具怎么干活？\n");

	message_vision(HIR "\n$N轻轻拨动那堆白骨。\n\n" NOR, me);
/*
	if( "/d/wudujiao/obj/tongpai"->in_mud() )
	{
		message("vission",HIR"只听呼啦一声，从里面窜出来一只大老鼠。\n"NOR, me);
		return 1;
	}
*/
	if(query("not_tongpai"))
	{
		message("vission",HIR"只听呼啦一声，从里面窜出来一只大老鼠。\n"NOR,me);
		return 1;
	}
	ob=new(__DIR__"obj/tongpai.c");
	ob->move(environment(me));
	message_vision(HIR"只听“当啷..”一声，从里面滚出来一面铜牌。\n\n\n"NOR,me);
	set("not_tongpai", 1);
	call_out("regenerate", 86400);
	return 1;
}
int regenerate()
{
	set("not_tongpai", 0);
	return 1;
}

