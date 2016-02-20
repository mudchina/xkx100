//   zhanglang.c

inherit NPC;
void create()
{
        set_name("蟑螂", ({ "zhang lang","lang" }) );
	set("race", "昆虫");
	set("subrace", "爬虫");
        set("age", 4);
        set("per", 10);
        set("long", "一只令人恶心的小虫子，正好奇的看着你。\n");
        set("combat_exp", 60);
        set("attitude", "friendly");
        set_skill("dodge", 5);
        set_skill("unarmed", 5);
        set_skill("parry", 5);
        set("max_qi", 100);
        set("chat_chance",10);
        set("chat_msg",({
            "叽叽...叽叽叽叽，....叽叽叽..~~~~。\n",
 //       (:random_move:)
        }));

        setup();
}
