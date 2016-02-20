// li4.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

void create()
{
        set_name("李四摧", ({ "li sicui", "sicui", "li"}));
        set("title", HIC "神箭八雄" NOR);
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 500);
        set("max_jing", 200);
        set("max_neili", 500);
        set("neili", 500);
        set("jiali", 50);
        set("combat_exp", 30000+random(10000));

        set_skill("dodge", 80);
        set_skill("unarmed", 80);
        set_skill("throwing", 80);
        set_skill("xuanyuan-arrow", 80);
        set_skill("changquan", 80);
        set_skill("lingxu-bu", 80);
        map_skill("dodge", "lingxu-bu");
        map_skill("parry", "changquan");
        map_skill("throwing", "xuanyuan-arrow");
        map_skill("unarmed", "changquan");

	set_temp("is_riding", HIW"玉花马"NOR);
        setup();
        carry_object(__DIR__"obj/arrow")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",1);
}
void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
        object obj;
        if( objectp(obj = present("zhao min", environment(ob))) )
        {
                this_object()->set_leader(obj);
        }
}
