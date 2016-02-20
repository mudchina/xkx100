// /kungfu/class/baituo/ouyangfeng.c
// Last Modified by Winder on May. 15 2001

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

int ask_help();
int do_accept();

void create()
{
	object ob;
	set_name("欧阳锋", ({ "ouyang feng", "ouyang", "feng" }));
	set("long", "他是白驼山庄主，号称“西毒”的欧阳锋。\n"
		+"由于习练「九阴真经」走火入魔，已变得精\n"
		+"神错乱，整日披头散发。\n");
	set("title", "白驼山庄主");
	set("gender", "男性");
	set("age", 53);
	set("nickname", HIY "西毒" NOR);
	set("shen_type",-1);
	set("shen", -150000);
	set("attitude", "peaceful");
	set("no_get",1);

	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 900);
	set("max_jing", 900);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);

	set("combat_exp", 3000000);
	set("score", 200000);

	set_skill("force", 200);
	set_skill("cuff", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("hand",200);
	set_skill("strike",200);
	set_skill("staff", 200);
	set_skill("training",200);
	set_skill("literate", 100);
	set_skill("xidu-poison", 150);
	set_skill("hamagong", 200);
	set_skill("hamaquan", 300);
	set_skill("chanchu-bufa", 300);
	set_skill("shexing-diaoshou", 300);
	set_skill("lingshe-zhangfa", 300);
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("cuff", "hamaquan");
	map_skill("strike", "hamagong");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");
	prepare_skill("strike", "hamagong");
	prepare_skill("hand", "shexing-diaoshou");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "staff.shoot" :),
		(: perform_action, "staff.saoye" :),
		(: perform_action, "strike.hama" :),
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );

	create_family("白驼山派",1, "开山祖师");
	set("chat_chance",2);
	set("chat_msg",({
		"欧阳锋自言自语道：何日白驼山派才能重霸江湖呢…\n",
		"欧阳锋道：我儿欧阳克必能够重振白驼山派雄风！\n",
		"欧阳锋道：江湖险恶，困难重重哪！\n",
	}));
	
	set("inquiry", ([
		"name":   "名字，我...我没有名字，我...我是谁?",
		"名字":   "名字，我...我没有名字，我...我是谁?",
	]));
	setup();
	if (clonep())
	 {
	 	ob = new(WEAPON_DIR"treasure/lingshezhang");
	 	if ( ob -> violate_unique() )
	 	{
	 		destruct(ob);
	 		ob=new("/d/baituo/obj/shezhang");
 		}
 		ob->move(this_object());
 		ob->wield();
	 }
	carry_object(__DIR__"obj/baipao")->wear();
	add_money("silver",50);
}

void init()
{
	add_action("do_accept", "accept");
        add_action("do_qiecuo","qiecuo");
}

int ask_help()
{
	object me = this_player();
	
	if (me->query("family/family_name") == "白驼山派" &&
		me->query("family/master_id") != "ouyang feng" &&
		me->query_condition("ice_sting") &&
		me->query_condition("ice_sting") < 10)
	{
		message_vision(HIG"欧阳锋说道：“好，救你不难，但是你须答应(accept)叫我一声爸爸。”\n"NOR, me);
		me->set_temp("helpme", 1);
		return 1;
	}
	return 0;
}

int do_accept()
{
	if (this_player()->query_temp("helpme"))
	{
		this_player()->set("oyf_son", 1);
		this_player()->apply_condition("ice_sting", 0);
		message_vision( HIY"欧阳锋哈哈大笑，声震林梢：“好，好，乖儿子，我就传你蛤蟆功作见面礼吧！只要你勤加修习，”\n", this_player());
		message_vision( HIY"不但除去身上剧毒轻而易举，他日称霸武林，光我白驼亦非难事！“ \n", this_player());
		tell_object(this_player(),HIG"你按照欧阳锋所传依法行功，胸口痛楚立减，不由得喜上眉梢。\n"NOR);
		this_player()->set_temp("baifeng", 1);
		return 1;
	} else return notify_fail("欧阳锋瞥了你一眼：“你没事瞎答应甚么！”\n");
}

void attempt_apprentice(object ob)
{
//	if (ob->query_temp("baifeng") && ob->query("combat_exp") > 50000 && ob->query("age") <= 18 && ob->query("age") >= 16)
	if (ob->query_temp("baifeng") && ob->query("combat_exp") > 50000 )
		command("recruit " + ob->query("id"));
	else message_vision("欧阳锋瞪了$N一眼道：“我白驼山不世艺业岂可轻传。”\n", ob); 	
}
