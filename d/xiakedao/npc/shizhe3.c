//NPC /npc/shizhe3.c

inherit NPC;

void greeting(object);
void init();

void create()
{
        set_name("侍者", ( { "shizhe", "zhe" }) );
        set("title", "侠客岛打杂弟子");
        set("gender", "男性" );
        set("age", 30);
        set("long",
              "这是个身着黄衣的三十几岁汉子，垂手站立，面无表情。\n"
             );
        set("attitude", "friendly");
        set("shen_type", 1);

        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 330);
        set("max_jing", 320);
        set("neili", 300);
        set("max_neili", 300);

        set("combat_exp", 10000);
        set("score", 10000);

        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 40);

        create_family("侠客岛", 2, "弟子");

        set("inquiry", ([
            "here" : "这里就是侠客行的中心了，小人在这服侍了这么久，对其中的秘密也不大清楚。\n",
            "cha"  : "请你稍待，岛主严令小人现在不得离开此地！\n",
            "yezi" : "请你稍待，岛主严令小人现在不得离开此地！\n",
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/xiakedao/obj/key1")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{

        if( !ob || environment(ob) != environment() ) return;
        say("黄衣侍者说道：这位" + RANK_D->query_respect(ob)
           + "想必你也是来参悟武林秘密的吧。这里就是侠客行\n"
           + "的正中心，周围共有二十四间石室，你可随意来去观看。但一切\n"
           + "要小心在意，千万不可莽撞行事。本室可供应饮食，不过还是尽\n"
           + "早离去为好。\n"
             );
        return;
}

int accept_object(object who, object ob)
{
        command("smile");

        if( ob->query("money_id") && ob->value() >= 5000  )
        {command("say " + RANK_D->query_respect(who) +
                "如此古道热肠，兼又身怀绝艺，本来岛主不让我说的，" +
                "但我实在不忍心见死不救。你从西北门进去，把墙壁上的" +
                "那把木刀取下，拿在手上，对你有好处。但你千万别告诉" +
                "别人，否则你我都有杀身之祸，切记切记！！！" );
        }
        return 1;

}
void die()
{
        object room;

        say("你敢杀我，老子到阴间也不会放过你。\n");
        message_vision("$N惨嚎一声，死了！\n", this_object());

        room = environment(this_object());
message("vision", "由于侍者死了摔倒在一旁，这时你才发现刚才他站的地方有点奇怪。\n"
        "地板由两块石板组成，似乎是个门.上面还有一钥匙孔(kong) \n", room);

        ::die();
}

