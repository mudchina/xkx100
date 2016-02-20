inherit NPC;
void create()
{
        set_name("哈萨克妇女", ({ "hasake", "woman"}));
        set("gender", "女性");
        set("age", 25);
        set("long", "一位热情好客的哈萨克族妇女。\n");
        set("attitude", "friendly");
        set("combat_exp", 500);
        set("str", 18);
        set("int", 18);
        set("con", 18);
        set("dex", 17);
        set("max_qi", 140);
        set("max_jing", 140);
        set("neili", 100);
        set("max_neili", 100);
        set_skill("unarmed", 10);
        set_skill("parry", 10);
        set_skill("dodge", 10);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 5);
        set("inquiry", ([
            "阿曼" : "阿曼是草原上一朵会走路的花。\n",
            "李文秀" : "李文秀这孩子，长得和阿曼一样美丽，歌也唱得好。\n",
        ]) );
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"哈萨克妇女道: 请进来坐坐吧，喝碗草原上香甜的乳酪。\n",
        }) );
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/shuinang");
}
