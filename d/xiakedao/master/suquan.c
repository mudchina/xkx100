// suquan.c 苏荃

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_join(string arg);

void create()
{
	set_name("苏荃", ({ "su-quan", "su" }));
	set("long", "一个千娇百媚、明艳不可方物的少妇。\n");
	set("gender", "女性");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 400000);

	set_skill("force", 150);
	set_skill("dulong-dafa", 150);
	set_skill("dodge", 180);
	set_skill("yixingbu", 250);
	set_skill("leg", 150);
	set_skill("strike", 180);
	set_skill("jueming-leg", 220);
	set_skill("huagu-mianzhang", 250);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("meiren-sanzhao", 220);
	set_skill("literate", 100);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("strike", "huagu-mianzhang");
	map_skill("leg", "jueming-leg");
	map_skill("parry", "meiren-sanzhao");
	map_skill("sword", "meiren-sanzhao");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("leg", "jueming-leg");
	set("party/party_name", HIY"神龙教"NOR);
	set("party/rank", HIR"教主夫人"NOR );
	set("party/level", 3);
	create_family("神龙教", 2, "弟子");

	setup();
	carry_object(WEAPON_DIR"sword/duanjian")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("silver", 50);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	object *obj, me=this_object();
	int i;

	obj = all_inventory(environment(me));
        command("say 横剑纯为守势，膝前膝前更不可解。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="hong-antong")
                {
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                }
	}
        return;
}

