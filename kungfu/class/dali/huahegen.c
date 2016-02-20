// huahegen.c 华赫艮

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("华赫艮", ({ "hua hegen", "hua" }));
	set("title",  "大理司徒" );
	set("long", "他是大理国三大公之一。
华司徒本名阿根，出身贫贱，现今在大理国位列三公，未发迹时，干
部的却是盗墓掘坟的勾当，  最擅长的本领是偷盗王公巨贾的坟墓。这些富贵人物
死后，必有珍异宝物殉葬，华阿根从极远处挖掘地道，通入坟墓，然后盗取宝物。
所花的一和虽巨，却由此而从未为人发觉。有一次他掘入一坟，在棺木中得到了一
本殉葬的武功秘诀，依法修习，练成了一身卓绝的外门功夫，便舍弃了这下贱的营
生，辅佐保定帝，累立奇功，终于升到司徒之职。\n");
	set("gender", "男性");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	set("env/wimpy", 60);	
	
	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 750000);
	set("score", 200000);

        set_skill("force", 80);
        set_skill("dodge", 90);
        set_skill("parry", 80);
        set_skill("cuff", 95);
        set_skill("sword", 80);
        set_skill("staff", 80);
	set_skill("kurong-changong", 80);
        set_skill("tiannan-step", 135);
        set_skill("jinyu-quan", 145);
        set_skill("duanjia-sword", 120);
	set_skill("literate", 60);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jingtian" :),				
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );


	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 20);

	create_family("大理段家",19,"武将");
}

int accept_object(object who, object ob)
{
	object tool;
	if (ob->id("axiang letter")) 
	{
		tell_object(who, "你给华赫艮一封阿祥的信。\n");
		tell_object(who, "华赫艮拆开信看了看，点头说道：“既然是阿祥写信来，我就把东西给你吧。”\n");
		destruct(ob);
		tool = new("/d/suzhou/npc/obj/diggertools");
		tool->move(who);
		tell_object(who, "华赫艮给你一套盗墓工具。\n");
		return notify_fail("华赫艮收了阿祥的信。");
	}
	return 0;
}

