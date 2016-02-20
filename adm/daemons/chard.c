// chard.c
// From ES2
// Modified by Xiang@XKX 
// Modified by winder@XKX100

#include <ansi.h> 
#define HUMAN_RACE "/adm/daemons/race/human"
#define BEAST1_RACE "/adm/daemons/race/beast1"
#define BEAST_RACE "/adm/daemons/race/beast"
#define MONSTER_RACE "/adm/daemons/race/monster"
#define STOCK_RACE "/adm/daemons/race/stock"
#define BIRD_RACE "/adm/daemons/race/bird"
#define FISH_RACE "/adm/daemons/race/fish"
#define SNAKE_RACE "/adm/daemons/race/snake"
#define INSECT_RACE "/adm/daemons/race/insect"

 
void create() { seteuid(getuid()); }  
 
void setup_char(object ob)
{
	string race;
	mapping my;
 
	if( !stringp(race = ob->query("race")) )
	{
		race = "人类";	
		ob->set("race", "人类");
	}
	switch(race)
	{
		case "人类":
			HUMAN_RACE->setup_human(ob);
			break;	
		case "妖魔":
			MONSTER_RACE->setup_monster(ob);
			break;	
		case "野兽":
			BEAST1_RACE->setup_beast(ob);
			break;	
		case "走兽": /* 肉食有爪 */
			BEAST_RACE->setup_beast(ob);
			break;	
		case "走畜": /* 草食用蹄 */
			STOCK_RACE->setup_stock(ob);
			break;
		case "飞禽":
			BIRD_RACE->setup_bird(ob);
			break;
		case "游鱼":
			FISH_RACE->setup_fish(ob);
			break;
		case "爬蛇":
			SNAKE_RACE->setup_snake(ob);
			break;
		case "昆虫":
			INSECT_RACE->setup_insect(ob);
			break;
		default: 
			error("Chard: undefined race " + race + ".\n");
	}
/* 为通用兽类保留 */
	if (race != "人类" && ! ob->query("dead_message"))
	{
		ob->set("dead_message", "\n$N仰天惨嚎了一声，趴在地上不动了。\n\n");
		ob->set("unconcious_message", "\n$N低低地吼了一声，滚倒在地了过去。\n\n");
		ob->set("revive_message", "\n$N四肢慢慢动弹了一下，睁开眼醒了过来。\n\n");
		ob->set("comeout_message", "往$d奔了过去。\n");
		ob->set("comein_message", "呼地窜了出来，警惕地四周张望着。\n");
		ob->set("fleeout_message", "惨叫一声，往$d落荒而逃。\n");
		ob->set("fleein_message", "摇摇摆摆地跑了过来，伸出舌头呼呼地喘着粗气。\n");
	} 
	my = ob->query_entire_dbase();
	if( undefinedp(my["pighead"]) ) my["pighead"] = 0;
// 玩家的这个判断改在updated.c中做。这里不必做 
	if( !userp(ob) )
	{
		if( undefinedp(my["jing"]) ) my["jing"] = my["max_jing"];
		if( undefinedp(my["qi"]) ) my["qi"] = my["max_qi"];
		if( undefinedp(my["jingli"]) ) my["jingli"] = my["max_jingli"];
		if( undefinedp(my["eff_jing"]) || my["eff_jing"] > my["max_jing"])
			my["eff_jing"] = my["max_jing"];
		if( undefinedp(my["eff_qi"]) || my["eff_qi"] > my["max_qi"])
			my["eff_qi"] = my["max_qi"];
	}
// avoid excess neili	 
	if (userp(ob))
//	if (userp(ob) && (int)ob->query_skill("force") > (int)ob->query_skill("force", 1)) 
	{
		if( ob->query_skill("force",1) < 1 )
		{
			my["max_neili"] = 0;
			my["neili"] = 0;
		}
		else
		if( !stringp(ob->query_skill_mapped("force")) )
		{
			if (my["max_neili"]>(int)ob->query_skill("force",1)*15)
			       my["max_neili"] = ob->query_skill("force",1)*15;
			if (my["neili"] > my["max_neili"])
				my["neili"] = my["max_neili"]; 
		}
		else // 内力和精力
		{
			if (my["max_neili"] > ((int)ob->query_skill("force")*10 + (int)ob->query("gift/max_neili")))
				my["max_neili"] = ob->query_skill("force")*10+(int)ob->query("gift/max_neili");
			if (my["neili"] > my["max_neili"])
				my["neili"] = my["max_neili"]; 
				
			if (my["max_jingli"] > ( (int)ob->query_skill("taoism") * 10+(int)ob->query("gift/max_jingli")))
				my["max_jingli"] = ob->query_skill("taoism") * 10+(int)ob->query("gift/max_jingli");
			if (my["jingli"] > my["max_jingli"])
				my["jingli"] = my["max_jingli"];
		}
		
		if ((my["potential"]-my["learned_points"])>100000)
			my["potential"] =my["learned_points"]+100000;
    if( my["shen"]>1000000) 	my["shen"]	=	 1000000;
    if( my["shen"]<-1000000) 	my["shen"]	=	-1000000;
    if( my["score"]>100000) 	my["score"]	=	 100000;
	}
	else my["bt_tufei"] = random(30) + 1; /* 巡捕任务之NPC设定 */

	if( undefinedp(my["shen_type"]) ) my["shen_type"] = 0;
 
	if( undefinedp(my["shen"]) ) {
		if (userp(ob))	
			my["shen"] = 0;
		else
			my["shen"] = my["shen_type"] * my["combat_exp"] / 10;
	}

	if( undefinedp(my["behavior_exp"]) ) my["behavior_exp"] = my["shen"];
	if( undefinedp(my["quest_exp"]) ) my["quest_exp"] = my["age"] * 10;

 
	if( !ob->query_max_encumbrance() ) 
		ob->set_max_encumbrance( my["str"] * 5000  +
			(ob->query_str() - my["str"]) * 1000);
 
	ob->reset_action();
}
 
