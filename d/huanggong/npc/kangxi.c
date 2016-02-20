//kangxi.c 康熙大帝

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;

string * officer = ({
	"守备",
	"都司",
	"游击",
	"参将",
	"副将",
	"总兵",
	"提督",
	"总督",
	"大将军",
});
int ask_officer();
void dest(object ob);

void create()
{
	set_name(HIR "康熙大帝" NOR, ({"kang xi", "kang"}));
	set("title", "清圣祖");
	set("gender", "男性");
	set("age", 36);
	set("str", 25);
	set("dex", 20);
	set("int", 28);
	set("con", 28);
	set("per", 27);
	set("long", HIR @LONG
这位高大魁梧，英俊潇洒的男子就是天下独尊的康熙大帝。
LONG NOR
	);

	set("combat_exp", 500000);
	set("score", 20000);
	set("shen_type", 1);
	set("attitude", "peaceful");


	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("literate", 100);
	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("finger", 100);
	set_skill("nianhua-zhi", 100);
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "nianhua-zhi");
	map_skill("finger", "nianhua-zhi");
	prepare_skill("finger", "nianhua-zhi");

	set_temp("apply/attack", 50);
	set_temp("apply/defence", 50);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 35);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 600);
	set("max_jing", 600);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 80);

	set("inquiry", ([
		"韦小宝" : "\n小宝是我的心腹,我让他为我收集各大官员的消息.\n",
		"鳌拜": "\n鳌拜虽是开朝元老,但太骄横跋负了,终是我的心腹大患.\n",
		"官职" : (:ask_officer:),
		"职务" : (:ask_officer:),
		"封赏" : (:ask_officer:),
	]));
        set("chat_chance", 3);
        set("chat_msg", ({
    "康熙往匾额上看了看。\n",
		"康熙说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
		"康熙说道：天下取士，非贤积德。我朝马上得天下，不能马上治天下。 \n",
		"康熙说道：想要官职，当然问朕了。\n",
		"康熙说道：收齐四十二章经者，朕重重有赏。\n",
        }) );
	setup();
	carry_object(__DIR__"obj/jinduan")->wear();
	add_money("gold", 5);
}
int ask_officer()
{
	int lv, worked;
	string officerlvl;
	object ob = this_player();
	lv = ob->query("officerlvl");
	worked = ob->query("bt/worked");
	if (lv < 1) 
	{
		command("say "+ob->query("name")+"，朕没有给扬州知府下旨，你来此何干？！\n");
		return 1;
  }
  if (ob->query_temp("guard"))
   {
    command("say "+ob->query("name")+"，朕已经给你封赏官职了，你下去吧！");
    return 1;
   }
  officerlvl = officer[lv-1];
	command("chat "+ob->query("name")+"，你秉承旨意，忠君爱民，朕甚嘉许。着兵部实授"+officerlvl+"之职！\n");
	ob->set("guard",HIY+officerlvl+NOR);
	ob->set_temp("guard",1);
	return 1;
}

int accept_object(object me, object ob)
{
	object gold;
	object cloth;
	int exp,pot,score;
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
	if ( ob->query("id") == "book1") 
	{
		me->set_temp("book14/1", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else if ( ob->query("id") == "book2") 
	{
		me->set_temp("book14/2", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else	if ( ob->query("id") == "book3") 
	{
		me->set_temp("book14/3", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else
	if ( ob->query("id") == "book4") 
	{
		me->set_temp("book14/4", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else
	if ( ob->query("id") == "book5") 
	{
		me->set_temp("book14/5", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else
	if ( ob->query("id") == "book6") 
	{
		me->set_temp("book14/6", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else
	if ( ob->query("id") == "book7") 
	{
		me->set_temp("book14/7", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else
	if ( ob->query("id") == "book8") 
	{
		me->set_temp("book14/8", 1);
		command("smile "+me->query("id"));
		call_out("dest",0,ob);
	}
	else
	{
		command("shake ");
		command("say 朕只是想找四十二章经，你且退下。");
	}
	if ( me->query_temp("book14/1") &&
	     me->query_temp("book14/2") &&
	     me->query_temp("book14/3") &&
	     me->query_temp("book14/4") &&
	     me->query_temp("book14/5") &&
	     me->query_temp("book14/6") &&
	     me->query_temp("book14/7") &&
	     me->query_temp("book14/8")) 
	{
		command("chat "+me->query("name")+"，你找回八部四十二章经，有功于社稷，赐黄马褂一件！\n");
		cloth = new(__DIR__"obj/ycloth");
		me->delete_temp("book14");
		cloth -> move(me);
		gold = new("/clone/money/gold");
		gold->set_amount(20);
		gold->move(this_object());
		command("give 20 gold to "+me->query("id"));
		if (!me->query("skybook/luding/42jing"))
   {
		 me->set("skybook/luding/42jing",1);
		 exp=500+random(1000);
     pot=exp/2;
     score=pot/2;
     me->add("combat_exp",exp);
     me->add("potential",pot);
     	tell_object(me,HIC"你成功得到了康熙的信任！\n在这次历练中你获得了"+
     	         chinese_number(exp)+"点经验、"+
               chinese_number(pot)+"点潜能以及"+
               chinese_number(score)+"点江湖阅历。\n\n"NOR);
		}
		
	}
	return 1;
}

void dest(object ob)
{
	destruct(ob);
}