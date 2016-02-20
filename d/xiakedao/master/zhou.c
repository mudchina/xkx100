// zhou.c 周芷若

#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("周芷若", ({ "zhou-zhiruo","zhiruo","zhou"}));
        set("long",
                "她是峨嵋派的第四代掌门弟子。\n"
                "一张脸秀丽绝俗。身着一身淡黄衣裳。\n"
                "略显清减的巧笑中带了些许无奈。\n"
                "她很寂寞。\n");
        set("gender", "女性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("class", "fighter");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("max_qi", 3500);
        set("max_jing", 1000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jingli", 1000);
        set("max_jingli", 1000);

        set("combat_exp", 1500000);
        set("score", 1000);
        set_skill("persuading", 80);
        set_skill("force", 100);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("strike", 100);
        set_skill("sword", 100);
        set_skill("claw", 100);
        set_skill("literate", 100);
        set_skill("mahayana", 100);
        set_skill("jinding-zhang", 100);
        set_skill("jiuyin-baiguzhao", 100);
        set_skill("tiangang-zhi", 100);
        set_skill("huifeng-jian", 100);
        set_skill("zhutian-bu", 100);
        set_skill("linji-zhuang", 100);
        map_skill("force","linji-zhuang");
        map_skill("claw","jiuyin-baiguzhao");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        prepare_skill("strike","jinding-zhang");
        create_family("峨嵋派", 4, "掌门弟子");

        setup();
        carry_object("/clone/weapon/changjian");
        carry_object("/d/emei/obj/ycloth.c")->wear();
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
        command("say 徒儿定会紧记与心的。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="miejue-shitai")
                {
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                }
	}
        command("say 这一句是否指出掌必尽全力，伤敌无虑。");
        return;
}

