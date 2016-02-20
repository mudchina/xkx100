// shipotian.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int ask_weiwang();

void create()
{
        set_name("石破天", ({"shi potian", "shi","potian"}));
        set("title", "长乐帮帮主");
        set("gender", "男性");
        set("age", 20);
        set("long", "他大约二十多岁，穿着一身破烂的衣服，却也挡不住他一身的英气。\n");

        set("attitude", "peaceful");

        set("str", 25);
        set("int", 35);
        set("con", 25);
        set("dex", 25);

        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);

        set("combat_exp", 1000000);
        set("score", 30000);

        set_skill("force", 100);                 // 基本内功
        set_skill("huntian-qigong", 150);        // 混天气功
        set_skill("unarmed", 100);               // 基本拳脚
        set_skill("xianglong-zhang", 150);       // 降龙十八掌
        set_skill("dodge", 100);                 // 基本躲闪
        set_skill("xiaoyaoyou", 150);            // 逍遥游
        set_skill("parry", 100);                 // 基本招架
        set_skill("begging", 50);               // 叫化绝活
        set_skill("checking", 50);              // 道听途说

        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong-zhang");
        set("chat_chance", 8);
        set("chat_msg", ({
        "石破天说道: 我来侠客岛这么多天了，也不知道阿绣和婆婆现在怎么样了。\n",
        "石破天说: 江湖威望很重要，威望高大有好处啊。\n",
        "石破天突然说道: 不行，我不放心阿绣，我要去看看她。\n",
        "石破天突然说道: 矣！我的体内怎么好象有一群蝌蚪在动呢。\n",
        "石破天说道: 你能给我玄冰碧火酒吗? \n",
        }));
        set("inquiry", ([
                "腊八粥" :  "\n你去问龙岛主，试试你的运气吧。\n",
                "石中玉" :  "\n他是我的兄弟，他现在在摩天崖。\n",
                "阿绣" :  "\n呀！你见过她吗?她还好吧。\n",
                "玄冰碧火酒" : "\n嘻嘻！多在侠客岛转转吧。\n",
                "赏善罚恶令" : "\n你可以用它来要腊八粥。\n",
                "威望" :  (: ask_weiwang :),
                "江湖威望" : (: ask_weiwang :),
        ]) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

int ask_weiwang()
{
        command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
        say("\n石破天说：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
                +"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
        say("\n石破天又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
        return 1;
}

int recognize_apprentice(object ob)
{
        if (ob->query("weiwang")<50)
        {
                message_vision("$N摇了摇头。\n",this_object());
                command("tell "+ob->query("id")+"你的身份太低，我不能教你 。\n");
                return 0;
        }
        return 1;
}

void init()
{
        ::init();
        add_action("do_skills","skills");
        add_action("do_skills","cha");

}

int do_skills(string arg)
{
        object ob ;
        ob = this_player () ;
        if(wizardp(ob))
                return 0;
        if (ob->query("weiwang")<50)
        {
                message_vision("$N摇了摇头。\n",this_object());
                command("tell "+ob->query("id")+" 你怎么能看我的武功呢。\n");
                return 1;
        }
        command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  叫化绝活 (begging)                       - 出类拔萃  50/   \n"+
"  道听途说 (checking)                      - 出类拔萃  50/   \n"+
"  基本轻功 (dodge)                         - 一代宗师  100/   \n"+
"  基本内功 (force)                         - 一代宗师  100/   \n"+
"□混天气功 (huntian-qigong)                - 一代宗师  150/   \n"+
"  基本招架 (parry)                         - 登峰造极  100/   \n"+
"  基本拳脚 (unarmed)                       - 一代宗师  100/   \n"+
"□降龙十八掌 (xianglong-zhang)             - 登峰造极  150/   \n"+
"□逍遥游 (xiaoyaoyou)                      - 一代宗师  150/   \n");
        return 1;
}

int accept_object(object who, object ob)
{
        object obn;
        if( !who || environment(who) != environment() )
                return 0;
        if( !objectp(ob) )
                return 0;
        if( !present(ob,who) )
                return notify_fail("你没有这样东西。\n");

        if( (string)ob->query("id") == "xuanbingbihuo jiu")
        {
                remove_call_out("destroy");
                call_out("destroy", 1, who, ob);

                message_vision( "\n石破天激动的说：这位大哥，我该怎么谢你呢。\n",who);
                obn = new("/d/xiakedao/obj/xuantie");
                obn->move(who);
                return 1;
        }
}

void destroy(object me, object ob)
{
        destruct(ob);
        return;
}
