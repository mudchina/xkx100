// qin.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("秦教头", ({ "qin jiaotou", "qin", "jiaotou" }));
        set("long","一个四十多岁的汉子，一看就是个会家子，浑身透着一股英气。\n");
        set("gender", "男性");
        set("age", 45);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("claw", 80);
        set_skill("hand", 80);
        set_skill("strike", 80);
        set_skill("finger", 80);
        set_skill("cuff", 80);
        set_skill("blade", 80);
        set_skill("stick", 80);
        set_skill("club", 80);
        set_skill("staff", 80);
        set_skill("sword", 80);
        set_skill("throwing", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        setup();

}
int accept_object(object who, object ob)
{
    if (who->query("combat_exp")>= 3500)
    {
        message_vision("秦教头望着$N说：你的武功应该历练江湖才能再长进，不能埋没
在这里了。\n", who);
        return 0;
    }
    if (ob->query("money_id") && ob->value() >= 500)
    {
        who->set_temp("marks/qin_paied",1);
        message_vision("秦教头对$N说：好！这位" + RANK_D->query_respect(who) 
+ "想学什么呢？\n" , who);
        return 1;
    }
    else
        message_vision("秦教头皱眉对$N说：钱我不在乎。可你也给的也太少了点儿吧？\n", who);
        return 0;
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("marks/qin_paied")==1) return 0;
        return 1;
}

