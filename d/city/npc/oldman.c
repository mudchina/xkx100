// /d/city/npc/oldman.c
// Last Modified by winder on Aug. 5 2001

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

string *class = ({
	"dragon","phenix","kylin","elephant","lion","tiger","panther","bear","fox","wolf","dog","pig","deer","marten","cat","mouse","monkey","eagle","vulture","chicken","duck","snake","tortoise","crocodile","horse","donkey","cattle","rabbit"});
string *title = ({
	HIY"龙",HIC"凤凰",YEL"麒麟","象","狮","虎","豹","熊","狐","狼","狗","猪","鹿","貂","猫","鼠","猴","鹰","雕","鸡","鸭","蛇","龟","鳄","马","驴","牛","兔"});
int *petstr=({30,20,25,30,25,25,20,25,12,15,12,15,10, 5, 5, 5,12,10,18, 5, 5,15, 5,18,20,18,22,10});
int *petdex=({30,30,25,10,20,20,25,12,20,20,20,10,22,20,20,18,30,25,25,20,20,15, 5,10,20,22,12,18});
int *petcon=({30,30,30,25,25,25,20,25,13,15,18,15,15,18,20,18,15,20,20,12,12,20,22,20,15,18,20,12});
int *petint=({30,30,30,12,15,15,12,12,20,12,20,10,10, 5,12,11,30,10,12,10,10, 5, 5, 8,12,10,10,12});
int *petper=({25,25,25,20,20,20,20,12,15,15,15,12,22,25,22,11,22,20,18,15,13, 8,10, 5,15,15,15,18});
int *petkar=({30,30,30,12,15,18,20,12,18,15,20,18,15,20,25,23,28,20,22,18,15,10,10, 8,12,15,15,12});
int *petcor=({30,30,30,15,20,25,25,20,12,20,18,12, 5,10,20,18,15,25,28,10,10,12,15,20,12,13,15, 5});
int *petcps=({30,30,30,25,20,20,15,20,25,12,18,15, 5, 8,10, 9,15,10,20,10,10,12,20,20,13,12,15, 5});
int *weight=({90,10,50,80,60,60,40,70,15,20,20,40,18,10,10, 8,15,20,35,10,10,18,10,30,40,30,45, 5});
int *value =({99,99,99,49,49,49,49,39,39,39,39,19,29,19, 9, 9,29,29,49, 9, 9,19, 9,39,39,29,29, 9});

