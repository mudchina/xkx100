
inherit NPC;

void create()
{
	set_name("方先生", ({ "fang xiansheng", "fang", "xiansheng"}));
	set("long", "这位老先生，正在认真地读书。\n");
	set("gender", "男性");
	set("age", 35);
	set_skill("literate", 60);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);
	set("combat_exp", 50000);
	setup();
	carry_object("clone/cloth/cloth")->wear();
}

