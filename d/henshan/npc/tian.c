//NPC /d/henshan/npc/tian.c
#include <ansi.h>
inherit NPC;
void greeting(object ob);
int accept_fight(object ob);
void create()
{
	seteuid(getuid());
	set_name("田伯光", ({ "tian boguang", "tian" }));
	set("long", "他一身飘逸的白色长衫，风流儒雅。\n");
	set("nickname", HIM "万里独行" NOR);
	set("gender", "男性");
	set("age", 37);
	set("attitude", "friendly");
	set("shen_type", -1);

        set("per", 23);
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 10);

	set("combat_exp", 300000);
	set("score", 40000);

	set_skill("blade", 100);
	set_skill("dodge", 150);
	set_skill("parry", 90);
	set_skill("force", 90);
	set_skill("lingxu-bu", 150);
	set_skill("kuangfeng-blade", 100);

	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "kuangfeng-blade");
	map_skill("blade", "kuangfeng-blade");

        set("chat_msg_combat", ({
                (: perform_action, "blade.kuang" :),
        }) );
	set("chat_chance", 10);
	set("chat_msg", ({
		"田伯光笑道：尼姑也没关系嘛，蓄起头发，两个月就是小美人了。\n",
	}) );

	setup();
	carry_object("/d/baituo/obj/baipao")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	add_money("silver",10);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("gender")=="女性")
	{
if (ob->query("age")<26) say("田伯光笑道：妙极，妙极，又来了一个小姑娘。\n");     
else say("田伯光笑道：妙极，妙极，可惜太老了点，我可没胃口。\n");     
	}
	else say("田伯光笑着招招手：这位"+RANK_D->query_respect(ob) + "来喝两杯，这个小尼姑嘛，反正也没什么事，就让她坐着就是。\n");
	return;
}

int accept_fight(object ob)
{
	if ((string)ob->query("gender") == "女性")
	{
		write("田伯光笑道：花姑娘？杀了太可惜了的。\n");
		return 0;
        }
	return 1;
}
 
int recognize_apprentice(object ob)
{
        if (ob->query_temp("mark/田") > 1)
        {
                ob->add_temp("mark/田", -1);
                return 1;
        }
        else
                return 0;
}

int accept_object(object who, object ob)
{
        object me = this_player();
        if (!(int)who->query_temp("mark/田"))
                who->set_temp("mark/田", 0);
        if (ob->query("money_id") && ob->value() >= 1000) {
                message_vision("田伯光说：好说好说，你要学大爷就教给你。\n", who);
                who->add_temp("mark/田", (int)(ob->value() / 50));
                return 1;
         }
}

