//gu.c
inherit NPC;

void create()
{
	set_name("顾炎武", ({ "gu yanwu", "gu" }));
	set("long", "顾先生被称为当世第一大文学家，肚子里的墨水比海还要深。\n");
	set("gender", "男性");
	set("age", 65);

	set_skill("literate", 300);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"顾炎武说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
		"顾炎武说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
		"顾炎武说道：大学之道，在明明德。在亲民，在止于至善。 \n",
		"顾炎武说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
	}) );
	carry_object(CLOTH_DIR"cloth")->wear();
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/朱"))
		return 0; 
	ob->add_temp("mark/朱", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	if (!(int)who->query_temp("mark/朱"))
		who->set_temp("mark/朱", 0);
	if (ob->query("money_id") && ob->value() >= 5000) {
		message_vision("顾炎武同意指点$N一些问题。\n", who);
		who->add_temp("mark/朱", ob->value() / 250);
		return 1;
	}
	return 0;
}
