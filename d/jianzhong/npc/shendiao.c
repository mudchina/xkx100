//shendiao.c

inherit NPC;

void create()
{
	set_name("神雕", ({ "shen diao", "diao" }) );
	set("race", "飞禽");
	set("subrace", "走禽");
	set("age", 20);
	set("long", @LONG
    这雕身形甚巨，比人还高，形貌丑陋之极，全身羽毛疏疏落
落，似是被人拔去了一大半似的，毛色黄黑，显得甚是肮脏，雕
钓嘴弯曲，头顶生著个血红的大肉瘤，双腿奇粗，羽翼甚短。
LONG
);
	set("attitude", "peaceful");
	set("chat_chance", 10);
	set("chat_msg", ({
		"这雕迈著大步来去，只是高视阔步，自有一番威武气概。\n",
		"这雕不时伸出羽翼，却又甚短，不知如何飞翔，但拍打呼呼成风。\n",
		"这雕突然高声鸣叫，声音微带嘶哑，但激越苍凉，气势甚豪。\n",
	}));
       set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("str", 86);
	set("cor", 80);
	set("limbs", ({ "头部", "身体", "左翅", "右翅", "左爪", "右爪" }) );
	set("verbs", ({ "poke", "claw", "wind" }) );

	set("combat_exp", 2000000);

	set_skill("dodge",100);
	set_skill("parry",100);

	set_temp("apply/attack", 120);
	set_temp("apply/damage", 120);
	set_temp("apply/armor", 120);
	set_temp("apply/defence",120);
	setup();
}


