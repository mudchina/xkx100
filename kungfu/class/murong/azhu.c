// azhu.c

inherit NPC;
//inherit F_SKILL;
int inquiry_tanqin();

void create()
{
	set_name("阿朱", ({ "a zhu", "zhu" }));
	set("long",
		"这是个身穿红衣的女郎，大约十七八岁，一脸精灵顽皮的神气。\n"
		"一张鹅蛋脸，眼珠灵动，别有一番动人风韵。\n");
	set("gender", "女性");
	set("class", "scholar");
	set("age", 17);
	set("per", 29);
	set("shen_type", 1);

	set("neili", 200);
	set("max_neili", 200);
	set("max_qi", 160);
	set("max_jing", 160);
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("blade", 50);
	set_skill("strike", 50);
	set_skill("finger", 50);
	set_skill("murong-sword", 50);
	set_skill("murong-blade", 50);
	set_skill("canhe-finger", 30);
	set_skill("xingyi-strike", 30);
	set_skill("shenyuan-gong", 50);
	set_skill("yanling-shenfa", 50);
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

	set("combat_exp", 10000);
	set("inquiry",([
		"曼陀山庄" : "我才不敢去曼陀山庄，王夫人太霸道了！\n",
		"王语嫣" : "哎，只有她才配得上我们公子，也不知她现在怎样了！\n",
		"阿碧" : "那小丫头也不只跑哪儿去了。\n",
		"弹琴" : ( : inquiry_tanqin : ),
		"南慕容" : "我家公子和丐帮乔帮主齐名，合称“南慕容北乔峰”！\n",
		"慕容复"   : "哎，这你也不懂，他就是我家公子！\n",
		"王夫人"   : "就是公子爷的舅妈，曼陀山庄的庄主！\n",
		"邓百川"   : "你问邓大哥啊？他在他青风庄上呢。\n",
		"公冶乾"   : "公冶二哥把信鸽传书一编码，就没几个人读得懂了。\n",
		"包不同"   : "包三哥最爱抬杠了，你见了他还是闭嘴的好。\n",
		"风波恶"   : "风四哥最是豪爽了，他从不与人计较什么。\n",
	]) );
	create_family("姑苏慕容", 33, "弟子");
	setup();
	carry_object("/d/yanziwu/npc/obj/goldring")->wear();
	carry_object("/d/yanziwu/npc/obj/necklace")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/yanziwu/npc/obj/pink_cloth")->wear();
	carry_object("/d/yanziwu/npc/obj/flower_shoe")->wear();
	carry_object("/clone/misc/mask");
}

int inquiry_tanqin()
{
	object me=this_player();
message_vision("阿朱说道：这位"+ RANK_D->query_respect(me)+"这么有雅兴，那我就为你弹奏一曲?\n只听琴声繁复清亮，你不由的痴了。\n", me );
//	细细品来，竟是张信哲的<<爱如潮水>>!!!\n 
	message_vision("阿朱一曲终了，道个万福，说道：现丑了。\n", me );
	return 1;
}
void attempt_apprentice(object ob)
{
	if ((int)ob->query("betrayer") > 0)
	{
		command("say 这位" + RANK_D->query_respect(ob) +
			"，我慕容家复国乃至为要事，你心志不坚，无缘我门。");
		return;
	}
	command("say 好吧我就收你为徒吧。");
	command("recruit " + ob->query("id"));
}
