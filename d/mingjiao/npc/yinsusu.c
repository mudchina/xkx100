// Yinsusu.c

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int ask_me();
int decide();
void goto_wpsd1(object me);
void goto_wpsd2(object me);
#include <ansi.h>

void create()
{
	set_name("殷素素", ({ "yin susu", "yin", "susu", }));
	set("long","她是白眉鹰王的独生女。手白胜雪，玉颊微瘦，眉弯鼻挺，一笑时
左颊上浅浅一个梨涡。\n"
	);

	set("gender", "女性");
	set("attitude", "friendly");
	set("class", "fighert");

	set("age", 18);
	set("shen_type", 1);
	set("per", 29);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 85);
	set_skill("hunyuan-yiqi", 85);
	set_skill("dodge", 85);
	set_skill("shaolin-shenfa", 85);
	set_skill("cuff", 95);
	set_skill("jingang-quan", 95);
	set_skill("parry", 85);
	set_skill("buddhism", 85);
	set_skill("literate", 85);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");

	set("inquiry", ([
		"谢逊"      : (: ask_me :),
		"冰火岛"    : (: ask_me :),
		"屠龙刀"    : (: ask_me :),
		"金毛狮王"  : (: ask_me :),
		"白眉鹰王"  : "那是我爹。",
	]));
	prepare_skill("cuff", "jingang-quan");

	set("party/party_name",HIG"明教"NOR);
	set("party/rank",HIM "紫微堂" NOR "堂主");
	create_family("明教", 35, "弟子");
	setup();

	carry_object("/d/yanziwu/npc/obj/green_cloth")->wear();
}

void init()
{
	add_action("do_decide", "decide");
}

int ask_me()
{
	object me;
	me = this_player ( ) ;
	message_vision(
"殷素素上上下下打量了$N一下，道：这位"+RANK_D->query_respect(me)+"，你不过是想屠龙刀吧。\n这小船也经不起海浪，我正要去王盘山岛，你看看快点决定(decide)要不要去。\n",me);

	me->set_temp ("yinsusu", 1 );
	return 1;
}

int do_decide()
{
	object me;
	me = this_player ( ) ;
	if (me->query_temp("yinsusu") != 1 )
		return notify_fail("殷素素问：你决定什么呀？\n");

	message_vision("殷素素对$N说道：“好，你可别后悔，坐稳了。”\n\n", me);
	message_vision("殷素素升起帆，小舟轻轻漂向江口。\n\n", me);
	me->move ("/d/binghuo/jiangmian1");
	call_out("goto_wpsd1",10,me) ;
       	return 1;
}

void goto_wpsd1(object me)
{
	message_vision("风帆带风，小舟在剧颠中漂出江口。\n\n", me);
	me->move ("/d/binghuo/jiangmian2");
	call_out("goto_wpsd2",10,me) ;
}

void goto_wpsd2(object me)
{
	tell_object(me , "片刻间坐船靠岸，白龟寿亲自铺上跳板。你走下舟来。\n" ) ;
	me->move ("/d/binghuo/wangpanshan") ;
}

