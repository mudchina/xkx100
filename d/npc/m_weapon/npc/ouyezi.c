// npc: /d/npc/m_weapon/npc/tianjianshi.c
// Last Modified by winder on Feb. 28 2001
// Modified by sir 4/13/2001

#include <ansi.h>
inherit NPC;

int do_weapon();
int do_give_weapon(object me);
object creat_weapon();

void create()
{
	set_name("欧冶子", ({ "ouye zi", "zi" }) );
	set("nickname", RED "赤心剑胆" NOR );
	set("gender", "男性" );
	set("age", 60);
	set("no_get", 1);
	set("long", "他头上包着头巾，三缕长髯飘洒胸前，面目清瘦但红晕有光，\n"
		"二目炯炯有神，烁烁闪着竟似是凛凛的剑光，浑身似乎都包围\n"
		"在一股剑气之中。\n");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 30);
	set("shen_type", 0);
	set("max_neli",5000);
	set("jiali",50);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("claw",200);
	set_skill("jiuyin-baiguzhao",200);
	set_skill("force",150);
	set_skill("sword",150);
	set_skill("bibo-shengong",100);
	set_skill("luoying-shenjian",100);
	set_skill("parry",90);
	set_skill("anying-fuxiang",100);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",50);

	set("combat_exp", 250000);
	set("score",0);
	
	map_skill("force","bibo-shengong");
	map_skill("parry","luoying-shenjian");
	map_skill("sword","luoying-shenjian");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("dodge","anying-fuxiang");
	
	set("attitude", "peaceful");
	
	set("inquiry", ([
		"铸剑" : "铸剑可是件十分艰苦的事，要消耗人的精气和内力，你有决心和毅力吗？\n",
		"原料" : "铸剑可用千年玄铁。。。你找到了我才能帮你铸剑。\n",
		"兵器" : (: do_weapon() :),
	]) );

	setup();
	set("chat_chance", 3);
	set("chat_msg", ({
		"欧冶子抚剑而歌：巨阙神兵兮，人铸就。盖世宝剑兮，配英雄！\n",
		"欧冶子低头沉吟，似乎在思考什么。\n"
		"欧冶子叹了一口气：神兵配英雄，可英雄。。。。。。\n"
	}) );
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	::init();
	add_action("do_answer","answer");
}

int accept_object(object who, object ob)
{	
	switch ((string)ob->query("name") ) 
	{
		case "倭刀" :
		case "叫化鸡" :
		case "羊皮书":
		case "软剑":
		case "辟邪剑谱":
			if( (who->query_temp("condition")) != (string)ob->query("name") )
			{
				message_vision(HIC "欧冶子一愣：我对你说过我要这样东西么？\n" NOR, who);
				return 0;
			}
			else
			{
				who->delete_temp("condition");
				message_vision(HIG "欧冶子微笑着：很好很好！那我就帮你这一次吧！\n" NOR, who);
				who->set_temp("condition_ok",1);
				destruct(ob);
				do_give_weapon(who);
				return 1;
			}
	}
	if((int)(who->query("weapon/make")) )
	{
		say("欧冶子一脸茫然：您已经有一把自造的武器了，还来干什么？难到不合手么？\n");
		return 0;
	}
	switch ((string)ob->query("id") ) 
	{
		case "shen mu": 
			who->set_temp("or",1);
			who->set_temp("get_orc",1);
			break;
		case "jin mu":
			who->set_temp("or",2);
			who->set_temp("get_orc",1);
			break;
		case "han zhu": 
			who->set_temp("or",3);
			who->set_temp("get_orc",1);
			break;
		case "iron stone": 
			who->set_temp("or",4);
			who->set_temp("get_orc",1);
			break;
		default :
			message("vision","这是什么！这不能用来打造兵器！",who);
			return 0;
	}
	message("vision", "欧冶子低头检视了一下手中的"+(string)ob->query("name")+"点了点头说：\n",who);
	write("我这儿可以打造以下兵器：\n"+
		"     剑(sword)\n"+
		"     刀(blade)\n"+
		"     枪(spear)\n"+
		"     棍(club)\n"+
		"     棒(stick)\n"+
		"     杖(staff)\n"+
		"     锤(hammer)\n"+
		"     钩(hook)\n"+
		"     斧(axe)\n"+
		"     鞭(whip)\n");	  	
	say("这位"+RANK_D->query_respect(who)+"要造什么兵器？决定了告诉我(answer)。\n");
	return 2;

}

