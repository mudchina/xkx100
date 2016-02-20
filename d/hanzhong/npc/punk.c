// punk.c

inherit NPC;

void create()
{
        set_name("小流氓", ({"punk"}) );
        set("gender", "男性" );
        set("age", 18);
        set("long", "这是一个游手好闲的小流氓。\n");

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("combat_exp", 500);
//      set("shen", -100);
        set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","heroism");
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"流氓骂骂咧咧的说道：这真他妈的邪唬，老子手里一对天牌，王\n"
"小二这杂种居然就摸出一对至尊来。\n",
"流氓靠着墙角打起瞌睡来了，睡梦中也不知想到了什麽，嘴里哼\n"
"哼道：我看见你哪雪白的大腿，我就起～了～坏～心～喽。\n",
"流氓摸了摸自己的口袋，叹了口气说道：唉，钱都让王小二骗去\n"
"了，不能去找翠花了。\n",
"流氓嘴角露出一丝邪笑，说道：翠花这娘儿们真够劲儿，真她奶\n"
"奶的够～劲～儿!\n",
        }) );
        carry_object(CLOTH_DIR"cloth")->wear();
        add_money("silver", 5);
}

