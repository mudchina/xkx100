// frog.c
#include <ansi.h>
inherit NPC;

void create()
{
    set_name(GRN"大青蛙"NOR,({ "big frog","qing wa","frog"}) );
    set("age", 7);
    set("long", "这是一只黑丝大青蛙，长在深不见日的水潭里，全身恶臭，\n
肥肥壮壮，一对血红的眼睛，十分恶心，你真想杀了它。\n");
    set("limbs", ({ "蛙前爪", "蛙后抓", "蛙嘴" }) );
    set("verbs", ({ "bite", "claw" }) );

    set("combat_exp", 50);
    set("shen_type", -1);
    set("str", 11);
    set("dex", 11);
    set("con", 11);
    set("int", 11);
    set("attitude", "peaceful");
    set("chat_msg", ({
        "大青蛙呱呱叫了两声，一副幸灾乐祸的得意模样。\n",
        "大青蛙蹦了两蹦，跳到你的脚边，真恶心！\n",
    }));
    setup();
}

void init()
{
    object ob;

    ::init();
    if( interactive(ob = this_player()) && !is_fighting() ) {
         remove_call_out("greeting");
         call_out("greeting", 1, ob);
    }
    add_action("do_dajia","hit");
    add_action("do_dajia","kill");
    add_action("do_dajia","fight");
    add_action("do_drop","drop");
    add_action("do_save","save");
}

void greeting(object ob)
{
    if( !ob || environment(ob) != environment() ) return;
    say( "大青蛙呱呱叫了两声，一副幸灾乐祸的得意模样。\n");
}

int do_dajia(string arg)
{
    command("say 这里都是水，站都站不稳，还打什么打？省点力气罢！\n");
    return 0;
}
int do_save()
{
    command("say 想存盘？省点力气罢！\n");
    return 0;
}
int do_drop(object arg)
{
    command("say 乱丢垃圾？先捡起来！\n");
    return 0;
}
