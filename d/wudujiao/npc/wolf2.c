// wolf2.c
inherit NPC;
#include <ansi.h>

string *first_name = ({ "秃尾巴", "短尾巴"});
string *name_words = ({ "狼王", "大母狼"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name,({"wolf"}));

	set("race", "走兽");
        set("long", "一只断了尾巴的大灰狼，正用一双狡诈的狼眼盯着你。\n");
        set("age", 3);
        set("attitude", "peaceful");

        set("max_jing", 700);
        set("max_qi", 700);

        set("str", 25);
        set("con", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 80);
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/defense", 150);
        set_temp("apply/armor", 50);
        set("combat_exp", 200000);
        set_weight(500000);
        set("chat_chance", 10);
        set("chat_msg", ({
            (: random_move :)
        }) );

        setup();
}
void init()
{
        object me,ob;
        if (interactive(me = this_player()))
        {
               remove_call_out("kill_ob");
               call_out("kill_ob", 1, me);
        }
        ::init();
}

