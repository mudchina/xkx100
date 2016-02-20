// /kungfu/class/mingjiao/zhangwuji.c
// Last Modified by winder on Oct. 30 2001

#include <ansi.h>
inherit F_MASTER;
inherit F_MANAGER;
inherit F_UNIQUE;
inherit NPC;

void greeting(object ob);
void create()
{
	object ob;
	seteuid(getuid());
	set_name("张无忌", ({ "zhang wuji", "zhang", "wuji" }));
	set("long", "明教教主张无忌，统领天下十万教众，豪气干云，叱咤千秋，\n"
		+"「九阳神功」、「乾坤大挪移」独步天下，是江湖中不世出的\n"
		+"少年英雄。\n");
	set("gender", "男性");
	set("age", 20);
	set("shen_type",1);
	set("attitude", "friendly");
	set("class", "fighter");

	set("per", 28);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3050);
	set("max_qi", 3050);
	set("jing", 3050);
	set("max_jing", 3050);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 150);

	set("combat_exp", 3000000);
	set("score", 455000);
	
	set_skill("force", 200);
	set_skill("cuff", 200);
	set_skill("strike", 200);
	set_skill("claw", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword",200);
	set_skill("blade", 200);
	set_skill("jiuyang-shengong", 200);
	set_skill("qiankun-danuoyi", 250);
	set_skill("sougu", 200);
	set_skill("hanbing-mianzhang", 200);
	set_skill("qishang-quan", 200);
	set_skill("lieyan-dao", 300);
	set_skill("liehuo-jian", 300);
	set_skill("shenghuo-ling", 300);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "qiankun-danuoyi");
	map_skill("sword","shenghuo-ling");
	map_skill("parry","shenghuo-ling");
	map_skill("claw", "sougu");
	map_skill("strike", "hanbing-mianzhang");
	map_skill("cuff", "qishang-quan");
	map_skill("blade", "lieyan-dao");
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	prepare_skill("cuff", "qishang-quan");

	set("party/party_name",HIG"明教"NOR);
	set("party/rank",HIM"教主"NOR);
	create_family("明教", 34, "弟子");

	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.tougu" :),
		(: perform_action, "sword.yinfeng" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );
	set("chat_chance",2);
	set("chat_msg",({
"张无忌愤然说道：“大丈夫当以国为家，捐躯沙场，抗元大业未成，同辈仍需努力！”\n",
"张无忌叹道：“人生失一知己，生亦何欢，死亦何忧，敏儿，你在哪里？”\n",
"张无忌道：“我教兄弟听了：生于乱世，当克己为公，行侠仗义，荡寇驱魔！”\n",
	}));

	set("inquiry",([
		"金毛狮王":"那是我义父谢大侠的职司。\n",
		"谢逊"  :"他就是我义父的大号。\n",
		"张翠山":"你想找我父亲有事麽？\n",
		"殷素素":"我妈是明尊座下紫微堂主。\n",
		"张三丰":"我太师父近来可好？\n",
		"赵敏"  :"人生失一知己，生亦何欢，死亦何忧，敏儿，你在哪里？\n",
		"小昭"  :"小昭我可一直念着她的好处。\n",
		"周芷若":"找她就去峨嵋山，别来烦我。\n",
	]));
	setup();
	if (clonep())
	{
    ob=new(WEAPON_DIR"treasure/yitian-jian");
    if (ob->violate_unique())
      destruct(ob);
    else
      ob->move(this_object());
	}
	carry_object("/clone/book/shenghuo-ling")->wield();
	carry_object("/d/mingjiao/obj/baipao")->wear();
	add_money("silver",70);
}

void init()
{
	object ob;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}
	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
      
        add_action("do_qiecuo","qiecuo");
}

void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;
	if((int)ob->query("shen")<-50000)
	{
		command("wield shenghuo ling");
		command("hit"+(string)ob->query("id"));
		command("unwield shenghuo ling");
	}
	else if((int)ob->query("shen")<-5000)
	{
		command("say 魔从心起，于武学不利，其道必诛，劝君放下屠刀，立地成佛。");
	}
	else if((int)ob->query("shen")<-100)
	{
		command("say 这位朋友，人行江湖，言行当正，切务走进邪魔歪道。");
	}
	else if((int)ob->query("shen")>=0)
	{
		command("say 光明正道任人走，劝君多加保重。");
	}
	else if((int)ob->query("shen")>10000)
	{
		command("say 大侠在上，受无忌一礼，大侠它日必为武林翘楚。");
	}
	return;
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("int")<20)
	{
		command("say 你的悟性太低了，不适合学习我的功夫。");
		return 0;
	}
	if((string)ob->query("gender")=="无性")
	{
		command("say 你阳气不足，习我功夫恐将走火如魔。");
		return 0;
	}
	if((int)ob->query("shen") <= 15000)
	{
		command("say 你应当多作些行侠仗义的事，以修身心。");
		return 0;
	}
	command("say 好，我就收下你这位好徒弟！");
	command("recruit " + ob->query("id"));
	return;
}

int accept_fight(object ob)
{
	if(((int)ob->query("combat_exp")<30000)&&((int)ob->query("shen")>0))
	{
		message_vision("武林中人最忌争强斗狠，你不是我的对手，回去吧。\n",ob);
		return 0;
	}
	message_vision("张无忌一拱手说道：这位"+RANK_D->query_respect(ob)+
	"，在下领教了。\n", ob);
	return 1;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
			command("say 你的职司就是本教的光明使者。");
			ob->set("title", HIR"明教使者"NOR);
 				  }
}
