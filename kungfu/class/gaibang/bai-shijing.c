// bai-shijing.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_quit();
void create()
{
	set_name("白世镜", ({"bai shijing", "bai", "shijing"}));
	set("nickname", "丐帮六老");
	set("gender", "男性");
	set("age", 50);
	set("long", 
"执法长老白世镜，面色蜡黄，向来铁面无私，帮中大小人等，纵然并不违
犯帮规刑条，见到他也是惧怕三分。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	set("no_get", "1");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("inquiry", ([
		"法刀"    :   (: ask_quit :),
		"执法"    :   (: ask_quit :),
		"退帮"    :   (: ask_quit :),
		"tuibang" :   (: ask_quit :),
	]));
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 95);            // 基本内功
	set_skill("huntian-qigong", 90);   // 混天气功
	set_skill("hand", 90);             // 基本手法
	set_skill("suohou-hand", 85);      // 锁喉擒拿手
	set_skill("staff", 90);            // 基本杖法
	set_skill("fengmo-staff", 85);     // 疯魔杖法
	set_skill("dodge", 90);            // 基本躲闪
	set_skill("xiaoyaoyou", 95);       // 逍遥游
	set_skill("parry", 85);            // 基本招架
	set_skill("staff", 90);            // 基本棍杖
	set_skill("strike",85);  // 基本掌法
	set_skill("lianhua-zhang",85); // 莲花掌
	set_skill("xianglong-zhang",85);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");
	map_skill("force", "huntian-qigong");
	map_skill("staff", "fengmo-staff");
	map_skill("parry", "fengmo-staff");
	map_skill("hand", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");

	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", RED"九袋长老"NOR);
	set("party/level", 9);
	create_family("丐帮", 10, "执法长老");
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangzhang")->wield();
}

init()
{
	object ob;
	mapping myfam;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		myfam = (mapping)ob->query("family");
		if((!myfam || myfam["family_name"] != "丐帮") && (!wizardp(ob)))
		{
			remove_call_out("saying");
			call_out("saying", 1, ob);
		}
	}
	add_action("do_decide", "decide");
}
void attempt_apprentice(object ob)
{
	command("say 老夫不收徒弟，"+RANK_D->query_respect(ob)+"还是请回吧。");
}
void destroying(object me, object obj)
{
	destruct(obj);
	return;
}
string ask_quit()
{
	mapping fam;
	object ob,me=this_player();
	string *sname;
	int i;

	if (!(fam = me->query("family")) || fam["family_name"] != "丐帮")
		return RANK_D->query_respect(me) +
		"与本派素无来往，不知此话从何谈起？";
	if(!me->query("party") || me->query("party/party_name") != HIC"丐帮"NOR)
	{
		return "你不是丐帮中人，想走就给我滚。";
	}
	if(me->query("combat_exp") < 100000)
	{
		return "你混进丐帮也没多少日子啊，哪里想走就能走？。";
	}
	me->set_temp("pending/quit_gaibang", 1);
	return "好吧，叛出丐帮须领受本帮法刀，废去你本门武功。\n想好就决定(decide)吧。";
}
int do_decide()
{
	if( !this_player()->query_temp("pending/quit_gaibang") )
		return 0;

	message_vision(
"$n脸如寒霜，沉声道：“执法弟子，请本帮法刀。”\n
他身后属下九名弟子齐声应道：“是！”每人从背后布袋中取出一个黄布包
袱，打开包袱，取出一柄短刀。九柄精光灿然的短刀并列在一起，一样的长
短大小，火光照耀之下，刀刃上闪出蓝森森的光采。一名执法弟子捧过一段
树木，九人同时将九柄短刀插入了木中，随手而入，足见九刀锋锐异常。九
人齐声叫道：“法刀齐集，验明无误。”\n
$n押低嗓子，哑声道：“行刑！”
"HIR"九名执法弟子法刀如疾电般闪过，$N只觉得剧痛如九线大潮，沛然而至，眼
前一阵眩晕。微一定神，执法弟子已经收刀退走了。\n"NOR"
$n冷笑着道：“你去吧，解下背上布袋，自今而后，丐帮中没了你这号人物。”\n
", this_player(), this_object() );
	this_player()->delete_temp("pending/quit_gaibang");
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->add("combat_exp", -23250);
	this_player()->set("combat_exp",this_player()->query("combat_exp")*8/9);
	this_player()->delete("party");
	return 1;
}

