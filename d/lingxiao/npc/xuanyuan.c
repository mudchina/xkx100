// Npc: /d/lingxiao/npc/xuanyuan.c
// Last Modified by winder on Jul. 15 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("轩辕苍翼", ({ "xuanyuan cangyi", "xuanyuan" }));
	set("title", "刀剑铺老板");
	set("shen_type", 1);
	set("gender", "男性" );
	set("age", 33);
	set("long", "据说轩辕苍翼是欧冶子的后代，为了避免被权贵强迫铸剑，\n"
		"才隐姓埋名在此开店，听说干将莫邪就在他手上。\n");
	set("combat_exp", 400000);
	set("inquiry", ([ 
		"干将莫邪" : "“想要干将莫邪，你可得先帮我个忙。先去帮我拿到雪山的冰魄玉精吧。”\n", 
		"干将" : "“干将乃先祖所铸的邪剑，杀人太多，冤魂萦绕 。”\n", 
		"莫邪" : "“莫邪乃先祖所铸的邪剑，杀人太多，冤魂萦绕 。”\n", 
	]));
	set("attitude", "friendly");
	set("vendor_goods",({
		WEAPON_DIR+"changjian",
		WEAPON_DIR+"gangdao",
		WEAPON_DIR+"hammer",
		WEAPON_DIR+"dagger",
		WEAPON_DIR+"qimeigun",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

int accept_object(object who, object obj, object ob1, object ob2)
{
	if ((string)obj->query("id") != "bingpo yujing")
	{
		command("say 这位"+(string)who->query("name") +"我找你要过这玩意吗？");
		return 0;
	}
	command("say 哈哈！我总算找到冰魄玉精了");
	ob1=new(WEAPON_DIR"treasure/ganjiang-jian");
	ob2=new(WEAPON_DIR"treasure/moye-jian");
	ob1->move(who);
	ob2->move(who);
	command("say 这位"+RANK_D->query_respect(who)+ "帮我找到了冰魄玉精，我也说话算数，这两把剑你就拿去吧。\n");
	message_vision("轩辕苍翼揭开一个长条盒子，嗖的一声抽出两把剑，递给$N。\n",who);
	destruct(obj);
	return 0;
}

