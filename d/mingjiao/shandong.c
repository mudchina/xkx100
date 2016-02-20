// Room: /d/mingjiao/shandong.c
// Date: Java 97/04/9
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "明教密洞");
	set("long", @LONG
这里是一个小小土洞，周围黑乎乎的很难看清楚。隐隐约约，可以
看到一扇大石门(men)。
LONG );
	set("exits", ([
		"out"  : __DIR__"huangtulu2",
	]));
	set("item_desc", ([
		"men"  : "一扇大石门，看来总有两万斤重吧。\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52060);
	set("coor/y", 800);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_break","break");
}
int do_break(string arg)
{
	object *ob, me = this_player();
	int i;

	if (arg != "men") return notify_fail("你在干吗? \n");
	if ( objectp(present("xiao zhao", environment(me))))
	{
		if((me->query_skill("jiuyang-shengong",1)<50) || me->query("neili")<500)
		{
			message_vision(CYN"小昭冲着$N淡淡笑道：你的九阳神功还早着呢。\n"NOR,me);
			return 1;
		}
		message_vision(CYN"小昭一声惊呼，石门在$N一击之下轧轧声响，缓缓移开。\n"NOR,me);

		ob = all_inventory(environment(me));
		for(i=0; i<sizeof(ob); i++)
		{
			if( !living(ob[i]) || ob[i]==me || ob[i]->query("id")=="xiao zhao")
				continue;
			message_vision(CYN"巨大的气浪把$N震出了密洞。\n"NOR,ob[i]);
			ob[i]->move(__DIR__"huangtulu2");
		}
		set("exits/enter",__DIR__"midao0");
		me->add("neili", -400);
		remove_call_out("close");
		call_out("close", 5, this_object());
	}
	else
	{
		message_vision(CYN"石门在$N一击之下，落下一些粉尘。\n"NOR,me);
		me->add("neili", -100);
	}
	return 1;
}

void close(object room)
{
	message("vision","石门又在轧轧声响，缓缓闭上。\n"NOR,room);
	room->delete("exits/enter");
}