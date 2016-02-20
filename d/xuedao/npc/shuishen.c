// shuisheng.c

inherit NPC;
#include <ansi.h>
string ask_me();
void create()
{
	set_name("水笙", ({ "shui sheng", "shui" }));
	set("long", 
	"她是个生得十分秀美清丽动人的江南佳丽。\n"
	"她和她的表哥汪啸风号称“铃剑双侠”，名动东南。\n");
	set("gender", "女性");
	set("nickname", HIM"铃剑女侠"NOR);
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("per", 28);
	set("str", 25);
	set("int", 28);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 1000);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 10);
	set("combat_exp", 200000);
	set("shen_type", 1);

	set_skill("force", 80);
	set_skill("huashan-neigong", 80);
	set_skill("dodge", 80);
	set_skill("huashan-shenfa", 80);
	set_skill("strike", 80);
	set_skill("huashan-zhangfa", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("huashan-jianfa", 80);
	set_skill("literate", 80);

	map_skill("force", "huashan-neigong");
	map_skill("dodge", "huashan-shenfa");
	map_skill("strike", "huashan-zhangfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	set("inquiry", ([
		"狄云" : (: ask_me :),
	]));
	set("chang_count", 1);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (query("chang_count") < 1)
		return "狄大哥还好吗？我在这里等了他这么久！我知道他终于会回来的。";
	add("chang_count", -1);
	ob = new("/d/xuedao/obj/dachang");
	ob->move(this_object());
	command("give da chang to "+this_player()->query("id"));
	return "狄大哥还好吗？我在这一直等着他。麻烦你，把这领大氅交给他吧。";
}
