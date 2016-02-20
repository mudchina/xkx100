// Room: /d/city/yaopu2.c
// Last modified by winder 2003.8.20

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "药铺内室");
	set("long", @LONG
这是药铺的内室，四壁都是药柜子，有开有关，半开的柜子里可以
看到半露的药材。地上、板凳上也放置了一些零碎药材，还有一些药罐、
药臼等配药器具。你可以用分药(fenyao)命令，帮助药铺老板分配这些
中药。
LONG
	);
	set("no_fight",1);
	set("no_steal",1);
	set("no_beg",1);

	set("exits", ([
		"west" : __DIR__"yaopu",
	]));
	set("coor/x", 16);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_fenyao","fenyao");
	add_action("do_ban","dazuo");
	add_action("do_ban","tuna");
	add_action("do_ban","du");
	add_action("do_ban","study");
	add_action("do_ban","exercise");

}
int do_ban()
{
	write ("你干什么这是别人的内室呀，不要影响别人工作。\n");
	return 1;
}
int do_fenyao()
{
	object mon, me = this_player();
	int bonus,exp,pot;

	if((int)me->query_temp("fengyaoover"))
		return notify_fail("你的药已经分完了，快去找老板要报酬吧。\n");	
	if( (int)me->query_temp("fengyao") ) 
		return notify_fail("你已经在工作了。\n");
	if (!(int)(me->query_temp("fengyaobegin")))
		return notify_fail("外间有人在喊：里面的人在做什么？快走快走。\n");
	message_vision("$N将袖子一缅，做出一副要大干一场的样子，唉，分个药也要这么样吗？\n\n",me);
	me->set_temp("fengyao",1);
	me->add("qi",-5);
	me->delete_temp("fengyaobegin");
	call_out("del_fengyao", 1, me, mon, bonus, exp, pot);
	return 1;
}
void del_fengyao(object me, object mon, int bonus, int exp, int pot)
{
	int xunhuan;

	xunhuan=random(4);
	xunhuan+=2;
	me->delete_temp("fengyao");
	while(xunhuan > 0)
	{
		if (random (8) <1)
		{
			message_vision( HIY"哎呀，$N累的满头大汗，一不小心分错了药。\n"NOR,me);
			me->add("qi",-5);
			me->start_busy(1);
			me->set_temp("fengyaow",1);
		}
		else
		{
			switch(random(5))
			{
				case 0: 
					message_vision("只见$N随手一扔，药居然刚好扔进药箱，好运气呀。\n",me); 
					me->add("qi",-1);
					break;
				case 1: 
					message_vision("$N分的好仔细呀，还要检查一次。\n",me);
					me->add("qi",-3);
					break;
				default:
					message_vision("$N看着手上的药材，想了半天终于还是没有找到该放的地方。\n",me); 
					me->add("qi",-4);
					break;
			}
			me->start_busy(1);
		}
		xunhuan--;
	} 
	write(HIW"\n 终于完成了，累死人了，好了终于可以去休息一下了.\n对了我还要去拿报酬呢，可不能白干。\n"NOR);
	me->set_temp("fengyaoover", 1);
	me->start_busy(3);
	return ;
}

