// shagu.c

inherit NPC;

void create()
{
	set_name("傻姑", ({"sha gu","shagu"}) );
        set("gender", "女性" );
        set("age", 21);
        set("long", "这是一个傻乎乎的小姑娘。\n");

        set("combat_exp", 150000);
	set("shen", 0);
	set("shen_type", 0);
        set("str", 32);
        set("dex", 18);
        set("con", 18);
        set("int", 10);
	set("max_qi", 900);
	set("max_jing", 720);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);

	set_skill("force", 60);
	set_skill("bibo-shengong", 60);
	set_skill("dodge", 60);
	set_skill("anying-fuxiang", 65);
	set_skill("parry", 60);
	set_skill("strike", 80);
	set_skill("luoying-zhang", 80);
	set_skill("qimen-wuxing", 30);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "anying-fuxiang");
	map_skill("strike", "luoying-zhang");
	map_skill("parry", "luoying-zhang");
	prepare_skill("strike", "luoying-zhang");

	set("rank_info/respect", "小姑娘");
	set("inquiry", ([
		"name": "他们都叫我做傻姑。",
		"rumors": "杨兄弟打了姑姑一掌，杨兄弟就死了。",
		"here": "这里是牛家村。",
		"姑姑": "那个傻小子叫她做蓉儿。",
		"师公": "师公教我打拳玩。",
	]) );
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
	"傻姑唱道：摇摇摇，摇到外婆桥，外婆叫我好宝宝....\n",
	"傻姑念叨说：师公说道，左三掌，右三叉，坏人打我就打他。\n",
	"傻姑忽然指着你的鼻子哈哈大笑，你觉得莫名其妙。\n",
	"傻姑喊道：杨家兄弟，不是我害的你，你可别来找我。\n",
	"傻姑靠在墙角，发出了阵阵的鼾声。\n",
        }) );
        carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
	object money;

	if (ob->id("zhangfa tujie")) 
	{
		if (who->query_temp("shagu_silver")) {
			tell_object(who, "傻姑接过图解，倒着看了半天，不明所以，大怒之下，将图解撕得稀烂！\n");
			destruct(ob);
			return notify_fail("");
		}
		else {
			if (query_temp("silver_give")) {
				tell_object(who, "傻姑接过图解，倒着看了半天，不明所以，只好又还了给你。\n");
				return notify_fail("");
			}
			else {
				tell_object(who, "傻姑接过图解，倒着看了半天，不明所以，只好又还了给你。\n");
				tell_object(who, "傻姑说道：还不如我这个亮晶晶好玩呢！你看看。\n");
				tell_object(who, "傻姑给你一些银子。\n");
				money = new("/clone/money/silver.c");
				money->set_amount(15);
				money->move(who);
				who->set_temp("shagu_silver", 1);
				set_temp("silver_give", 1);
				return notify_fail("");
			}
		}
	}
	return 0;
}