int do_answer(string arg)
{
	object me,w_or;
	me = this_player();
	if(!(me->query_temp("get_orc") ) )
	{
//		write("你找到原料了吗？\n");
		return 0;
	}
	
	if(!arg)
	{
		write("你要造什么兵器？\n");
		return 0;
	}

	message("vision",me->name()+"对欧冶子轻声说了几句。\n",environment(me), ({me}) );
	switch (arg)
	{
		case "sword" :
			me->add_temp("sword",1);
			write("带着原料去找侍剑吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "blade" :
			me->add_temp("blade",1);
			write("带着原料去找侍刀吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "spear" :
			me->add_temp("spear",1);
			write("带着原料去找侍枪吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "club" :
			me->add_temp("club",1);
			write("带着原料去找侍棍吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "stick" :
			me->add_temp("stick",1);
			write("带着原料去找侍棒吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "staff" :
			me->add_temp("staff",1);
			write("带着原料去找侍杖吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "axe" :
			me->add_temp("axe",1);
			write("带着原料去找侍斧吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "hammer" :
			me->add_temp("hammer",1);
			write("带着原料去找侍锤吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "hook" :
			me->add_temp("hook",1);
			write("带着原料去找侍钩吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "whip" :
			me->add_temp("whip",1);
			write("带着原料去找侍鞭吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		default :
			message_vision(HIC"欧冶子一脸狐疑：什么兵器？\n"NOR,me);
			return notify_fail("欧冶子仔细的说：此事不可儿戏，请慎重！！\n");
	}
	switch ( me->query_temp("or") )
	{
		case 1:
//			w_or = new("/d/npc/m_weapon/tan/item/shenmu",1);
//			w_or->move(me);			
//			message_vision(HIC"欧冶子给了$N一块千年神木。\n"NOR,me);
		command("give shen mu to "+me->query("id"));
			break;
		case 2:
//			w_or = new("/d/npc/m_weapon/tan/item/jinmu",1);
//			w_or->move(me);
//			message_vision(HIC"欧冶子给了$N一块海底金母。\n"NOR,me);
		command("give jin mu to "+me->query("id"));
			break;
		case 3:
//			w_or = new("/d/npc/m_weapon/tan/item/hanzhu",1);
//			w_or->move(me);
//			message_vision(HIC"欧冶子给了$N一块寒丝羽竹。\n"NOR,me);
		command("give han zhu to "+me->query("id"));
			break;
		case 4:
//			w_or = new("/d/qilian/obj/ironstone",1);
//			w_or->move(me);
//			message_vision(HIC"欧冶子给了$N一块陨星铁石。\n"NOR,me);
		command("give iron stone to "+me->query("id"));
			break;
	}

	me->delete_temp("get_orc");
	return 1;
}

int do_weapon()
{
	object me,obj;
//object weapon;	
	string w_id;
	me = this_player();
	w_id = me->query("weapon/id");
	if( !(me->query("weapon/make")) )
		return notify_fail("你造过兵器吗？\n");

	if( objectp(obj = present(w_id, me)) )
	{
		say("欧冶子脸色一沉：您的武器不就在你手边么？还来干什么！\n");
		return 1;
	}
	if (me->query_temp("condition") )
	{
		say("欧冶子脸色一沉：不是让你去拿"+(me->query_temp("condition") )+
"了么？还没拿到回来干嘛！\n");
		return 1;
	}

	if( !(me->query_temp("condition_ok")) )
	{
		message_vision(HIY"这位"+RANK_D->query_respect(me)+"想要重新得到兵器？这不难。不过......\n" NOR, me);
		message_vision(HIY"欧冶子沉吟了一下说：你得找到我要的东西。\n" NOR, me);
		switch( random(5) )
		{
			case 0:
				message_vision("拿到倭刀，再来吧！\n",me);
				me->set_temp("condition","倭刀");
				break;
			case 1:
				message_vision("给我叫化鸡，我就帮你！！\n",me);
				me->set_temp("condition","叫化鸡");
				break;
			case 2:
				message_vision("嗯..你就拿羊皮书来换吧！\n",me);
				me->set_temp("condition","羊皮书");
				break;
			case 3:
				message_vision("..我想看看软剑！\n",me);
				me->set_temp("condition","软剑");
				break;
			case 4:
				message_vision("如果你能替我找到辟邪剑谱的话......\n",me);
				me->set_temp("condition","辟邪剑谱");
				break;
		}
	}
	return 1;
}
int do_give_weapon(object me)
{
		object weapon;
		object *obs;
		int i;
		object env;
		string env_name;
    string area;
    

		
		me->delete_temp("condition_ok");
		obs = children("/d/npc/m_weapon/weapon/m_weapon");
		for (i=0;i<sizeof(obs);i++)
		{
			if (obs[i]->query("owner")==me->query("id"))
			{
				if (!environment(obs[i])) continue;
				env = environment(obs[i]);
        sscanf(base_name(env),"/%*s/%s/%*s",area);
        area=to_chinese(area);
				if (env->is_character())
				  env_name = env->query("name")+"手中";
				else
				  env_name = env->query("short");				
			  if (!userp(env))
			    env_name = area +"的" + env_name;
			  message_vision("$N说道：你的"+obs[i]->query("name")+
			  "在"+ env_name+"，快去找吧。\n",this_object());
			  return 1;
			}
		}
		
		weapon = creat_weapon();
		weapon->move(me);
		return 1;
}

object creat_weapon()
{
	object me,weapon;
	string mask;	//the verible that record the type of weapon
	me = this_player();
	mask = me->query("weapon/type");
	weapon = new("/d/npc/m_weapon/weapon/m_weapon",1);
	return weapon;
/*
	switch(mask)
	{
		case "剑":
			weapon = new("/d/npc/m_weapon/weapon/m_sword",1);
			return weapon;
		case "刀":
			weapon = new("/d/npc/m_weapon/weapon/m_blade",1);
			return weapon;
		case "枪":
			weapon = new("/d/npc/m_weapon/weapon/m_spear",1);
			return weapon;
		case "棍":
			weapon = new("/d/npc/m_weapon/weapon/m_club",1);
			return weapon;
		case "棒":
			weapon = new("/d/npc/m_weapon/weapon/m_stick",1);
			return weapon;
		case "杖":
			weapon = new("/d/npc/m_weapon/weapon/m_staff",1);
			return weapon;
		case "锤":
			weapon = new("/d/npc/m_weapon/weapon/m_hammer",1);
			return weapon;
		case "钩":
			weapon = new("/d/npc/m_weapon/weapon/m_hook",1);
			return weapon;
		case "鞭":
			weapon = new("/d/npc/m_weapon/weapon/m_whip",1);
			return weapon;
		case "斧":
			weapon = new("/d/npc/m_weapon/weapon/m_axe",1);
			return weapon;
	}
*/
}