int do_goumai(string arg);
void addaction(object pet);
void addaction(object pet)
{
	switch (pet->query("class"))
	{
		case "dragon"   :     //龙
			pet->set("verbs",({"angel","bite","claw","rope","tail"}));break;
		case "phenix"   :     //凤凰
			pet->set("verbs",({"claw","poke","wind"})); break;
		case "kylin"    :     //麒麟
			pet->set("verbs",({"angel","bite","hoof","knock"}));break;
		case "elephant" :     //象
			pet->set("verbs",({"hoof","knock","snoot"})); break;
		case "lion"     :     //狮
			pet->set("verbs",({"bite","claw","hoof","snap"}));break;
		case "tiger"    :     //虎
			pet->set("verbs",({"bite","claw","hoof","snap","tail"}));break;
		case "panther"  :     //豹
			pet->set("verbs",({"bite","claw","hoof","snap"}));break;
		case "bear"     :     //熊
		case "fox"      :     //狐
			pet->set("verbs",({"bite","claw","hoof"})); break;
		case "wolf"     :     //狼
		case "dog"      :     //狗
			pet->set("verbs",({"bite","claw","hoof","snap"}));break;
		case "pig"      :     //猪
			pet->set("verbs",({"bite","hoof","knock"}));break;
		case "deer"     :     //鹿
		case "cattle"   :     //牛
			pet->set("verbs",({"angel","hoof","knock"}));break;
		case "marten"   :     //貂
		case "cat"      :     //猫
		case "monkey"   :     //猴
		case "rabbit"   :     //兔
		case "mouse"    :     //鼠
			pet->set("verbs",({"bite","claw","hoof"})); break;
		case "eagle"    :     //鹰
		case "vulture"  :     //雕
		case "chicken"  :     //鸡
		case "duck"     :     //鸭
			pet->set("verbs",({"claw","poke","wind"})); break;
		case "snake"    :     //蛇
			pet->set("verbs",({"bite","rope","tail"}));break;
		case "tortise"  :     //龟
			pet->set("verbs",({"bite"}));break;
		case "crocodile":     //鳄
			pet->set("verbs",({"bite","claw","tail"}));break;
		case "horse"    :     //马
		case "donkey"   :     //驴
			pet->set("verbs",({"bite","hoof","knock"}));break;
		default: 
			pet->set("verbs",({"bite","claw"})); break;
	}
}
void create()
{
	set_name("白髯老头", ({ "lao tou", "laotou", "oldman"}) );
	set("gender", "男性" );
	set("age", 64);
	set("long","一个须发皆白的老者，精神矍铄，满面红光。如果你有兴趣，可以向他要只宠物养来玩玩。\n");
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 400000);
	set("attitude", "friendly");
	set_skill("dodge", 120);
	set_skill("unarmed",120);
	set_skill("parry", 120);
	set_skill("force",120);
	set("inquiry", ([
		"宠物"  : "你要购买(goumai)什么宠物？请看本店招牌。\n",
	]) );
	set("vendor_goods", ({
		FODDER_DIR+"siliao",
		FODDER_DIR+"fantuan",
		FODDER_DIR+"miantuan",
		FODDER_DIR+"roukuai",
		FODDER_DIR+"routuan",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",30);
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_goumai","goumai");
	add_action("do_return","return");
	add_action("do_lingqu","lingqu");
	add_action("do_zancun","zancun");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if( ob->query("Pet"))
	{
		say("白髯老者掀髯笑道：“这位"+RANK_D->query_respect(ob)+"，你的宠物养得如何了啊？”\n");
	}
	else
	{
		say("白髯老者掀髯笑道：“这位"+RANK_D->query_respect(ob)+"，来买宠物啊？”\n");
	}
}
int do_goumai(string arg)
{
	object pet, gold, me = this_player(), ob = this_object();
	int num;

	if(!arg)
		return notify_fail("老头笑道：“别急，你想购买什么宠物，请先看清楚招牌。”\n");
	if (me->query("Pet") && !wizardp(me))
	{
		command("say 这位"+RANK_D->query_respect(me)+"，宠物只能豢养一只，如果想买新的，得把旧的先还(return)给我。”\n");
		return 1;
	}
	if ( member_array(arg, class) == -1)
		return notify_fail("老头歉然笑道：“暂时没有这种宠物可买，请看清楚招牌。”\n");
	if (!wizardp(me) && me->query("combat_exp") < 2000000 &&
		(arg == "dragon" || arg == "phenix" || arg == "kylin"))
		return notify_fail("老头呵呵一通，笑道：“你的经验还不足养这些宠物。”\n");

	num = member_array(arg, class);
	gold = present("gold", me);
	if(!gold) return notify_fail("老头笑了笑：“你没带金子来？”\n");
	if((int) gold->query_amount() < value[num])
		return notify_fail("老头看了你一眼：“你身上黄金没带够。”\n");
	pet = new("/clone/misc/pet");
	pet->set("class", class[num]);
	pet->set("id", class[num]);
	pet->set("title", title[num]+NOR);
	pet->set("name", "宠物");
	pet->set("race", "野兽");
	pet->set_name("宠物", ({class[num], "pet"}));
	pet->set("long", "这是一只宠物"+title[num]+"。\n"NOR);
	pet->set("level",1);
	pet->set("owner", me->query("id"));
	pet->set_temp("owner", me->query("id"));
	pet->set_temp("ownername", me->query("name"));
	me->set("Pet/id", class[num]);
	me->set("Pet/name", "宠物");

	pet->set("str", petstr[num]+random(10));
	pet->set("dex", petdex[num]+random(10));
	pet->set("con", petcon[num]+random(10));
	pet->set("int", petint[num]+random(10));
	pet->set("per", petper[num]+random(10));
	pet->set("kar", petkar[num]+random(10));
	pet->set("cor", petcor[num]+random(10));
	pet->set("cps", petcps[num]+random(10));
	pet->set("obe", 1);  //初始驯服度
	pet->set("age", 1);  //年龄
// 重量决定食量
	pet->set("weight", weight[num]*1000);
	pet->set_weight(weight[num]*1000);
	if( random(10) > 4) pet->set("gender", "雌性");
	else pet->set("gender", "雄性");
	gold->add_amount(-value[num]);

	addaction(pet);
	pet->move(environment(me));
	message_vision("$N掏出"HIR+chinese_number(value[num])+NOR"两"HIY"黄金"NOR"，往柜面一砸：“给我来一只"+title[num]+NOR"。”\n", me);
	message_vision("$N看了一眼"HIY"黄金"NOR"成色，伸手一捋，把它捋到抽屉里。然后从身后笼子里取出一只"+title[num]+NOR"放在地上。\n", ob);		
	me->set("Pet/class", pet->query("class"));
	me->set("Pet/exp", pet->query("combat_exp"));
	me->set("Pet/id", pet->query("id"));
	me->set("Pet/title", pet->query("title"));
	me->set("Pet/name", pet->query("name"));
	me->set("Pet/nickname", pet->query("nickname"));
	me->set("Pet/long", pet->query("long"));
	me->set("Pet/level", pet->query("level"));
	me->set("Pet/max_jing", pet->query("max_jing"));
	me->set("Pet/eff_jing", pet->query("eff_jing"));
	me->set("Pet/jing", pet->query("jing"));
	me->set("Pet/max_qi", pet->query("max_qi"));
	me->set("Pet/eff_qi", pet->query("eff_qi"));
	me->set("Pet/qi", pet->query("qi"));
	me->set("Pet/food", pet->query("food"));
	me->set("Pet/water", pet->query("water"));

	me->set("Pet/str", pet->query("str"));
	me->set("Pet/dex", pet->query("dex"));
	me->set("Pet/con", pet->query("con"));
	me->set("Pet/int", pet->query("int"));
	me->set("Pet/per", pet->query("per"));
	me->set("Pet/kar", pet->query("kar"));
	me->set("Pet/cor", pet->query("cor"));
	me->set("Pet/cps", pet->query("cps"));
	me->set("Pet/obe", pet->query("obe"));

	if(pet->query("last_age_set"))
		pet->add("mud_age", time()-pet->query("last_age_set"));
	else pet->add("mud_age", 1);
	me->set("Pet/mud_age", pet->query("mud_age"));
	me->set("Pet/weight", pet->query("weight"));
	me->set("Pet/gender", pet->query("gender"));
	me->set("Pet/wimpy", pet->query("env/wimpy"));

	me->set("Pet/unarmed", pet->query_skill("unarmed", 1));
	me->set("Pet/dodge", pet->query_skill("dodge", 1));
	me->set("Pet/parry", pet->query_skill("parry", 1));

	return 1;
}

int do_return()
{
	object me = this_player(), *ob;
	string file, id;
	int i;

	if(!me->query("Pet"))
		return notify_fail("老头呵呵乐了：“你就没养宠物，来这凑啥热闹来着？”\n");
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");
	id = me->query("id");
	ob = all_inventory(environment(me));
	for (i = 0; i < sizeof(ob); i++)
	{
		if(ob[i]->query("owner") == id && ob[i]->query("curiousness"))
		{
			break;
		}
	}
	if( i == sizeof(ob) )
		return notify_fail("老头奇怪地看了你一眼：“你的宠物没带来，那你怎么还给我啊？”\n");
	message_vision("$N一把抱起地上的$n，递过柜台还给老头。\n", me, ob[i]);
	me->delete("Pet");
	destruct(ob[i]);
	me->start_busy(1);
	return 1;
}
int do_lingqu()
{
	object pet, me = this_player(), ob = this_object(), *obj;
	int i;

	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");
	if(!me->query("Pet"))
	{
		command("say 这位"+RANK_D->query_respect(me)+"，你没暂存(zancun)过宠物，这里哪有东西可领取？”\n");
		return 1;
	}

	obj = objects();
	for (i=0; i<sizeof(obj); i++)
	{
		if(obj[i]->query("owner") == me->query("id") &&  //奸细也有owner
			obj[i]->query("curiousness"))
		{
			if(environment(obj[i]) == me )
				return notify_fail(ob->name()+ "说道：你不是正骑在你的宠物身上么？\n");
			else
				if(environment(obj[i]) != environment(me) )
					return notify_fail(ob->name()+"说道：你的宠物在"+(environment(obj[i])->query("outdoors") ? to_chinese(environment(obj[i])->query("outdoors")) : "哪里")+"的"+environment(obj[i])->query("short")+"，赶快去找吧。\n");
				else
					return notify_fail(ob->name()+ "说道：你的宠物不是就在你旁边么？\n");
			return 1;
		}
	}
	pet = new("/clone/misc/pet");

	pet->set("owner", me->query("id"));
	pet->set_temp("owner", me->query("id"));
	pet->set_temp("ownername", me->query("name"));

	pet->set("class", me->query("Pet/class"));
	pet->set("id", me->query("Pet/id"));
	pet->set("title", me->query("Pet/title"));
	pet->set("name", me->query("Pet/name"));
	pet->set("nickname", me->query("Pet/nickname"));
	pet->set("race", "野兽");
	pet->set_name(me->query("Pet/name"), ({me->query("Pet/id"), "pet"}));
	pet->set("long", me->query("Pet/long"));
	pet->set("level", me->query("Pet/level"));

	pet->set("str", me->query("Pet/str"));
	pet->set("dex", me->query("Pet/dex"));
	pet->set("con", me->query("Pet/con"));
	pet->set("int", me->query("Pet/int"));
	pet->set("per", me->query("Pet/per"));
	pet->set("kar", me->query("Pet/kar"));
	pet->set("cor", me->query("Pet/cor"));
	pet->set("cps", me->query("Pet/cps"));
	pet->set("obe", me->query("Pet/obe"));

	pet->set("combat_exp", me->query("Pet/exp"));
	pet->set("mud_age", me->query("Pet/mud_age"));
	pet->set("age", 1+me->query("Pet/mud_age")/86400);
	pet->set("weight", me->query("Pet/weight"));
	pet->set_weight(me->query("Pet/weight"));
	pet->set("gender", me->query("Pet/gender"));
	pet->set("env/wimpy", me->query("Pet/wimpy"));

	pet->set("max_jing", me->query("Pet/max_jing"));
	pet->set("eff_jing", me->query("Pet/eff_jing"));
	pet->set("jing", me->query("Pet/jing"));
	pet->set("max_qi", me->query("Pet/max_qi"));
	pet->set("eff_qi", me->query("Pet/eff_qi"));
	pet->set("qi", me->query("Pet/qi"));
	pet->set("food", me->query("Pet/food"));
	pet->set("water", me->query("Pet/water"));

        pet->set("curiousness", 1);
	pet->set("last_age_set", time());

	pet->set_skill("unarmed", me->query("Pet/unarmed"));
	pet->set_skill("dodge", me->query("Pet/dodge"));
	pet->set_skill("parry", me->query("Pet/parry"));

	addaction(pet);

	pet->move(environment(me));
	message_vision("$N从身后笼子里取出一只"+pet->name()+"放在地上。\n", ob);
	me->start_busy(1);
	return 1;
}

int do_zancun()
{
	object me = this_player(), *ob;
	string file, id;
	int i;

	if(!me->query("Pet"))
		return notify_fail("老头呵呵乐了：“你就没养宠物，来这凑啥热闹来着？”\n");
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");
	id = me->query("id");
	ob = all_inventory(environment(me));
	for (i = 0; i < sizeof(ob); i++)
	{
		if(ob[i]->query("owner") == id && ob[i]->query("curiousness"))
		{
			break;
		}
	}
	if( i == sizeof(ob) )
		return notify_fail("老头奇怪地看了你一眼：“你的宠物没带来，暂存啥啊？”\n");
	if(ob[i]->query_temp("feeded"))
		return notify_fail(ob[i]->name()+"刚吃了东西，懒洋洋的不想理你。\n");

	me->set("Pet/class", ob[i]->query("class"));
	me->set("Pet/exp", ob[i]->query("combat_exp"));
	me->set("Pet/id", ob[i]->query("id"));
	me->set("Pet/title", ob[i]->query("title"));
	me->set("Pet/name", ob[i]->query("name"));
	me->set("Pet/nickname", ob[i]->query("nickname"));
	me->set("Pet/long", ob[i]->query("long"));
	me->set("Pet/level", ob[i]->query("level"));
	me->set("Pet/max_jing", ob[i]->query("max_jing"));
	me->set("Pet/eff_jing", ob[i]->query("eff_jing"));
	me->set("Pet/jing", ob[i]->query("jing"));
	me->set("Pet/max_qi", ob[i]->query("max_qi"));
	me->set("Pet/eff_qi", ob[i]->query("eff_qi"));
	me->set("Pet/qi", ob[i]->query("qi"));
	me->set("Pet/food", ob[i]->query("food"));
	me->set("Pet/water", ob[i]->query("water"));

	me->set("Pet/str", ob[i]->query("str"));
	me->set("Pet/dex", ob[i]->query("dex"));
	me->set("Pet/con", ob[i]->query("con"));
	me->set("Pet/int", ob[i]->query("int"));
	me->set("Pet/per", ob[i]->query("per"));
	me->set("Pet/kar", ob[i]->query("kar"));
	me->set("Pet/cor", ob[i]->query("cor"));
	me->set("Pet/cps", ob[i]->query("cps"));
	me->set("Pet/obe", ob[i]->query("obe"));

	if(ob[i]->query("last_age_set"))
		ob[i]->add("mud_age", time()-ob[i]->query("last_age_set"));
	else ob[i]->add("mud_age", 1);
	me->set("Pet/mud_age", ob[i]->query("mud_age"));
	me->set("Pet/weight", ob[i]->query("weight"));
	me->set("Pet/gender", ob[i]->query("gender"));
	me->set("Pet/wimpy", ob[i]->query("env/wimpy"));

	me->set("Pet/unarmed", ob[i]->query_skill("unarmed", 1));
	me->set("Pet/dodge", ob[i]->query_skill("dodge", 1));
	me->set("Pet/parry", ob[i]->query_skill("parry", 1));

// 取消跟随状态
	me->delete_temp("comedby");

	message_vision("$N一把抱起地上的$n，递过柜台给老头暂存。\n", me, ob[i]);
	destruct(ob[i]);
	me->start_busy(1);
	return 1;
}

