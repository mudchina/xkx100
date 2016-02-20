// zhang3.c

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_join(string arg);

void create()
{
	set_name("章老三", ({ "zhang laosan", "zhang" }));
	set("gender", "男性");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("long", "这是一个干瘦老头,一双小眼睛贼闪发光。\n");
	set("combat_exp", 25000);
	set("score", 2000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 50);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("yixingbu", 40);
	set_skill("shenlong-bashi", 50);
	map_skill("parry", "shenlong-bashi");
	map_skill("dodge", "yixingbu");

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);
	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);
	set("inquiry", ([
		"洪安通" : "这三个字是你说的吗？",
		"洪教主" : "洪教主仙福永享，寿与天齐，洪教主神目如电，烛照四方。",
		"苏荃"   : "没规没矩的。",
		"神龙岛" : "神龙岛在汝州的东北方向，从塘沽口出海便到。",
		"神龙教" : "一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"入教"   : "一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"教主"   : "教主脾气不好，要讨他欢心才好。\n",
		"口号"   : "万年不老！永享仙福！寿与天齐！文武仁圣！\n",
	]) );
	set("chat_chance", 3);
	set("chat_msg", ({
		"章老三说道：洪教主身通护佑，众弟子勇气百倍，以一当百，以百当万。\n",
		"章老三说道：洪教主神目如电，烛照四方。\n",
		"章老三说道：我弟子杀敌护教，洪教主亲加提拔，升任圣职。\n",
		"章老三说道：我教弟子护教而死，同升天堂。\n",
		"章老三高声叫道：教主宝训，时刻在心，建功克敌，无事不成！\n",
		"章老三忽然齐声叫道：众志齐心可成城，威震天下无比伦！\n",
		"章老三忽然齐声叫道：神龙飞天齐仰望，教主声威盖八方！\n",
		"章老三忽然齐声叫道：乘风破浪逞英豪，教主如同日月光！\n",
		"章老三齐声叫道：教主永享仙福，寿与天齐！\n",
	}) );
	set("party/party_name", HIY"神龙教"NOR);
	set("party/rank", HIW"白龙门"NOR"教众");
	set("party/level", 2);
	create_family("神龙教",2,"弟子");
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("silver",5);
}

void init()
{
	add_action("do_join","join");
}

int recognize_apprentice(object ob)
{
	if (ob->query("party/party_name") == HIY "神龙教" NOR)
	{
		message_vision("$N摇了摇头。\n",this_object());
		command("tell "+ob->query("id")+"你我素不相识，我凭什么要教你呢？ \n"); 
		return 0;
	}
	return 1;	
}

#include "/kungfu/class/shenlong/shenlong.h";
