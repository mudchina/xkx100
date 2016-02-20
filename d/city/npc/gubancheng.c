// npc: /d/city/npc/gubancheng.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>
inherit NPC;

void create()
{
	set_name( YEL "顾半城" NOR, ({"gu bancheng","gu","bancheng"}) );
	set("gender", "男性" );
	set("title", "顾家彩帛铺老板");
	set("age", 51);
	set("long", @LONG
顾老板的生意很是红火，店铺里全是人，看起来应该扩大店面了。有人
说是他的名字起得好，“半城”嘛，半个城的人都到他这里来买布匹绸
缎，生意还能不好？不过，现在似乎他有把名字改成“全城”的打算。
LONG
	);
	set("chat_chance", 40);
	set("chat_msg", ({
		"顾老板道：客官，看看这上好的湖绸吧！\n",
		"顾老板道：扬州城是天下最繁华的地方啦，没有啥这里买不到的。\n",
		"顾老板道：呵呵，小老儿这家店也就能糊口，您别听他们瞎吹。\n",
		"顾老板道：嗯，本府的程老爷，那真是爱民如子啊！\n",
	}));
	set("inquiry", ([
		"彩帛" : "您家要块绸缎？随便挑，随便挑……\n",
		"here" : "这儿是扬州府，从这儿到东京和大理都很方便的。\n",
	]) );
	set("attitude", "friendly");
	set("rank_info/respect", "老哥");
	set("rank_info/rude","老王八蛋");
	set("combat_exp",100);
	set_skill("unarmed", 5);
	setup();
	carry_object( "/clone/cloth/male-cloth")->wear();
}

void init()
{
	object ob = this_player();
	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision("顾老板忙着给客人量布，一回头，见有人进来，招呼一声：“您稍等！”\n",ob);
	return;
}