varargs object make_corpse(object victim, object killer)
{
	int i;
	object corpse, mengzhu, room, *inv;
 
	if( victim->is_ghost() ) {    
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });       
		i = sizeof(inv);      
		while(i--) inv[i]->move(environment(victim)); 
		return 0;
	}
 
	corpse = new(CORPSE_OB);      
	corpse->set_name( victim->name(1) + "的尸体", ({ "corpse" }) );
	corpse->set("long", victim->long() 
		+ "然而，" + gender_pronoun(victim->query("gender"))
		+ "已经死了，只剩下一具尸体静静地躺在这里。\n");
	corpse->set("age", victim->query("age")); 
	corpse->set("gender", victim->query("gender"));
	corpse->set("victim_name", victim->name(1));
	corpse->set("victim_id", victim->query("id"));
	corpse->set("victim_user", userp(victim));
	corpse->set("victim_exp", victim->query("combat_exp"));
	corpse->set("victim_shen", victim->query("shen"));
	corpse->set("kill_by", victim->query_temp("last_damage_from"));
	if (victim->query_temp("faint_by")) corpse->set("kill_by", victim->query_temp("faint_by"));
	else corpse->set("kill_by", killer);
	if (userp(victim)) corpse->set("userp", 1);
	victim->set_temp("die_by_from",corpse->query("kill_by"));
	corpse->set_weight( victim->query_weight() );
	corpse->set_max_encumbrance( victim->query_max_encumbrance() );
	corpse->move(environment(victim)); 
 
// Don't let wizard left illegal items in their corpses.
	if( !wizardp(victim) ) {      
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });       
		i = sizeof(inv);      
		while(i--) {
			if( strsrch(inv[i]->query("name"), "碎片") >= 0)
				inv[i]->move(environment(victim));
			else
			if( (string)inv[i]->query("equipped")=="worn" ) { 
				inv[i]->move(corpse);
				if( !inv[i]->wear() ) inv[i]->move(environment(victim));
			}
			else inv[i]->move(corpse);
		} 
	}
	return corpse;
}

int break_relation(object player)
{
	object ob, room;
	string std_id = player->query("id");

	if (player->query("family/family_name") == "华山派" )
	{
		if(!( room = find_object("/d/huashan/xiaofang")) )
			room = load_object("/d/huashan/xiaofang");
		ob = present("feng qingyang", room);
		player->delete("family");
		player->set("title","普通百姓");
		tell_object(player, RED "\n你已非风清扬的弟子了，好自为之吧！\n\n" NOR);
		ob->delete( "students/"+std_id );
		ob->set( "pending", std_id );
		ob->save();
//		ob->restore();
	}

	return 1;
}
