// wolf1.c
inherit NPC;
#include <ansi.h>

string *first_name = ({ "°×ÑÛ", "¶ö", "¹«", "Ä¸"});
string *name_words = ({ "ÀÇ"});


void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name,({"wolf"}));

	set("race", "×ßÊÞ");
        set("long", "Ò»Ö»Ð×ºÝ²Ð±©µÄÀÇ£¬ÕýµÉ×Å»ðºìµÄÀÇÑÛ¶¢×ÅÄã¡£\n");
        set("age", 3);
        set("attitude", "peaceful");

        set("max_jing", 700);
        set("max_qi", 700);

        set("str", 20);
        set("con", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/attack", 50);
        set_temp("apply/damage", 50);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 50);
        set("combat_exp", 100000);
        set_weight(500000);
        set("chat_chance", 15);
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

