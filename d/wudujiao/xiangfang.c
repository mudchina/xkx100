// Room: /d/wudujiao/xiangfang.c

inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
这是一间乱糟糟的厢房，里面到处都是各种大大小小的笼子、瓦罐之
类的东西。不时能看到有毒虫在笼子里面上窜下跳，四处游走。一个赤着
膀子的白胡子老者正在手忙脚乱的给毒虫们挨个喂食，忙得手忙脚乱。
LONG
	);
	set("exits", ([
		"east" : __DIR__"nanyuan",
	]));
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/oldman": 1,
		__DIR__"obj/zhulou": 3,
	]));
	set("coor/x", -44930);
	set("coor/y", -81060);
	set("coor/z", 30);
	setup();
}

void init ()
{
	add_action("do_cun","cun");
	add_action("do_qu","qu");
}

int do_cun (string arg)
{
	object ob;
	int du_exp,du_attack,du_defense,du_dodge,du_armor,du_qi,du_jing;
	int temp,du_what,du_age;
	string du_name,du_id;
	object me = this_player();
	if ((string)me->query("family/family_name")!="五毒教" ||
		!objectp(present("old man", environment(me))))
		return notify_fail("什么？\n");
	if (!arg) return notify_fail("你要寄存什么？\n");
		ob = present(arg,environment(me));
	if (!objectp(ob)) return notify_fail("你要寄存什么？\n");
	if (ob->query("host_id") != me->query("id"))
		return notify_fail("看清楚了，那可不是你的毒虫。\n");
	if (ob->query("age") < 99 )
		return notify_fail("看清楚了，那可不是你的毒虫。\n");
	if (me->query("duchong_cun") > 0 )
		return notify_fail("白髯老者把眼一瞪，气呼呼的道：你已经存有一个毒虫了，想累死我啊？\n");
	message_vision ("白髯老者笑道：好吧，我就帮你照看一段时间，你放心吧。\n",me);
	me->set("duchong_cun",1);
	du_exp=ob->query("combat_exp");
	du_attack=ob->query_temp("apply/attack");
	du_defense=ob->query_temp("apply/defense");
	du_armor=ob->query_temp("apply/armor");
	du_dodge=ob->query_skill("dodge",1);
	du_qi=ob->query("max_qi");
	du_jing=ob->query("max_jing");
	du_name=ob->query("name");
	du_id = ob->query("id");
	me->set("du/exp",du_exp);
	me->set("du/attack",du_attack);
	me->set("du/defense",du_defense);
	me->set("du/armor",du_armor);
	me->set("du/dodge",du_dodge);
	if(du_qi>3000) du_qi=3000;
	me->set("du/qi",du_qi);
	if(du_jing>2000) du_jing=2000;
	me->set("du/jing",du_jing);
	me->set("du/name",du_name);
	me->set("du/id",du_id);
	du_age=ob->query("age");
	if(du_age > 99 && du_age < 999) me->set("du/age",100);
	if(du_age > 999 && du_age < 9999) me->set("du/age",1000);
	if(du_age > 9999 ) me->set("du/age",10000);
	message_vision ("白髯老者一把将"+du_name+"抓起来，丢进了旁边的笼子里。\n",me);
	destruct(ob);
	me->save();
	return 1;
}
int do_qu (string arg)
{
	object ob, *obj, me = this_player();
	int du_exp,du_attack,du_defense,du_dodge,du_armor,du_qi,du_jing;
	int temp,du_what,du_age,i;
	string du_name,du_id;

	if ((string)me->query("family/family_name")!="五毒教" ||
		!objectp(present("old man", environment(me))))
		return notify_fail("什么？\n");
	obj = objects();
	for (i=0; i<sizeof(obj); i++)
	{
		if(obj[i]->query("host_id") == me->query("id") )
		{
			if(environment(obj[i]) == me )
				return notify_fail(ob->name()+ "说道：你不是正骑在它身上么？\n");
			else
				if(environment(obj[i]) != environment(me) )
					return notify_fail("白髯老者说道：它在"+(environment(obj[i])->query("outdoors") ? to_chinese(environment(obj[i])->query("outdoors")) : "哪里")+"的"+environment(obj[i])->query("short")+"，赶快去找吧。\n");
				else
					return notify_fail("白髯老者说道：它不是就在你旁边么？\n");
			return 1;
		}
	}
	if (present("wudu ling",me))
	{
		me->set("duchong_cun",1);
		message_vision("白髯老者苦笑道：阁下拿着五毒令，不管有没有，变也要给你变出来一个。\n",me);
		destruct(present("wudu ling",me));
	}
	if (me->query("duchong_cun") < 1 )
		return notify_fail("白髯老者把眼一瞪，气呼呼的道：你什么时候来存过东西啊？\n");
	message_vision("白髯老者笑道：快把它领走吧，这段时间真累死我了。\n",me);
	me->set("duchong_cun",0);
	du_exp=me->query("du/exp");
	du_attack=me->query("du/attack");
	du_defense=me->query("du/defense");
	du_armor=me->query("du/armor");
	du_dodge=me->query("du/dodge");
	du_qi=me->query("du/qi");
	du_jing=me->query("du/jing");
	du_name=(string)me->query("du/name");
	du_id =(string)me->query("du/id");
	du_age=me->query("du/age");
	if(du_age> 99 && du_age < 999 && du_id=="du she")
	{
		ob =new(__DIR__"npc/she1");
	}
	if(du_age> 999 && du_age < 9999 && du_id=="du she")
	{
		ob =new(__DIR__"npc/she2");
	}
	if(du_age> 9999 && du_id=="du she")
	{
		ob =new(__DIR__"npc/she3");
	}
	if(du_age> 99 && du_age < 999 && du_id=="zhi zhu")
	{
		ob =new(__DIR__"npc/zhizhu1");
	}
	if(du_age> 999 && du_age < 9999 && du_id=="zhi zhu")
	{
		ob =new(__DIR__"npc/zhizhu2");
	}
	if(du_age> 9999 && du_id=="zhi zhu")
	{
		ob =new(__DIR__"npc/zhizhu3");
	}
	if(du_age> 99 && du_age < 999 && du_id=="wu gong")
	{
		ob =new(__DIR__"npc/wugong1");
	}
	if(du_age> 999 && du_age < 9999 && du_id=="wu gong")
	{
		ob =new(__DIR__"npc/wugong2");
	}
	if(du_age> 9999 && du_id=="wu gong")
	{
		ob =new(__DIR__"npc/wugong3");
	}
	if(du_age> 99 && du_age < 999 && du_id=="xie zi")
	{
		ob =new(__DIR__"npc/xiezi1");
	}
	if(du_age> 999 && du_age < 9999 && du_id=="xie zi")
	{
		ob =new(__DIR__"npc/xiezi2");
	}
	if(du_age> 9999 && du_id=="xie zi")
	{
		ob =new(__DIR__"npc/xiezi3");
	}
	if(du_age> 99 && du_age < 999 && du_id=="chan chu")
	{
		ob =new(__DIR__"npc/chanchu1");
	}
	if(du_age> 999 && du_age < 9999 && du_id=="chan chu")
	{
		ob =new(__DIR__"npc/chanchu2");
	}
	if(du_age> 9999 && du_id=="chan chu")
	{
		ob =new(__DIR__"npc/chanchu3");
	}
	ob->move(environment(me));
	ob->set("combat_exp",du_exp);
	ob->set_temp("apply/attack",du_attack);
	ob->set_temp("apply/defense",du_defense);
	ob->set_temp("apply/armor",du_armor);
	ob->set_skill("dodge",du_dodge);
	ob->set("max_qi",du_qi);
	ob->set("max_jing",du_jing);
	ob->set("name",du_name);
	ob->set("eff_jing", ob->query("max_jing"));
	ob->set("jing", ob->query("max_jing"));
	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("qi", ob->query("max_qi"));
	ob->set("food", ob->max_food_capacity());
	ob->set("water", ob->max_water_capacity());
	message_vision ("白髯老者从旁边取出一个笼子，打开笼门。"+du_name+"顿时从里面窜了出来。\n",me);
	ob->set("host_id",(string)me->query("id"));
	ob->set_leader(me);
	me->save();
	return 1;
}
