//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
	set_name("凌霜华",({ "ling shuanghua", "ling"}));
	set("gender", "女性" );
	set("nickname", HIY"人淡如菊"NOR);
	set("title",HIM"知府千金"NOR);
	set("age", 18);
	set("long", 
"一个清秀绝俗的少女正在观赏菊花，穿一身嫩黄衫子，当真是人淡如菊。\n");
	set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen_type", 1);
	set("str", 14);
	set("per", 28);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("flower_count", 1);
	set("attitude", "friendly");
	set("chat_chance", 5);
	set("chat_msg", ({
		"凌霜华脸红了红，低声道：“对不起，先生别见怪，小丫头随口乱说。”\n",
	}) );
	set("inquiry", ([
		"绿菊"   : (: ask_me :),
		"绿菊花" : (: ask_me :),
		"丁典"   : "“丁大哥为我受尽羞辱。”说罢，眼圈忽地一红。\n",
                "丁大哥" : "“丁大哥为我受尽羞辱。”说罢，眼圈忽地一红。\n",
	]));
	setup();
	carry_object("/d/jiangling/obj/nenhuangshan")->wear();
	carry_object("/clone/cloth/female-shoe")->wear();
}


string ask_me()
{
	object ob;
	
	if (query("flower_count") < 1)
		return "谢谢你提醒我，我会给丁大哥放盆绿菊花的。";
	add("flower_count", -1);
	ob = new("/d/jiangling/obj/greenflower1");
	ob->move(this_player());
	return NOR"麻烦你，把这朵「"HIG"绿玉如意"NOR"」转交给丁大哥，他就会明白的。"NOR;
}
