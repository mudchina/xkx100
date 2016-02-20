// xiaoqu.c

inherit NPC;

void create()
{
	set_name("曲非烟",({ "qu feiyan", "qu" }) );
        set("gender", "女性" );
        set("age", 12);
        set("long", 
"她是曲长老的宝贝孙女儿，有十二、三岁了吧。\n");
        set_temp("apply/defense", 5);
	set("combat_exp", 70);
//        set("shen", 100);
	set("shen_type", 1);
        set("per", 26);
        set("str", 30);
        set("dex", 30);
        set("con", 30);
        set("int", 30);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

