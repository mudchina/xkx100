//Npc : guyueer.c 顾月儿

inherit NPC;

void create()
{
	set_name("顾月儿",({ "gu yueer", "xiao hai", "kid"}) );
	set("title", "学童");
	set("gender", "女性" );
	set("age", 10);
	set("long", "这是个一个资政书院的学童，正在和同伴玩耍。\n");
	set("combat_exp", 1);
	set("positive_score",10);
	set("str", 9);
	set("cor", 18);
	set("cps", 20);
	set("per", 26);
	set("chat_chance", 3);
	set("chat_msg", ({
        "顾月儿道：那个姓杨的最恶心了，老色迷迷额看着我，自以为很酷。\n",
        "顾月儿道：真不想再上学了，可是爹爹老逼我来。\n",
        "顾月儿道：我们的老师真可怜的，唉～～～～！\n"
    }));
    set("inquiry", ([
        "秘密" : "我能有什么秘密呢？\n",
        "secret" : "我不懂洋文的。\n",
    ]));
	set("attitude", "peaceful");
	setup();
	carry_object(__DIR__"obj/huaao")->wear();
}
