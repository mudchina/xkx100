// aman.c 阿曼

inherit NPC;

void create()
{
	set_name("阿曼", ({ "a man", "man"}));
	set("gender", "女性");
	set("age", 18);
	set("long", 
"一个娇美的哈萨克姑娘，苏普的情侣。\n");
	set("combat_exp", 2000);
	set("shen_type", 1);

	set_temp("apply/attack", 5);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 5);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

