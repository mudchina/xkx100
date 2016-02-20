
inherit NPC;
#include <ansi.h>


int ask_me();

void create()
{
	set_name("公平子", ({ "gongping zi", "zi", "referee" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是一位仙风道骨的中年道人，早年云游四方，性好任侠，公正无私。\n");

	set("combat_exp",60000);
                set("shen_type", 1);
	set("attitude", "friendly");

	set("max_qi", 800);
	set("max_jing", 800);
	set("max_neili", 800);
	set("owner","mud os");

	set("win_times", 0);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("sword",80);
	set_skill("parry",80);
	set_skill("dodge", 80);
	set("inquiry", ([
		"华山论剑"       : (: ask_me :),
	]));
  
	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/changjian")->wield();
}

void init()
{
        add_action("do_sign", "sign");
        add_action("do_join", "join");
}

//mixed ask_me()
int ask_me()
{
        object me;

        me = this_player();
        if (PK_D->is_pking())
        {
        	tell_object(me,"公平子对你说道：“现在华山论剑正在举行呢，你想干什么？”\n");
		return 1;
	}
        else if (PK_D->is_ready())
        {
        	tell_object(me,"公平子对你说道：“很好，现在华山论剑正要开始，你要报名(sign)么？”\n");
		return 1;
	}
	else
	{
        	tell_object(me,"公平子对你说道：“华山论剑？你慢慢等着吧。要是无聊，现在要是想进去玩玩(join)也行。”\n");
		return 1;
	}
}

int do_sign()
{
        object me;
        string msg;
        object ob;

        me = this_player();
        message_vision(CYN "\n$N" CYN "陪着笑脸对$n" CYN "道：您好，您好，我也来签个到。\n" NOR, me, this_object());
        
        if (stringp(msg = PK_D->reject_join(me)))
        {
		tell_object(me,"公平子对你说道：“"+msg+"”\n");
                return 1;
        }
        
	me->set_temp("bwdh_join",1);
       	tell_object(me,"公平子对你说道：“华山论剑马上就要开始了，阁下做好准备就赶快加入吧（join）！”\n");
        return 1;
}

int do_join()
{
        object me;
        object *obs;
        int i;
        
        me=this_player();
        if (PK_D->is_pking())
        {
        	tell_object(me,"公平子对你说道：“现在华山论剑正在进行中，你还是等等吧。”\n");
		return 1;
	}
	
	if (PK_D->is_ready() && !me->query_temp("bwdh_join") )
        {
        	tell_object(me,"公平子对你说道：“想要参加论剑的赶紧先报名（sign）吧，其他人还是等等吧。”\n");
		return 1;
	}
	
	obs = all_inventory(me);
	for ( i = 0 ; i < sizeof(obs); i++)
        {
                if (obs[i]->is_character())
                {
                        tell_object(me,"公平子对你说道：“阁下身上背着谁呢？还是先放下再来吧！”\n");
                        return 1;
                }
        }
        
        message_vision(CYN "$N" CYN "赔笑对$n" CYN "道：我想要参加华山论剑，放行可好？\n" NOR, this_player(), this_object());

        if (!PK_D->join_competition(this_player()))
        {
                message("vision", HIW + this_player()->name() + HIW "一闪身进了紫竹林。\n" NOR, environment());
                return 1;
        }
        else
        {
        	tell_object(me,"公平子对你说道：“阁下还是改日再来参加华山论剑吧！”\n");
                return 1;
        }
        	      
}

void unconcious()
{
        die();
}


