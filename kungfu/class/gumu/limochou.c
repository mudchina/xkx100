// /kungfu/class/gumu/limochou.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>
inherit F_MASTER;
inherit NPC;

int do_look(string var);
int ask_me();

void create()
{
	object ob;
	set_name("李莫愁", ({ "li mochou", "li", "mochou" }));
	set("long", "她生得极为美貌，但冰冷的目光让人不寒而栗。\n");
	set("nickname", "赤练仙子");
	set("gender", "女性");
	set("rank_info/respect", "道姑");
	set("age", 27);
	set("attitude","heroism");
	set("str", 30);
	set("dex", 35);
	set("per", 30);
	set("con", 17);
	set("int", 25);
	set("shen_type", -1);

	set_skill("unarmed", 90);
	set_skill("force", 80);
	set_skill("dodge", 100);
	set_skill("whip",130);
	set_skill("qiufeng-chenfa",180);
	set_skill("yunv-xinfa", 100);    //玉女心法	
	set_skill("throwing",130);
	set_skill("meinv-quan",100);
	map_skill("force", "yunv-xinfa");
	map_skill("whip","qiufeng-chenfa");
	map_skill("unarmed","meinv-quan");
	set("jiali",50);

	set("combat_exp", 95000);

	set("max_qi", 1500);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);

	set("inquiry", ([
		"name" : "站远点！",
		"here" : "我不是本地人，不知道。",
		"情" : "你如何能理解其中相思之苦、惆怅之意？",
		"陆展元" : "你问那个薄情的小畜生做什么？",
		"何沅君" : (: ask_me :),
		"小龙女" : "那是我的师妹。你问她想干什么？",
		"林朝英" : "那是我的师祖，不该你问的你别问，小心我宰了你。",
	]) );

         create_family("古墓派", 3, "弟子");
 
	set("chat_chance", 10);
	set("chat_msg", ({
		"李莫愁纵声而歌，音调凄婉，歌道：「问世间，情是何物，直教生死相许？」\n",
		"李莫愁歌道：「天南地北双飞客，老翅几回寒暑？」\n",
		"李莫愁唱道：「欢乐趣，离别苦，就中更有痴儿女。」\n",
		"李莫愁唱道：「君应有语，渺万里层云，千山暮雪，只影向谁去？」\n",
		"李莫愁词意悲切，声调更是哀怨，唱道：「横汾路，寂寞当年箫鼓。荒烟依旧平楚。」\n",
		"李莫愁歌道：「招魂些何嗟及，山鬼自啼风雨。」\n",
		"李莫愁唱道：「天也妒，未信与，莺儿燕子俱黄土。」\n",
		"李莫愁唱道：「千秋万古，为留待骚人，狂歌痛饮，来访雁丘处。」\n",
	}) );

	setup();
	carry_object("/d/quanzhou/obj/fuchen")->wield();
	carry_object("/d/wudang/obj/greenrobe")->wear();
	ob=new(__DIR__"obj/yinzhen");
	ob->set_amount(10);
	ob->move(this_object());
}
void attempt_apprentice(object ob)
{
	if(ob->query("per") < 20)
	{
        	command("say 尊容实在不敢恭维，恐怕学不了玉女心法。\n");
	}
	if ((string)ob->query("gender") != "女性")
	{     
	      message("vision", HIY "李莫愁大怒，喝道：我最恨你们这些薄情的臭男人！去死吧！\n李莫愁决心杀死" + ob->name() +"\n" NOR, environment(), this_object() );
	      kill_ob(this_player());
	}		
	else
	{
	        command("say 好吧，我就收下你这个徒弟了。\n");
        	command("recruit " + ob->query("id"));
	}
}
void init()
{
	::init();
	add_action("do_look","look");
	add_action("do_look","hug");
	add_action("do_look","mo");
	add_action("do_look","18mo");
	add_action("do_look","kiss");

}

int ask_me()
{
	object me;
 
	me = this_player();
	message("vision", HIY"李莫愁冷笑一声：『我这就送你去见她』\n李莫愁决心杀死" + me->name() +"\n" NOR, environment(), this_object() );
	kill_ob(this_player());
	return 1;
}

int do_look(string target)
{
	object me;
 
	me = this_player();
	if (target=="li" || target=="li mochou" || target=="mochou" ) 
		if ((string)me->query("gender") != "女性")
		{
			message("vision", HIY "李莫愁大怒，喝道：我最恨你们这些薄情的臭男人！去死吧！\n李莫愁决心杀死" + me->name() +"\n" NOR, environment(), this_object() );
			kill_ob(this_player());
		}
}

