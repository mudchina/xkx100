// gongye.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("公冶乾", ({ "gongye qian", "gongye","qian" }));
	set("title", "姑苏慕容 "HIR"赤霞庄主"NOR );
	set("long", "这是一个文士打扮的中年书生，豪迈过人。\n");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2000);
	set("max_jing", 1100);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 400000);
	set("score", 50000);

	set_skill("force", 110);
	set_skill("dodge", 110);
	set_skill("parry", 110);
	set_skill("sword", 110);
	set_skill("blade", 110);
	set_skill("strike", 110);
	set_skill("finger", 110);
	set_skill("literate", 110);
	set_skill("murong-sword", 160);
	set_skill("murong-blade", 160);
	set_skill("canhe-finger", 160);
	set_skill("xingyi-strike", 160);
	set_skill("shenyuan-gong", 110);
	set_skill("yanling-shenfa", 160);
	map_skill("parry", "murong-sword");
	map_skill("sword", "murong-sword");
	map_skill("blade", "murong-blade");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("finger", "canhe-finger");
	map_skill("strike", "xingyi-strike");
	prepare_skill("finger", "canhe-finger");
	prepare_skill("strike", "xingyi-strike");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({		
		(: perform_action, "sword.lianhuan" :),
		(: perform_action, "finger.dian" :),
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );
	set("inquiry",([
		"王语嫣"   : "只有她才配得上我们公子，也不知她现在怎样了！\n",
		"南慕容" : "我家公子和丐帮乔帮主齐名，合称“南慕容北乔峰”！\n",
		"慕容复"   : "哎，这你也不懂，他就是我家公子！\n",
		"王夫人"   : "就是公子爷的舅妈，曼陀山庄的庄主！\n",
		"阿朱"     : "那小妮子只大我一岁，整天就喜欢扮别人玩。\n",
		"邓百川"   : "你问邓大哥啊？他在他青风庄上呢。\n",
		"公冶乾"   : "别问我，烦着呢。\n",
		"包不同"   : "包三弟最爱抬杠了，你见了他还是闭嘴的好。\n",
		"风波恶"   : "风四弟最是豪爽了，他从不与人计较什么。\n",
	]) );

	create_family("姑苏慕容", 33, "弟子");
 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("betrayer") > 0)
	{
		command("say 这位" + RANK_D->query_respect(ob) +
			"，我慕容家复国乃至为要事，你心志不坚，无缘我门。");
		return;
	}
	if ((int)ob->query_skill("shenyuan-gong", 1) < 50)
	{
		command("say 姑苏慕容家武功，以内功为根基。");
		command("say "+RANK_D->query_respect(ob)+"还应该多加努力！");
		return;
	}
	command("say 好吧我就收你为徒吧。");
	command("recruit " + ob->query("id"));
}
