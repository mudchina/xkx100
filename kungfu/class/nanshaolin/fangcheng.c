// Npc: /kungfu/class/nanshaolin/fangcheng.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("方成", ({ "fang cheng", "fang", "cheng"}));
	set("long", "他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，身手却已相\n"
		"当矫捷，看来似乎学过一点武功。\n");
	set("nickname", "狱头");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);

	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("zhanzhuang-gong", 50);
	set_skill("dodge", 50);
	set_skill("yiwei-dujiang", 50);
	set_skill("cuff", 50);
	set_skill("shaolin-cuff", 50);
	set_skill("luohan-cuff", 50);
	set_skill("strike", 50);
	set_skill("weituo-strike", 50);
	set_skill("sanhua-strike", 50);
	set_skill("finger", 50);
	set_skill("mohe-finger", 50);
	set_skill("sword", 50);
	set_skill("damo-sword", 50);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "luohan-cuff");
	map_skill("strike", "sanhua-strike");
	map_skill("finger", "mohe-finger");
	map_skill("sword", "damo-sword");
	map_skill("parry", "damo-sword");
	prepare_skill("strike", "sanhua-strike");
	prepare_skill("finger", "mohe-finger");

	create_family("南少林派", 21, "弟子");

	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
}
void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) )
	{
		remove_call_out("speaking");
		call_out("speaking", 1, ob);
	}
}

void speaking(object ob)
{
	if ( random(5) < 1 )
	{
		switch( random(3) )
		{
			case 0:
				command( "say 百年前的一场大火，整个少林寺就除这监牢和北边\n的钟楼没遭灾。唉。。。\n");
				break;
			case 1:
				command( "say 这里四周全用钢汁浇缝的花岗岩给封了起来，你们\n就是变成苍蝇也飞不出去！\n");
				break;
			case 2:
				command( "say 好好呆着别动，等会儿自然会放你们出去，不过你\n们自己要打架我可不管！\n");
				break;
		}
	}
}
#include "/kungfu/class/nanshaolin/fang.h";

