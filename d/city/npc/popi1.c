// popi1.c
// Last Modified by Winder on Jul. 15 2000

inherit NPC;

void create()
{
	set_name("张不四", ({"po pi","punk"}) );
	set("gender", "男性" );
	set("title","泼皮");
	set("age", 20);
	set("long", "这人是个泼皮，整天无所事事，到处闲逛。。\n");
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_skill("unarmed", 20);
	set("combat_exp", 2000);
	set("str", 25);
	set("per", 20);
	set("inquiry", ([
		"here" : "挣大眼睛自己看看，没看老子正忙着吗？！",
	]) );
	set("chat_chance", 20);
	set("chat_msg", ({
"泼皮骂骂咧咧的说道：赌场老板真他妈不是东西，老子欠债又不是不能还了，竟敢把老子轰出来？！\n",
"泼皮盯着自己的手看了半天，咕咕囔囔的叨唠着：”真是怪事，这手尽抓瘪十！？\n",
"妈的！泼皮不满的嘟囔着：人都他妈死绝了，老子一没钱了，连个鬼影都见不到了！\n",
"泼皮说道：去去，一边去，大爷正烦着呢！\n",
"泼皮打量者你，不知道想做些什么。\n",
"我知道个秘密，怎么样，咱最近手头有点紧。\n",
		(:random_move:),
	}) );
	setup();
	carry_object(__DIR__"obj/poyi")->wear();
}

int accept_object(object me, object ob)
{
	int val;

	val = ob->value();
	if ( val < 5000  )
	{
		message_vision("张不四对$N一翻大眼，这么一点钱就想打发大爷我？\n", me);
		command( "kick " + me->query( "id" ) );
		return 0;
	}
	if (random(5) == 0)
		command( "whisper " + me->query("id") + " 据说杨府藏有不世奇珍，是件神物呢！" );
	else 
	{
		command( "look " + me->query( "id" ) );
		command( "say 现在真是怪事多，还到处硬塞钱的，那我就收下了。");
	}
	return 1;
}

