inherit NPC;
void create()
{
        set_name("苏鲁克", ({ "suluke", "su"}));
        set("gender", "男性");
        set("age", 45);
        set("long", "他就是哈萨克第一勇士苏鲁克。\n");
        set("attitude", "heroism");
        set("combat_exp", 110000);
        set("shen", 1100);
        set("str", 33);
        set("int", 20);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 10);
        set_skill("unarmed", 30);
        set_skill("blade", 50);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_temp("apply/damage", 30);
        setup();
        carry_object(__DIR__"obj/wandao")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/jiunang");
}