// hua.c

inherit NPC;

void create()
{
	set_name("华师傅", ({ "hua shifu", "hua" }));
	set("gender", "男性");
	set("age", 65);
	set("long", 
"他是镖局中的厨子，烹饪功夫著实不差，几位冬瓜盅、佛跳墙、糟鱼、肉
皮馄饨，驰誉福州，是林震南结交达官富商的本钱之一。\n");
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 30);
	set_skill("blade", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_temp("apply/damage", 30);

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
