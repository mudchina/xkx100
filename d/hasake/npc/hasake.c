inherit NPC;
void create()
{
        set_name("哈萨克牧民", ({ "hasake", "mu min"}));
        set("gender", "男性");
        set("age", 26);
        set("long", "一位健壮的哈萨克族民，正赶着几十只羊。\n");
        set("attitude", "friendly");
        set("combat_exp", 4000 + random(500));
        set("str", 32);
        set("int", 18);
        set("con", 22);
        set("dex", 17);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 5);
        set_skill("unarmed", 20);
        set_skill("blade", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);

        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_temp("apply/damage", 25);
        
        set("inquiry", ([
            "苏普" : "苏普是苏鲁克的儿子，跟他爹一样是个好汉子！\n",
            "苏鲁克" : "苏鲁克是我们哈萨克人中的大英雄，他有个儿子叫苏普。\n",
            "阿曼" : "阿曼是草原上一朵会走路的花。\n",
            "计老人" : "计老人会酿又香又烈的美酒，会医牛羊马匹的疾病。\n",
        ]) );

        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
"哈萨克牧民高兴地说: 上个月，我用刀砍死了一头狼，剥了狼皮送给咱阿妹。\n",
"哈萨克牧民道:  欢迎来到我们哈萨克部族，请去喝碗香甜的乳酪吧。\n",
        }) );
        carry_object(__DIR__"obj/madao")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/jiunang");
}
