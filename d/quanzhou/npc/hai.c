// hai.c 海公公
// Jay 4/6/96

inherit NPC;

string ask_for_zigong();
int ask_for_gongzi();

void create()
{
        set_name("海公公", ({"hai gonggong", "hai", "gonggong"}));
        set("title", "东厂千户");
        set("long",
"他是东厂大太监海大富，乔装改扮成商人模样出京寻欢作乐，长得既像
老头又像老太太。\n"
        );

        set("gender", "无性");
        set("rank_info/respect", "公公");

        set("attitude", "heroism");
        set("class", "eunach");

        set("inquiry",([
                "自宫"    : (: ask_for_zigong :),
                "zigong"  : (: ask_for_zigong :),
                "工资"    : (: ask_for_gongzi :),
                "薪水"    : (: ask_for_gongzi :),
                "salary"  : (: ask_for_gongzi :),
                "payment" : (: ask_for_gongzi :),
                "gongzi"  : (: ask_for_gongzi :),
        ]));

        set("age", 60);
        set("shen_type", -1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 500);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 100);
        set("combat_exp", 15000);
        set("score", 100);
        set("apply/attack",  30);
        set("apply/defense", 30);

        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("bixie-jian", 50);

        map_skill("dodge", "bixie-jian");
        map_skill("sword", "bixie-jian");

        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}

void init()
{
        add_action("do_decide", "decide");
}

string ask_for_zigong()
{
        object me;

        me = this_player();

        if( (string)me->query("gender")=="无性" )
                return "你我同是阉人，何必开如此无聊的玩笑？\n";

        if( (string)me->query("gender") == "女性" )
                return "我虽已废，但一样可以给你这个小美人带来快乐，要不要试试？\n";
        if ((int)me->query_str() > 28 )
                return "这位好汉过于粗壮，自宫有碍观瞻，不妥，不妥。\n";

        if ((int)me->query("mud_age") < 600)
                return "这位小兄弟才出娘胎，就要自宫，好可怜见的。\n";

        me->set_temp("pending/zigong", 1);
        return "自宫？这位公子相貌堂堂，何必... 我真希望能有你的那个。自宫之后，
不可后悔，你若决心已定(decide)，告诉我。\n";
}

int do_decide()
{
        if( !this_player()->query_temp("pending/zigong") )
                return 0;

        message_vision(
                "$N一咬牙，褪下中衣。（女玩家闭眼！）\n\n"
                "$n伸出长剑插到$N两腿之间，飞速一剜，……\n\n"
                "$N顿时惨叫一声昏了过去……\n\n",
                this_player(), this_object() );
        command("chat 嗨……");
        command("hehe");
        this_player()->delete_temp("pending/zigong");
        this_player()->set("gender","无性");
        this_player()->set("class", "eunach");
        this_player()->set("combat_exp",this_player()->query("combat_exp")+1000);
        this_player()->unconcious();
        return 1;
}

int ask_for_gongzi()
{
        object me,payment;
        int paytimes;

        me = this_player();
        if( (string)me->query("gender")!="无性" ) return 0;
        if ( me->query_skill("bixie-jian",1) < 60)
        {
                tell_object(me,"海公公道：下等使役太监哪有工资？进东厂再说！\n");
               	return 1;
        }
        paytimes = (int)(me->query("mud_age")/7200);
        if (me->query("paytimes")<paytimes)
        {
            payment=new("/clone/money/gold");
            payment->move(me);
            me->add("paytimes",1);
            tell_object(me,"海公公道：这是你本月的份额，收好吧。\n");
        }
        else tell_object(me,"海公公道：欺负我老糊涂？你本月工资已经领取过了！\n");
        return 1;
}

