// feng.c 风清扬

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("风清扬", ({ "feng-qingyang", "feng", "qingyang" }));
	set("title", "华山第十二代剑宗长老");
	set("long", 
"这便是当年名震江湖的华山名宿风清扬。他身著青袍，神气抑郁脸如金纸。
身材瘦长，眉宇间一直笼罩着一股淡淡的忧伤神色，显然对当年的剑宗气宗
之争一直难以忘怀。\n");
	set("gender", "男性");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 4800);
	set("max_qi", 4800);
	set("jing", 3600);
	set("max_jing", 3600);
	set("neili", 4400);
	set("max_neili", 4400);
	set("jiali", 200);

	set("combat_exp", 1750000);
	set("score", 200000);

	set_skill("cuff", 200);
	set_skill("force", 180);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 220);
	set_skill("strike", 200);
	set_skill("zixia-shengong", 200);
	set_skill("poyu-quan", 170);
	set_skill("fanliangyi-dao", 180);
	set_skill("huashan-sword", 200);
	set_skill("hunyuan-zhang", 170);
	set_skill("lonely-sword", 200);
	set_skill("feiyan-huixiang",200);
	set_skill("literate", 120);

	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	create_family("华山派", 12, "弟子");
	set("family/master_id", "feng qingyang");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
}

void greeting(object ob)
{
	object *obj, me=this_object();
	int i;

	obj = all_inventory(environment(me));
        command("say 非也，非也，这招应该剑意曲而剑势直。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="zhang-sanfeng")
                {
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"),0);
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"),0);
                }
	}
        return;
}

