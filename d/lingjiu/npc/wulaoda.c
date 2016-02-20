// NPC jiuyi.c

#include <ansi.h>

inherit NPC;
string ask_me();

void create()
{
	set_name("乌老大", ({ "wu laoda", "wu"}));
	set("long", @LONG 他就是名动江湖的乌老大，由于谋反童姥未遂而被囚禁于此。
LONG );
	set("gender", "男性");
	set("age", 40);
	set("shen_type",-1);
	set("attitude", "peaceful");

	set("str", 27);
	set("int", 23);
	set("con", 24);
	set("dex", 30);

	
	set("max_qi", 1000);
 	set("qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 0);

	set("combat_exp", 1000000);
	set("score", 100000);

	set("inquiry", ([
		"白云熊胆丸" : (: ask_me :),
	]));
	set("chat_chance", 3);
	set("chat_msg", ({
		"乌老大喃喃道：白云熊胆丸可真是好东西！\n",
	}) );
	set("wan_count", 1);
	setup();
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam=this_player()->query("family")) || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(this_player()) + 
		"你怎敢要灵鹫宫之镇派宝物呢？";
	if (query("wan_count") < 1)
		return "不好意思，已经有人捷足先登了，你下次再来吧。";
	add("wan_count", -1);
	ob = new(__DIR__"obj/baiyunwan");
	ob->move(this_player());
	return "唉，看在你舍身救我的份上，这颗白云熊胆丸就给你吧。";
}
