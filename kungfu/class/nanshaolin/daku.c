// Last Modified by Winder on May. 29 2001
// Npc: /kungfu/class/nanshaolin/daku.c

#include "/kungfu/class/nanshaolin/da.h"
#include "ansi.h"
inherit NPC;
inherit F_MASTER;
string ask_me();
int do_zhongcai(string arg);

void create()
{
	set_name("大苦大师", ({ "daku dashi", "daku", "dashi"}));
	set("long",
		"他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，\n"
		"太阳穴微凸，双目炯炯有神。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 2000);
	set("max_jing", 1200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali",200);
	set("combat_exp", 1000000);
	set("score", 5000);

	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 150);
	set_skill("force", 150);
	set_skill("zhanzhuang-gong", 150);
	set_skill("dodge", 150);
	set_skill("yiwei-dujiang", 220);
// basic skill begin
	set_skill("shaolin-cuff", 220);
	set_skill("luohan-cuff", 220);
	set_skill("weituo-strike", 220);
	set_skill("sanhua-strike", 220);
	set_skill("boluomi-hand", 220);
	set_skill("jingang-strike", 220);
	set_skill("nianhua-finger", 220);
	set_skill("boruo-strike", 220);
// basic skill end
// 鞭和拳
	set_skill("cuff", 150);
	set_skill("jingang-cuff", 220);
	set_skill("whip", 150);
	set_skill("jiujie-whip", 220);
	set_skill("xiangmo-whip", 220);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "jingang-cuff");
	map_skill("whip", "xiangmo-whip");
	map_skill("parry", "xiangmo-whip");

	prepare_skill("cuff", "jingang-cuff");
	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		
		(: exert_function, "roar" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("南少林派", 19, "僧监");
	set("inquiry", 
	([
		"轮值" : (: ask_me :),
	]));
	setup();
	carry_object(WEAPON_DIR+"whip/whip")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
	add_action("do_lunzhi","lunzhi");
	add_action("do_zhongcai","zhongcai");
}
string ask_me()
{
	mapping fam; 
	object me;
	object ob;
	ob=this_player();
	me=this_object();
	if(!(fam = this_player()->query("family")) ||
		fam["family_name"] != "南少林派")
		return RANK_D->query_respect(ob)+"，你不是本寺弟子，不能轮值！";
	if((string)ob->query("class")!="bonze")
		return ("俗家弟子不能轮值。");
	if(ob->query("combat_exp")>=50000 || 
		ob->query("potential") > 20000)
		return("我看你的武功已有相当的功底了，就把轮值的机会让给师弟们吧。\n");
	if(me->query_temp("lunzhi"))
		return ("现在已有人轮值了，你就等下一次吧。\n");
	me->set("lunzhi_name",ob->query("name"));
	me->set_temp("lunzhi",1);
	ob->set_temp("lunzhi",1);
	ob=new(__DIR__"obj/lunzhi-ling");
	ob->move(this_player());
	write("大苦大师给你一块轮值令。\n");
	return "好吧，你就到迎客亭把令交给方通吧，轮值时应当小心防范，防止外敌偷入寺中。";
}
int do_lunzhi(string arg)
{
	object ob,me;
	ob=this_player();
	me=this_object();
	if(!(arg)) return 0;
	if(!(arg=="ok")) return 0;
	if(!ob->query_temp("lunzhi")) return 0;
	if(!ob->query_temp("lunzhied")) return 0;
	if(ob->query("name")==me->query("lunzhi_name")) 
	{
		if (interactive(ob) && (int)ob->query_condition("sl_lunzhi"))
		{
			command("angry"+ob->query("id"));
			command("slap"+ob->query("id"));
			return notify_fail( "大苦大师大怒道："RED"想偷懒，快给我滚回去。\n"NOR);
		}
		command("pat "+ob->query("id"));
		command("say 哈哈，真难为你了，"+RANK_D->query_respect(ob)+"，干得好！");
		ob->add("potential",(int)(ob->query_skill("buddhism",1)/10)+30);
		ob->add("combat_exp",(int)(ob->query_skill("buddhism",1)/4)+90);
		me->delete("lunzhi_name");
		me->delete_temp("lunzhi");
		ob->delete_temp("lunzhi");
		ob->delete_temp("lunzhied");
		return 1;
	}
	return notify_fail("大苦大师苦着脸说：我被杀了，你轮值的记录没有了！\n");
}

int do_zhongcai(string arg)
{
	object ob=this_player(), me=this_object();

	if(!arg || arg != "ok") return 0;
	if(!ob->query_temp("mark/浇完")) return 0;
	{
		command("pat "+ob->query("id"));
		command("say 辛苦了！");
		ob->add("potential",(int)(ob->query_skill("buddhism",1)/10)+30);
		ob->add("combat_exp",(int)(ob->query_skill("buddhism",1)/4)+90);
		ob->delete_temp("job_name");
		ob->delete_temp("mark/浇完");
		return 1;
	}
	return notify_fail("方相问道：你刚才进去服侍方丈了？\n");
}

