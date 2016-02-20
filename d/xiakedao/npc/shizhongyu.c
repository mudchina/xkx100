// shizhongyu.c 石中玉

inherit NPC;

void create()
{
        set_name("石中玉", ({ "shi zhongyu", "shi", "zhongyu" }));
        set("gender", "男性");
        set("age", 20);
        set("str", 15);
        set("int", 45);
        set("con", 18);
        set("dex", 20);
        set("per", 30);
        set("long", "这是一个年轻公子，大约二十左右岁，面若中秋之月，色如春晓
之花，鬓若刀裁，\n"
            "眉如墨画，鼻如悬胆，情若秋波，虽怒而时笑，即视而有情。\n");
        set("combat_exp", 30000);
        set("shen_type", 1);
        set("score", 0);
        set("attitude", "peaceful");

        set_skill("unarmed", 30);
        set_skill("force", 30);
        set_skill("blade", 20);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("literate",100);

        set_skill("wuhu-duanmendao", 50);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/armor", 5);
        set_temp("apply/damage", 10);
        map_skill("blade", "wuhu-duanmendao");

        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 20);
        set("inquiry", ([
                "侠客岛" : "在泉州附近的一个小岛。\n",
                "石破天" : "他是我的亲兄弟，他现在在侠客岛。\n"
                           "你见了他可别忘了带玄冰碧火酒呀。\n",
//                "hop"    : "她是金砖的女神呀，我很崇拜她啊。\n",
//                "young"  : "他是我的老乡呀。\n",
//                "host"   : "你太小看我了，谁不知道大名鼎鼎的冷晴人啊。\n",
//                "wind"   : "我久仰他的大名，就是没见过。\n",
//                "shaw"   : "嘻嘻，我在MUD中到见过他。\n",
//                "aman"   : " 我当然知道了，我见过他呀。\n",
//                "xmo"    : "小莫啊！我们是好朋友呀，我们经常在一起玩。\n",
//                "mudos"  : "哈哈!我们也是好朋友呀! \n",
//                "road"   : "呀！你是谁呀? 怎么连她都知道哇。她是新月的姐姐呀。\n"
//                           "她可是个好孩子，还是个研究生呢！唉，新月能有她的一半就好了。\n",
//                "xinyue" : "别提他了，一天游手好闲，一点也不象他的姐姐。\n",
                "叮当"   : "我好久没见到她了，不知道她现在怎么样了。\n",
                "赏善罚恶令" : "有了它，你可以到侠客岛学武功呀。\n",
        ]) );
        set("chat_chance", 8);
        set("chat_msg", ({
                "\n石中玉说道: 叮当，你在哪呀，我好想你呀。\n",
                "\n石中玉叹道: 也不知道我的叮当怎么样了。\n",
                "\n石中玉说道: 腊八粥可是好东西...\n",
                "\n石中玉说道: 唉，谁能帮我杀了外面的老头，兄弟我谢谢你了！\n",

        }) );
        setup();
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",1);
}

void init()
{
        object ob;
        ob = this_player();
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
}

void greeting(object ob)
{
        int change=0;
        if( !ob || environment(ob) != environment() )
                return;
        message_vision( "\n石中玉哈哈大笑道：我终于看见救我的人来了。\n",this_object());
}

void die()
{
        say("\n石中玉说道：我还有个心愿没了，希望你能帮我照顾叮当！\n");

        message_vision("石中玉喊着叮当的名字，死了！\n", this_object());
        ::die();
}

int accept_object(object who, object ob)
{
        object obn;

        if( !who || environment(who) != environment() )
                return 0;
        if ( !objectp(ob) )
                return 0;
        if ( !present(ob, who) )
                return notify_fail("你没有这件东西。");

        if ( (string)ob->query("id") == "shou pa")
        {
                remove_call_out("destroy");
                call_out("destroy", 1, who, ob);

                message_vision("\n石中玉感动的热泪迎眶：终于知道了她的消息了！\n",who);
                obn = new("/d/xiakedao/obj/shane-bu");
                obn->move(who);
                return 1;
        }
}

void destroy(object me, object ob)
{
        destruct(ob);
        return;
}
