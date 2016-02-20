// Npc: /kungfu/class/nanshaolin/fangchen.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;
string ask_me(string name);

void create()
{
	set_name("方尘", ({ "fang chen", "fang", "chen"}));
	set("long", "他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，身手却已相\n"
		"当矫捷，看来似乎学过一点武功。\n");
	set("nickname", "兵器头");
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
	set_skill("whip", 50);
	set_skill("jiujie-whip", 50);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "luohan-cuff");
	map_skill("hand", "fengyun-hand");
	map_skill("whip", "jiujie-whip");
	map_skill("parry", "jiujie-whip");
	prepare_skill("cuff", "luohan-cuff");
	prepare_skill("hand", "fengyun-hand");

	set("inquiry", ([
		"长剑" : (: ask_me, "changjian" :),
		"剑"   : (: ask_me, "changjian" :),
		"戒刀" : (: ask_me, "jiedao" :),
		"刀"   : (: ask_me, "jiedao" :),
		"禅杖" : (: ask_me, "chanzhang" :),
		"杖"   : (: ask_me, "chanzhang" :),
		"戒棍" : (: ask_me, "qimeigun" :),
		"棍"   : (: ask_me, "qimeigun" :),
		"皮鞭" : (: ask_me, "changbian" :),
		"鞭"   : (: ask_me, "changbian" :),
	]));
	set("wuqi_count", 25);

	create_family("南少林派", 21, "弟子");

	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(WEAPON_DIR+"whip/whip")->wield();
}

string ask_me(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "南少林派")
		return RANK_D->query_respect(this_player()) +"与本派素无来往，不知此话从何谈起？";
	if ( present(name, this_player()) )
		return RANK_D->query_respect(this_player()) +"你现在身上不是有这样武器吗，怎麽又来要了？ 真是贪得无餍！";
	if (query("wuqi_count") < 1)
		return "抱歉，你来得不是时候，武器已经发完了。";
	if (name == "changjian") 
		ob = new(WEAPON_DIR + "sword/" + name);
	if (name == "jiedao") 
		ob = new(WEAPON_DIR + "blade/" + name);
	if (name == "chanzhang") 
		ob = new(WEAPON_DIR + "staff/" + name);
	if (name == "changbian") 
		ob = new(WEAPON_DIR + name);
	if (name == "qimeigun") 
		ob = new(WEAPON_DIR + name);
	ob->move(this_player());
	add("wuqi_count", -1);
	message_vision("方尘给$N一件"+ob->query("name")+"。\n",this_player());
	return "拿去吧。不过要记住，武器只可防身练武，不可凭此杀害生灵。";
}
#include "/kungfu/class/nanshaolin/fang.h";
