// Feb. 6, 1999 by Winder
// jinshe.c 金蛇郎君
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void dest(object ob);
string ask_skill1(object me,string arg);
string ask_skill2(object me,string arg);
string ask_skill3(object me,string arg);
void create()
{
	set_name("夏雪宜", ({"xia xueyi", "xia", "xueyi"}));
	set("nickname", HIY"金蛇郎君"NOR);
	set("gender", "男性");
	set("age", 25);
	set("long", 
		"他就是人称“金蛇郎君”的一代怪杰——夏雪宜。\n"
		"他做事全凭好恶，时正时邪，端地是独来独往，好不潇洒！\n"
		"听说他的身世很惨，人也变得偏激起来。\n"
		"看起来他好象受了点伤，脸色很难看。\n");
 	set("attitude", "peaceful");
	
	set("str", 100);
	set("int", 20);
	set("con", 30);
	set("dex", 25);
	set("chat_chance", 15);
	set("chat_msg", ({
		"夏雪宜突然恶狠狠地说道：仪儿，你到底为什么要害我！？\n",
		"夏雪宜眼中仿佛要喷出火来。\n",
                "突然，夏雪宜“哇”地一声，吐出一大口带黑的血。\n",
	}));
	set("inquiry", ([
		"温仪": "她....她..... \n",
		"锁剑诀" 	:	(: ask_skill1 :),
		"附骨缠身":	(: ask_skill2 :),
		"金蛇吐雾":	(: ask_skill3 :),
	]));
	set("qi", 10000);
	set("max_qi", 10000);
	set("jing", 5000);
	set("max_jing", 5000);
	set("neili", 9000);
	set("max_neili", 9000);
	set("jiali", 100);
	set("no_get",1);
	
	set("combat_exp", 10000000);
	 
	set_skill("force", 200);		// 基本内功
	set_skill("huntian-qigong", 200);	// 混天气功
	set_skill("unarmed", 220);		// 基本拳脚
	set_skill("dodge", 200);		// 基本躲闪
	set_skill("parry", 200);		// 基本招架
        set_skill("sword", 200);                // 基本剑法
        set_skill("jinshe-jian",200);           // 金蛇剑法
	
	map_skill("force", "huntian-qigong");
	map_skill("sword", "jinshe-jian");
	map_skill("parry", "jinshe-jian");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
int accept_object(object who, object ob)
{
	object obn;
	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");
	if (  (string)ob->query("id") != "wen shoupa")
		    return notify_fail("夏雪宜不需要这件东西。\n");
         write(HIY "夏雪宜接过手帕，呆呆地出神，突然间潸然泪下。 \n" NOR);
         write(HIR "夏雪宜喃喃道：仪儿啊，我知道你的心意，其实就算是真的，我也不在乎的。\n" NOR);         
         write(HIY "夏雪宜转过头来对你说：我该怎样感谢你呢？\n" NOR);
         write(HIY "他背转身去，沉默不语，好象在思考着什么。\n" NOR);
         write(HIY "夏雪宜突然象下了很大决心似地对你说：我看\n" NOR);
         write(HIY "你也是武林中人，这里有两本我毕身心血的《金蛇秘芨》，\n" NOR);
         write(HIY "现在它对我来说已经没有什么用了，你就拿去吧。\n" NOR);
         write(HIY "夏雪宜叹了口气道：你是锄恶扬善也好，我行我素也好，胡作非为也好，通通与我无关。\n" NOR);
         write(HIY "夏雪宜挥了挥手：好了，你可以走了。\n" NOR);
         obn = new("/clone/book/jinshe2");
         obn->move(who);
         obn = new("/clone/book/jinshe3");
         obn->move(who);
         write(HIR "夏雪宜回首按了墙上的一个机关，只听得隆隆几声巨响，石壁之上露出一个四方的洞口来。\n"NOR);
         "/d/shiliang/jinshedong"->set("exits/east","/d/shiliang/jinshedong1");
         destruct(ob);
         return 1;
}
void dest(object ob)
{
    destruct(ob);
}
string ask_skill1(object me,string arg)
{
	return teach_perform(this_player(),this_object(),([
		"perform"	: "suo",	//pfm的代码
		"name"		: "锁剑诀",	//pfm的名称
		"sk1"		: "jinshe-jian",//主要的武功的id
		"lv1"		: 100,		//主要的武功的等级
		"sk2"		: "sword",	//需要武功sk2的id
		"lv2"		: 100,		//需要武功sk2 的等级
		"neili"		: 300,		//需要基本内功等级
		"free"		: 1, 		//free=1不需要同一门派
		"msg1"		: "$N哈哈一笑：要学其实这招并不难，天下人都以常理出招。\n"+
				"而我金蛇剑法反其道而行，剑诀要旨在于意境，不在招式。\n"+
				"$n听了$N的指导，恍然大悟。",
		"msg2"		: "好了，你自己继续练习吧。",
		]));
}
string ask_skill2(object me,string arg)
{
	return teach_perform(this_player(),this_object(),([
		"perform"	: "fugu",	//pfm的代码
		"name"		: "附骨缠身",	//pfm的名称
		"sk1"		: "jinshe-zhang",//主要的武功的id
		"lv1"		: 100,		//主要的武功的等级
		"sk2"		: "strike",	//需要武功sk2的id
		"lv2"		: 100,		//需要武功sk2 的等级
		"neili"		: 300,		//需要基本内功等级
		"free"		: 1, 		//free=1不需要同一门派
		]));
}
string ask_skill3(object me,string arg)
{
return teach_perform(this_player(),this_object(),([
		"perform" 	: "tuwu",	//pfm的代码
		"name"		: "金蛇吐雾",	//pfm的名称
		"sk1"		: "jinshe-zhui",//主要的武功的id
		"lv1"		: 100,		//主要的武功的等级
		"sk2"		: "throwing",	//需要武功sk2的id
		"lv2"		: 100,		//需要武功sk2 的等级
		"force"		: 100,		//需要基本内功等级
		"neili"		: 300,		//需要最大内力多少
		"free"		: 1, 		//free=1不需要同一门派
		]));
}
