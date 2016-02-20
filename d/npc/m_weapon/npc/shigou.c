// npc: shigou.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("侍钩", ({ "shigou"}) );
	set("nickname", HIB "钩" NOR );
	set("gender", "男性" );
	set("type","钩");
	set("age", 20);
	set("no_get", 1);
	set("long", 	
		"他头上包着白布头巾，一袭白袍，没有一丝褶皱。\n");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 30);
	set("shen_type", 0);
	set("max_neli",500);
	set("jiali",50);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("force",150);
	set_skill("sword",150);
	set_skill("parry",90);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",50);
	set("combat_exp", 250000);
	set("score",0);
	set("attitude", "peaceful");
	set("inquiry", ([
		"铸钩" : "师傅命我帮助别人铸钩，但到现在也不见一个人影。谁要铸钩呢？\n",
		"原料" : "铸棍可用寒丝羽竹，海底金母，千年神木，陨星铁石。但效果各不一样。\n",
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}


int accept_object(object who, object ob)
{	
	if(!(who->query_temp("hook") ) )
	{
		message_vision(HIC"师傅没有同意为你铸钩，您请回吧！\n"NOR, who);
		return 0;
	}
	who->delete_temp("hook");
	who->set_temp("m_make","钩");
	switch ((string)ob->query("id") ) 
	{
		case "shen mu": 
			who->add_temp("shenmu",1);
			break;
		case "jin mu":
			who->add_temp("jinmu",1);
			break;
		case "han zhu": 
			who->add_temp("hanzhu",1);
			break;
		case "iron stone": 
			who->add_temp("ironstone",1);
			break;
		default :
			message("vision","这是什么！师傅说这不能用来打造兵器！\n",who);
			return 0;
	}
	message("vision", "侍钩低头检视了一下手中的"+(string)ob->query("name")+"点了点头说：\n", who);
	message("vision","。。。好我们现在就开始铸钩！\n", who);

	write("请这位"+RANK_D->query_respect(who)+"给钩起名字吧！(zhu 钩的名字 英文代号)\n");
	return 1;
}
#include "shi.c"