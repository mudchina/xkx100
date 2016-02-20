// snake.c

inherit NPC;
void use_poison();

void create()
{
        set_name("竹叶蛇", ({ "big snake" }) );
	set("race", "爬蛇");
        set("age", 4);
        set("long", "一条剧毒的全身象竹子的蛇\n");

        set("attitude", "aggressive");
        set_skill("dodge", 200);
        set("combat_exp", random(2999999));
	set("bellicosity", 300 );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        setup();
}
void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        tell_object(ob, "你觉得腿上剧痛，伸手一摸发现两个毒牙印痕。\n");
	ob->receive_wound("qi",40);
	ob->apply_condition("snake_poison", (int)this_player()->query_condition("snake_poison") + random(3)+3);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}

