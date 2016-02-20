// NPC yupopo.c
// modified by rocwood

#include <ansi.h>
inherit NPC;
string ask_me();
void create()
{
	set_name("余婆婆", ({ "yu popo", "yu", "popo" }));
	set("long",
		"她是「灵鹫宫」九天九部中昊天部的首领。
她跟随童姥多年，出生入死，饱经风霜。\n");
	set("title", "灵鹫宫昊天部首领");
	set("gender", "女性");
	set("class", "dancer");
	set("age", 60);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);

	set("combat_exp", 100000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("sword",100);
	set_skill("tianyu-qijian",100);
	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong", 100);
	map_skill("force", "bahuang-gong");
	map_skill("dodge", "yueying-wubu");
	map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");
	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand", "zhemei-shou");
	create_family("灵鹫宫",2,"弟子");
	set("inquiry", ([
		"灵鹫宫" : (: ask_me :),
		"拜师"   : (: ask_me :),
	]));
	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",40);
}

void die()
{
	message("vision", HIW"\n余婆婆叹道：“唉，主人，没想到老身不能守住百丈涧！哼，让你们也过不去！”\n"NOR,"/d/lingjiu/jian");
	message("vision", HIW"余婆婆挥动长剑，只听见“乒”的一声，碗口粗的铁索断断成了两截。\n"NOR,"/d/lingjiu/jian");
//	message_vision("$N惨叫一声，死了！\n", this_object());
	::die();
}
string ask_me()
{
	object ob=this_player(),room;
	if(!( room = find_object("/d/lingjiu/xianchou")) )
		room = load_object("/d/lingjiu/xianchou");
	if (!(string)ob->query("family/family_name"))
	{
		if ((string)ob->query("gender")=="女性")
		{
			message_vision("余婆婆冲着$N微笑说：你是来拜师的吧，我送你进去。\n",ob);
			message_vision("余婆婆长袖一拂，$N只觉得一阵狂风吹来，慢慢被吹到山涧对面去。\n",ob);
			ob->move(room);
			return "灵鹫宫的将来有希望了。\n";
		} else return "无耻奸徒打听我灵鹫宫有何居心！\n";
	}
	if ((string)ob->query("family/family_name")=="灵鹫宫")
	{
		message_vision("余婆婆冲着$N点点头，微微笑了笑。\n",ob);
		return "诸位灵鹫宫弟子辛苦了。\n";
	}
	return  "老身奉主人之命守卫百丈涧，非灵鹫宫弟子请回！";
}

