// Npc: /d/lingxiao/npc/shi.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("时万年",({"shi wannian","shi",}));
	set("gender", "男性");
	set("age", 20);
	set("long", "他是凌霄城第六代弟子时万年，在此守卫监狱。\n");
	set("attitude", "peaceful");

	set("no_get", 1);
	set("str", 30);
	set("con", 30);
	set("int", 24);
	set("dex", 30);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jing", 800);
	set("max_jing", 800);
	set("qi", 1500);
	set("max_qi", 1500);

	set("combat_exp", 250000); 
	set("shen_type", 0);
	set("score", 20000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );
	set("chat_chance", 5);
	set("chat_msg", ({
	"时万年恨恨说道：老疯子不知道又怎么了，把自己关在里面弄死不肯出来。\n", 
	"时万年把剑一弹，傲然道：有我守在这，谁都别想把老疯子放出来。\n", 
	}) );
	set_skill("strike", 120);
	set_skill("sword", 150);
	set_skill("force", 120);
	set_skill("parry", 120);
	set_skill("dodge", 150);
	set_skill("literate", 80);

	set_skill("xueshan-sword", 150);
	set_skill("bingxue-xinfa", 120);
	set_skill("snow-strike", 120);
	set_skill("snowstep", 120);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("凌霄城", 6, "弟子");
	setup();
	
	carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
} 
void init()
{ 
	object ob;
	::init();

	ob = this_player();
	if(ob->query("family/family_name") !="凌霄城")
	{
		command("heng");
		command("say 你居然敢闯入本派禁地，受死吧！\n");
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
	else
		if(ob->query("family/master_id")=="bai zizai")
		{
			command( "say 师兄回来了，快去见掌门人吧，不过小心点……没准他又犯病了。");
		} 
		else
			if(ob->query("family/master_id")=="bai wanjian")
			{
				command( "say 你是白师哥的弟子吧，快进去见见老爷子吧，他的病越来越不得了啦。");
			}
}

