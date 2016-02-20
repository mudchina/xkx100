// Room: /d/xingxiu/npc/piaoran.c
// Last Modified by Winder on Apr. 25 2001

#include <ansi.h>
inherit NPC;
string ask_job();
void create()
{
	set_name("飘然子", ({ "piaoran zi", "piaoran", "zi" }) );
	set("gender", "男性" );
	set("nickname", "星宿派五弟子");
	set("age", 28);
	set("long", "他生性淫邪，武功高强，经常奸淫良家妇女。
后被正派人士截杀，断了两条腿逃回了星宿后，就再没步出过这个山洞。\n");
	set("env/wimpy", 40);
	set("str", 28);
	set("dex", 10);
	set("con", 25);
	set("int", 22);
	set("shen", -10000);

	set_skill("force", 100);
	set_skill("huagong-dafa", 105);
	set_skill("strike", 100);
	set_skill("chousui-zhang", 105);
	set_skill("poison", 100);
	set_skill("parry", 100);
	set_skill("staff", 100);
	set_skill("tianshan-zhang", 100);
	set_skill("literate", 50);
	map_skill("force", "huagong-dafa");
	map_skill("strike", "chousui-zhang");
	map_skill("parry", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");

	set("max_qi", 1100);
	set("max_jing", 900);
	set("neili", 1500);
	set("eff_jingli", 1100);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 600000);
	set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
	}));
	
	create_family("星宿派", 2, "弟子");
	set("inquiry", ([
		"星宿派" : "你想加入，就拜我为师。",
		"星宿海" : "去星宿海干什么？拜我为师就够你学的了。",
		"丁春秋" : "丁春秋是你叫的吗？没大没小的。以后叫老仙！",
		"炼毒"   : (: ask_job :),
		"毒"     : (: ask_job :),
		"poison" : (: ask_job :),
	]));	
	setup();
	carry_object("clone/cloth/dao-cloth")->wear();
	add_money("silver", 10);
}

string ask_job()
{
	object me;
	mapping fam;
	int poison, exp;
	me = this_player();
	fam = (mapping)me->query("family");
	poison = me->query_skill("poison", 1);
	exp=me->query("combat_exp",1); 
 
	if(!fam) return "给老子滚一边去！";
	if(fam["family_name"] != "星宿派" && !me->query_temp("ding_flatter"))
		return "给老子滚一边去！";
	if(poison < 120) return "哈哈哈，你先学够了基本的毒技再来吧。";
	if(poison >= 200) return "这个。。。这种腐尸毒对你好象没什么用了吧？";
	if(me->query_skill("huagong-dafa", 1) < 100 )
		return "你的化功大法还不纯熟，炼毒会很危险的！";
	if(me->query_condition("wait_xx_task"))
		return "你好象把师兄的事情搞砸了吧？这次你就好好等着。";  
	if(me->query_condition("xx_task") || me->query_condition("xx_task2"))
		return "你还在为其他师兄弟们做事呢，等完成了再来我这里吧。";   
	if(interactive(me) && me->query_temp("xx_job"))
		return "你怎么还在这里发呆？";

	me->set_temp("promotion_target",1 );
	message_vision("\n$N对着$n嘿嘿一笑：“想练毒是吧？先去给你自己找具有用的尸体来。”\n", this_object(), me);
	return "记住，可不是杀个小喽罗那样丢人显眼！\n";    
}

void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object me)
{
	mapping fam;
	fam = (mapping)me->query("family");

	if (fam["family_name"] != "星宿派")
	{
		command("say 哪里跑来的"+RANK_D->query_rude(me)+"！竟敢擅闯星宿禁地！");
		kill_ob(me); 
	}
}
void kicking(object who)
{
	if(!who || environment(who) != environment())  return;
	who->move("/d/xingxiu/cave");
	message("vision","只听“呼”地一声，紧接着"+who->query("name")+"从黑暗中直飞出来，摔了个四脚朝天！\n", environment(who), who);
	who->receive_wound("jing", 200);
	who->receive_wound("qi", 250);
	who->start_busy(5);
}
int accept_object(object who, object ob,object me)
{
	object obj;
	if(!objectp(obj = present("shi guan", environment()))) return 0;
	if(obj->query_temp("liandu"))
	{
		command("say 石棺正在用呢，你等等吧。");
		return 0;
	}
	if(ob->query("id") != "corpse")
	{
		command("say 这是什么东西？？");
		return 0;
	}
	if(userp(ob))
	{
		command("stare " + who->query("id"));
		command("say 竟敢来这里欺骗我，给我滚出去！");
		message_vision("\n说完$N双掌前推，一股内劲拂出，就将$n震出洞外！\n\n", this_object(), who);
		kicking(who);
		return 0;
	}
	if(!who->query_temp("promotion_target"))
	{
		command("say 你这样拿具尸体给我干什么？");
		return 0;
	}       
	if ( ob->query("kill_by") != who)
	{
		command("say 嘿嘿，练腐尸毒的尸体是需要自己亲自杀的，你另找一具吧。");
		return 0;
	}
	if ( (ob->query("victim_user") &&
		ob->query("victim_exp") < who->query("combat_exp")/3) ||
		(!ob->query("victim_user") &&
		ob->query("victim_exp") < who->query("combat_exp")))
	{
		command("say 嘿嘿，我早就说过太弱的尸体没用，你另找一具吧。");
		return 0;
	}
	if (interactive(who) && (who->query_condition("xx_task") ||
		who->query_condition("xx_task2")))
	{
		command("pat "+ who->query("id"));
		command("say 你还在为其他师兄弟们做事呢，等完成了再来我这里吧。");
		return 0; 
	}
	call_out("put_in", 4, ob, this_object(), who, obj);
	return 1;
}

int put_in(object corpse, object ob, object me, object obj)
{
	object *inv;
	int i;
	if(!objectp(present(obj, environment(ob))))
	{
		command("say 咦？石棺怎么不见了？");
		command("drop corpse");
		return 1;
	}
	if(!objectp(present(me, environment(ob))))
	{
		command("say 耶？那家伙怎么不见了？");
		command("drop corpse");
		return 1;
	}

	inv = all_inventory(corpse);
	i = sizeof(inv);
	while(i--) destruct(inv[i]);
	corpse->move(obj); 
	if(corpse->query("victim_user")) obj->set_temp("liandu", 2);
	else obj->set_temp("liandu", 1);
	obj->set_temp("liandu_target", me->query("id"));
	obj->set("arg", ob->query_temp("dest"));
	command("nod "+me->query("id"));
	command("say 好吧，你来试着练习(liandu)一下毒技吧。");
}
