// npc: shibian.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("侍鞭", ({ "shibian"}) );
	set("nickname", HIM "鞭" NOR );
	set("gender", "女性" );
	set("type","鞭");
	set("age", 20);
	set("no_get", 1);
	set("long", 	
		"她头上包着天青色纱巾，一领天青色布袍，没有一丝褶皱。\n");
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
		"造鞭" : "师傅命我帮助别人造鞭，但到现在也不见一个人影。谁要造鞭呢？\n",
		"原料" : "造鞭只能用寒丝羽竹。\n",
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}


int accept_object(object who, object ob)
{	
	if(!(who->query_temp("whip") ) )
	{
		message_vision(HIC"师傅没有同意为你造鞭，您请回吧！\n"NOR, who);
		return 0;
	}
	who->delete_temp("whip");
	who->set_temp("m_make","鞭");
	switch ((string)ob->query("id") ) 
	{
		case "han zhu": 
			break;
		default :
			message("vision","这是什么！师傅说这不能用来打造长鞭！\n",who);
			return 0;
	}
	message("vision", "侍鞭低头检视了一下手中的"+(string)ob->query("name")+"点了点头说：\n", who);
	message("vision","。。。好我们现在就开始造鞭！\n", who);
	write("请这位"+RANK_D->query_respect(who)+"给鞭起名字吧！(zhu 鞭的名字 英文代号)\n");
	destruct(ob);
	return 1;
}
#include "shi.c"