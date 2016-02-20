// Npc: /d/lingxiao/npc/dizi.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("弟子",({"lingxiao dizi","dizi"}));
	set("gender", "男性");
	set("age", 20);
	set("long", "这是一个凌霄城的普通弟子。\n");
	set("attitude", "peaceful");

	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);
	set("neili", 500);
	set("max_neili", 500);
	set("max_jing", 400);
	set("jing", 400);
	set("max_qi", 800);
	set("qi", 800);
	set("jiali", 20);

	set("combat_exp", 20000);
	set("shen_type", 0);
	set("score", 50000);
	set("chat_chance", 10);
	set("chat_msg", ({
       "一名凌霄城弟子小声说道：听说老爷子发疯了，还把封师叔的膀子卸了下来，不知道是真是假。\n", 
       "凌霄弟子冷笑道：打起来了好啊，这下子半年一次的论剑也不用开了，免得挨骂。\n", 
       "一名凌霄城弟子哼了一声，道：师父一向说我们凌霄城的剑法天下无双，改天我要让那些江湖中人见识一下。\n",
       "一名凌霄城弟子不屑道：老爷子的病是气出来的，你们不知道吧。\n",
       "凌霄城弟子哼了一声，道：马上赏善罚恶使者要来了，我们还是先跑路吧。\n",
       "凌霄城弟子摇摇头，道：就算赏善罚恶使者来了，只要有人接令牌，我们这些小人物也没事。\n",
       "一名凌霄城弟子打了个哈欠，道：昨天轮到老子守城，差点被冷死。\n",
       "一名凌霄城弟子搓了搓手，道：昨天我从师父的柜子里偷了瓶参阳玉酒，嘿嘿……真他妈的不错。\n",
       "一名凌霄城弟子看看四周，小声说道：上次谢烟客来的时候，带的那个狗杂种，听说是长乐帮的帮主。\n",
       "一名凌霄城弟子摆了个架势，大声说：武当少林算什么！老爷子说了，武林中就我们凌霄城最厉害！\n",
       "一名凌霄城弟子掏出一瓶酒，喝了两口，红着眼睛说：老爷子是被成师叔祖他们暗算了！我等会就去把他救出来！\n",
       "一名凌霄城弟子低声对另一位弟子说，要想进地牢，就必须先拿到寒玉牌啊。\n",
       "一名凌霄城弟子愤愤说道：那个狗杂种，上次竟想对阿绣非礼，要是让我遇见，哼哼哼！\n",
	}) );
	set_skill("strike", 50);
	set_skill("sword", 60);
	set_skill("force", 60);
	set_skill("parry", 50);
	set_skill("dodge", 60);
	set_skill("literate", 20);

	set_skill("xueshan-sword", 60);
	set_skill("bingxue-xinfa", 50);
	set_skill("snow-strike", 40);
	set_skill("snowstep", 50);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("凌霄城", 7, "弟子");
	setup();

	carry_object("/d/lingxiao/obj/icesword")->wield();	
	carry_object(CLOTH_DIR+"bai")->wear();
}

void init()
{
	if( this_player()->query("family/master_id") == "bai zizai") {
		message_vision(HIC "凌霄弟子向$N躬身为礼，说道：师叔您老人家好！\n" NOR, 
		this_player());
	}       
}

