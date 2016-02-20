// guo.c 郭襄
// Modified by Winder Jul.2000
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_quit();
mixed out_master(mixed arg);

void create()
{
	set_name("郭襄", ({ "guo xiang","guo","xiang"}));
	set("long",
"她十八九岁年纪，身穿淡黄衣衫，骑着一头青驴，正缓缓而行。
她腰悬短剑，脸上颇有风尘之色，显是远游已久；韶华如花，正
当喜乐无忧之年，可是容色间却隐隐有懊闷意，似是愁思袭人，
眉间心上，无计回避。她姓郭，单名一个襄字，乃大侠郭靖和女
侠黄蓉的次女，现下她一驴一剑，只身漫游，排遣心中愁闷。\n"); 
	set("gender", "女性");
	set("nickname", "小东邪");
	set("age", 18);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("shen", 100000);
	set("class", "bonze");
	set("env/wimpy", 60);

	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("per", 20);

	set("max_qi", 4000);
	set("max_jing", 2000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jingli", 1500);
	set("max_jingli", 1500);
	set_temp("is_riding", HIC"青驴"NOR);
	set("combat_exp", 3000000);
	set("score", 1000);
	set("chat_chance", 10);
	set("chat_msg", ({
		"郭襄低声吟道：「问世间，情是何物，直教生死相许？」\n",
		"郭襄低声吟道：「天南地北双飞客，老翅几回寒暑？」\n",
		"郭襄低声吟道：「欢乐趣，离别苦，就中更有痴儿女。」\n",
		"郭襄低声吟道：「君应有语，渺万里层云，千山暮雪，只影向谁去？」\n",
		"郭襄低声吟道：「横汾路，寂寞当年箫鼓。荒烟依旧平楚。」\n",
		"郭襄低声吟道：「招魂些何嗟及，山鬼自啼风雨。」\n",
		"郭襄低声吟道：「天也妒，未信与，莺儿燕子俱黄土。」\n",
		"郭襄低声吟道：「千秋万古，为留待骚人，狂歌痛饮，来访雁丘处。」\n",
		(: random_move :)
	}) );

	set_skill("persuading", 150);
	set_skill("throwing", 200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("finger", 200);
	set_skill("parry", 200);
	set_skill("strike", 200);
	set_skill("sword", 200);
	set_skill("blade", 200);
	set_skill("literate", 100);
	set_skill("mahayana", 200);
	set_skill("buddhism", 200);
	set_skill("jinding-zhang", 300);
	set_skill("tiangang-zhi", 300);
	set_skill("huifeng-jian", 300);
	set_skill("yanxing-dao", 300);
	set_skill("zhutian-bu", 300);
	set_skill("linji-zhuang", 200);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("blade","yanxing-dao");
	map_skill("parry","huifeng-jian");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mie" :),
//		(: perform_action, "blade.wuxing" :),
		(: perform_action, "strike.bashi" :),
		(: perform_action, "finger.lingkong" :),		
		(: exert_function, "powerup" :),				
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );
	create_family("峨嵋派", 1, "掌门人");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"female-cloth")->wear();
	carry_object(CLOTH_DIR"female-shoe")->wear();
	carry_object(__DIR__"obj/donkey");
}

void attempt_apprentice(object ob)
{
	mapping ob_fam;
	mapping my_fam = ob->query("family");
	string name, new_name;
	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "峨嵋派")
	{
		command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
		return;
	}
	if ((string)ob->query("class")!="bonze" )
	{
		command ("say 我不收俗家弟子。");
		return;
	}
	if ((int)ob->query_skill("mahayana",1)<150||
		(int)ob->query_skill("linji-zhuang",1)<150)
	{
		command("say 你本门的功夫修为还太低。");
		return;
	}
	if ((int)ob->query("shen") < 500000)
	{
		command("say "+RANK_D->query_respect(ob)+"你行侠仗义之事还做的不够。");
		return;
	}
	if ((string)ob->query("class")=="bonze" )
	{
		name = ob->query("name");
		new_name = "风" + name[2..3];
		ob->set("name", new_name);
		command("say 从今以后你的法名叫做" + new_name + "，恭喜你成为峨嵋第三代弟子!");
	}
	command("recruit " + ob->query("id"));
}

