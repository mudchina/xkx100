// poorman.c

inherit NPC;

void create()
{
        set_name("穷汉", ({ "poor man", "man" }) );
        set("gender", "男性" );
        set("age", 33);
        set("long", "一个骨瘦如柴，满脸菜色的穷汉。\n");
        set("attitude", "friendly");
        set("combat_exp", 250);
//	set("shen", 50);
	set("shen_type", 1);
        set("str", 20);
        set("dex", 18);
        set("con", 17);
        set("int", 13);
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
"穷汉懒洋洋地打了个哈欠。\n",
"穷汉叹了口气：那些蒙古鞑子害得我家破人亡。\n",
                (: random_move :)
        }) );
        carry_object("/clone/misc/cloth")->wear();
}

