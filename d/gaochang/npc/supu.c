// supu.c 苏普

inherit NPC;

void create()
{
	set_name("苏普", ({ "su pu", "su", "pu"}));
	set("gender", "男性");
	set("age", 19);
	set("long", 
"一个健硕的哈萨克少年，头人苏鲁克的孩子。\n");
	set("combat_exp", 20000);
	set("shen_type", 1);
	set("jiali", 10);

	set_skill("force", 20);
	set_skill("blade", 20);
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);

	set("inquiry", ([
		"李文秀" : "计爷爷说那个汉人小姑娘已经不在人世了。\n",
		"苏鲁克" : "那是我爹。\n",
		"阿曼"   : "她不就在我旁边么！？\n",
	]) );

	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 10);

	setup();
	carry_object("/d/xingxiu/obj/wandao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

