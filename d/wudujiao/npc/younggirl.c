// younggirl.c  苗族少女
inherit NPC;

void create()
{
        set_name("苗族少女", ({ "young girl", "girl" }));
        set("gender", "女性");
        set("age", 18);
        set("max_qi",300);
        set("per",35);
        set("long", "一个身穿苗族服饰的妙龄少女。\n");
        set("combat_exp", 7000);
        set("shen_type", 1);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        setup();
        carry_object("/d/city/obj/cloth")->wear();
}

