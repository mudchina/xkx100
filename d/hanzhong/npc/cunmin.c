// cunmin.c

inherit NPC;

void create()
{
        set_name("村民", ({ "cun min", "min" }) );
        set("gender", "男性" );
        set("age", 30);
        set("long", "一个魁梧的庄稼汉子。\n");
        set("attitude", "friendly");
        set("combat_exp", 500);
        set("shen", 100);
        set("shen_type", 1);
        set("str", 22);
        set("dex", 18);
        set("con", 18);
        set("int", 13);
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
"村民道：多亏全真教的道爷们，这山上咬庄稼的獾子全让他们给赶跑了。\n",
"村民突然满脸恍然的神色：今年的收成不错，我得跟全真教的道爷们送点
儿去，请他们尝尝鲜。\n",
        }) );
        carry_object(CLOTH_DIR"cloth")->wear();
        add_money("coin",100);
}

