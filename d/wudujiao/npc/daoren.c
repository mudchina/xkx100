// daoren.c
inherit NPC;
int ask_me();
#include <ansi.h>

void create()
{
        set_name("毒郎中", ({ "dao ren","dao" }) );
        set("gender", "男性" );
        set("age", 35);
        set("per", 20);
        set("long", "一位身穿道服，干瘪黑瘦的中年道人．\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set_skill("dodge", 80);
        set_skill("unarmed",80);
        set_skill("parry", 80);
        set_skill("literate", 150);

        set("chat_chance",12);
        set("chat_msg",({
            "毒郎中冷笑道：江湖中人谁敢和我们五毒教作对，管叫他死的不明不白。\n",
            "毒郎中干笑一声道：贫道专管练制各种毒药，保证药到命除。\n",
        }));

        setup();
        add_money("silver", 20);
        set("inquiry", ([
            "name": "在下就是毒郎中．\n",
            "here": "此乃炼丹房，可以在这里练制(lianzhi)各种毒药。\n",
            "毒药": "阁下可以使用(lianzhi)命令练制各种毒药。\n",
            "毒经": (: ask_me :),
            "配方": (: ask_me :),
            "毒药配方": (: ask_me :),
        ]) );
        carry_object("/d/wudang/obj/greenrobe")->wear();
}
int ask_me()
{
        object ob,me,book;
        me = this_player();
        if ((string)me->query("family/family_name") != "五毒教")
              return notify_fail("阁下与本派并无渊源，这是从那里话来？\n");
        book=present("jing",me);
        if(objectp(book) && (string)book->query("name")=="毒经上篇")
              return notify_fail("你不是有一本了吗，怎么还来要？\n");
        command("say 此乃我五毒教之《毒经》，千万不可遗失了啊。\n");
        ob = new("/clone/book/poisonbook1");
        ob->move(this_player());
        return 1;
}

