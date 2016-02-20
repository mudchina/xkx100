// lin-pingzhi.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("林平之", ({ "lin pingzhi","lin","pingzhi"}));
        set("gender", "男性");
        set("age", 18);
        set("long",
                "林平之是岳不群最小的一个弟子，也是他的东床快婿。\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("con", 30);
        set("int", 24);
        set("dex", 35);

        set("max_qi",1500);
        set("max_jing",1500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);

        set("combat_exp", 100000);
        set("shen_type", -1);
        set("score", 200000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 60);
        set_skill("sword", 50);
        set_skill("force", 60);
        set_skill("parry", 50);
        set_skill("dodge", 60);
        set_skill("literate", 70);

        set_skill("huashan-sword", 80);
        set_skill("bixie-sword", 50);
        set_skill("zixia-shengong", 60);
        set_skill("huashan-ken", 60);
        set_skill("feiyan-huixiang", 60);

        map_skill("sword", "bixie-sword");
        map_skill("parry", "bixie-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");

        create_family("华山派", 14, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void die()
{
        object corpse, killer;
        int i;
        string skill;
        object book;

        if( !living(this_object()) ) revive(1);
        if( wizardp(this_object()) && query("env/immortal") ) return;

        // Clear all the conditions by death.
        this_object()->clear_condition();

        COMBAT_D->announce(this_object(), "dead");
        if( objectp(killer = query_temp("last_damage_from")) ) {
                set_temp("my_killer", killer->query("id"));
                COMBAT_D->killer_reward(killer, this_object());
        }

        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());

        if (userp(killer))
        {
             message_vision("$N得到一本辟邪剑谱。\n",killer);
//             command("rumor "+this_player()->query("name")+"抢了辟邪剑谱啦。\n");
             book=new("/clone/book/bixie_book");
             book->move(killer);
        }

        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        this_object()->dismiss_team();
        destruct(this_object());
}
