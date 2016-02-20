// Roo: /d/guu/yaofang.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"药房"NOR);
	set("long", @LONG
这里是一间石室，周围的火把将石室照的灯火通明，石室里面摆满
了很多瓶瓶罐罐，上面都贴好了标签，一瓶瓶玉蜂浆被古墓弟子制成后
放在此处。你能看见几个古墓弟子正在忙碌的干活。
LONG	);
	set("exits", ([
		"north" : __DIR__"mudao10",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3220);
	set("coor/y", -30);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

void init()
{
//	add_action("do_make","make");
//	add_action("do_make","huo");
}

int do_make(string arg)
{
	object ob, name1, me = this_player();
	int exp,pot,score;

	ob= present("feng mi", me);
	name1= me->query("id");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");	
	if ( arg =="jiang")
	{
		if ( ! me->query_temp("gm_job1"))
			return notify_fail("你还没去采蜜呢，怎么来制玉蜂浆？\n");
		if (!objectp(present("feng mi", me)))
			return notify_fail("你用什么来制成玉蜂浆？\n");
		if ( ob->query_temp("gm/make") != name1 )
			return notify_fail("这蜂蜜好象不是你采来的吧？\n");	
		message_vision(HIY"$N仔细地将蜂蜜调和均匀，制成玉蜂浆，放在架上。\n"NOR,me);
		me->delete_temp("gm_job1");
		exp=40+random(20);
		me->add("combat_exp",exp);
		pot= 10+random(10);
		me->add("potential",pot); 
		score=2+random(5);
		me->add("score",score);
		call_out("destroying", 1, ob);
		tell_object(me,HIW"因为劳作，你增长了：" + chinese_number(exp) + "点实战经验" + chinese_number(pot) + "点潜能" + chinese_number(score) + "点江湖阅历。\n"NOR); 
		return 1;
	}
	return notify_fail("你想把蜂蜜制成什么啊？\n");
}

void destroying(object ob)
{
	destruct(ob);
	return;
}

