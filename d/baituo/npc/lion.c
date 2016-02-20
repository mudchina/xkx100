// lion.c
// Last Modified by Winder on May. 15 2001

inherit NPC;

void create()
{
	set_name("雄狮", ({ "lion", "xiongshi", "shi" }) );
	set("race", "走兽");
	set("age", 15);
	set("long", "一只矫健的雄狮，十分威风。\n");
//	set("attitude", "aggressive");
	set("attitude", "peace");
	set("shen_type", -1);
	set("combat_exp", 400000);
	set_temp("apply/attack", 300);
	set_temp("apply/defense", 300);
	set_temp("apply/damage", 150);
	set_temp("apply/armor", 50);

	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
		"雄狮一声长吼，四下传来阵阵会响。\n",
		"雄狮后足一蹬，猛地一跃到你的面前。\n",
	}) );
}

