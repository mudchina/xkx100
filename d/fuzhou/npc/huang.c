// huang.c

#include <ansi.h>

inherit NPC;
//inherit F_SKILL;
int ask_diubiao();

void create()
{
	set_name("黄先生", ({ "huang xiansheng", "huang" }));
	set("title", HIR"福"HIC"威"YEL"镖局"HIY"账房"NOR);
	set("gender", "男性");
	set("age", 36);

	set("inquiry", ([
		"丢镖" : (: ask_diubiao :),
		"失镖" : (: ask_diubiao :),
		"失败" : (: ask_diubiao :),
	]) );

	set("combat_exp", 10000);
	set("shen_type", 1);

	set("eff_qi",800);
	set("qi",800);
	set("max_neili", 100);
	set("neili", 100);
	set("jiali", 10);


	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
	object myenv ;
	if(who->query_temp("fuwei_diubiao_ask")&&(ob->query("money_id") && ob->value() >= 100000))
    {
		message_vision(HIY"黄老先生对$N说：好吧！就再给你一次机会了！\n"NOR , who);
	    who->delete_temp("fuwei_destm");
	    who->delete_temp("fuwei_dest");
	    who->delete_temp("fuwei_diubiao_ask");
	    who->delete_temp("fuwei_ready");
            who->delete_temp("fuwei_prepare");
            return 1;  
         }
	if(who->query_temp("fuwei_ready"))
	{
		message_vision(HIY"黄老先生对$N说：又给我钱？好！好！留着我喝老酒！\n"NOR , who);
		return 1;
	}
	if(!who->query_temp("fuwei_prepare"))
	{
		message_vision(HIY"黄老先生对$N说：要押镖，该先去找总镖头！\n"NOR, who);
		return 1;
	}
	if ( wizardp(who) || (ob->query("money_id") && ob->value() >= 200000))
	{
		message_vision(HIY "黄老先生对$N说：镖车准备好了，在院子里呢。赶快接镖(jiebiao)吧！\n丢了镖押金就赔偿给镖主！\n"NOR , who);
		who->set_temp("fuwei_ready",1);
		who->delete_temp("fuwei_prepare",1);
		return 1;
	}
	else
	{
		message_vision(HIR"黄老先生皱着眉对$N说：就这点？你还保什么镖？出去出去！\n"NOR, who);
		return 0;
	}
}

int ask_diubiao()
{ 
	object me = this_player();
	if (me->query_temp("fuwei_dest"))
	{
message_vision(HIR"黄老先生皱着眉对$N说：那上面可是有好几万镖银啊！你要还想继续保镖就先交十两黄金来吧！\n"NOR, me);
        me->set_temp("fuwei_diubiao_ask",1);
        return 1;
	}
        else 
        {
          message_vision(HIR"黄先生皱眉道:你好象没接过镖吧？\n",me);
          return 1;
        }
          
}
