// Npc: /kungfu/class/nanshaolin/fangqiong.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;
string ask_for_join();

void create()
{
	set_name("方穷", ({ "fang qiong", "fang", "qiong"}));
	set("long", "他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，身手却已相\n"
		"当矫捷，看来似乎学过一点武功。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);

	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("zhanzhuang-gong", 50);
	set_skill("dodge", 50);
	set_skill("yiwei-dujiang", 50);
	set_skill("cuff", 50);
	set_skill("shaolin-cuff", 50);
	set_skill("luohan-cuff", 50);
	set_skill("hand", 50);
	set_skill("fengyun-hand", 50);
	set_skill("staff", 50);
	set_skill("pudu-staff", 50);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "luohan-cuff");
	map_skill("hand", "fengyun-hand");
	map_skill("staff", "pudu-staff");
	map_skill("parry", "pudu-staff");
	prepare_skill("cuff", "luohan-cuff");
	prepare_skill("hand", "fengyun-hand");

	set("inquiry",([
		"剃度" : (: ask_for_join :),
		"出家" : (: ask_for_join :),
	]));
	create_family("南少林派", 21, "弟子");

	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(WEAPON_DIR+"staff/chanzhang")->wield();
}

void init()
{
	add_action("do_kneel", "kneel");
}

string ask_for_join()
{
	object me = this_player();

	if( (string)me->query("class")=="bonze" )
		return "阿弥陀佛！你我同是出家人，何故跟贫僧开这等玩笑？\n";
	if( (string)me->query("gender") != "男性" )
		return "阿弥陀佛！善哉！善哉！女施主若真心仰慕南少林，可以做本院俗家弟子。\n";
	me->set_temp("pending/join_bonze", 1);
	return "阿弥陀佛！施主若真心皈依我佛，请跪下(kneel)受戒。\n";
}
int do_kneel()
{
	object me = this_player();
	string *prename = ({ "正", "方", "元", "大" });
	string name, new_name;
	int gen;

	if( !me->query_temp("pending/join_bonze") ) return 0;
	message_vision("$N双手合十，恭恭敬敬地跪了下来。\n\n$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n", me, this_object() );
	name = me->query("name");
	if (me->query("family/family_name") == "南少林派")
		gen = me->query("family/generation");
	else gen = 22;
	new_name = prename[22-gen] + name[0..1];
	command("say 从今以后你的法名叫做" + new_name + "。");
	command("smile");
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set("class", "bonze");
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));
	me->set("shen", 0);
	if (me->query("family/family_name") == "南少林派")
		me->set("title", "南少林派第"+chinese_number(gen)+"代弟子");
	return 1;
}
#include "/kungfu/class/nanshaolin/fang.h";
