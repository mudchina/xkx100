// azi.c 阿紫

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_azi();

void create()
{
//	set_name("阿紫", ({ "azi" }));
	set_name("阿紫", ({ "a zi","azi" }));
	set("nickname", "星宿派小师妹");
	set("long", 
		"一个身穿紫衣的美貌少女。她瓜子白净脸，容颜俏丽，
可眼神中总是透出一股邪气。\n");
	set("gender", "女性");
	set("age", 15);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", -1);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 24);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 10);
	set("combat_exp", 50000);
	set("score", 10000);

	set_skill("force", 40);
	set_skill("huagong-dafa", 50);
	set_skill("dodge", 30);
	set_skill("zhaixinggong", 40);
	set_skill("strike", 30);
	set_skill("chousui-zhang", 40);
	set_skill("claw", 30);
	set_skill("sanyin-wugongzhao", 40);
	set_skill("parry", 20);
	set_skill("poison", 20);
	set_skill("staff", 20);
	set_skill("tianshan-zhang", 80);
//	set_skill("literate", 30);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "tianshan-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("env/wimpy", 60);

	set("inquiry", ([
		"星宿派" : "你想加入，就拜我为师。",
		"深涧"   : "嘿嘿，哪有那么容易就告诉你。",
		"星宿海" : "去星宿海干什么？拜我为师就够你学的了。",
		"丁春秋" : "丁春秋是你叫的吗？没大没小的。以后叫老仙！",
		"老仙"   : "你得多吹捧老仙，否则别想有出头之日。\n",
		"神王木鼎" : "我送了给我姐夫啦。有本事你自己去拿。",
		"姐夫"   : "连我姐夫萧峰都不知道，你真是个大呆瓜。",
		"星宿"   : "你问的可是星宿派？",
		"吹捧"   : "女的容易多了，我最讨老仙喜欢。男的得更加把劲。",
		"阿紫"   : "就是本姑娘我啊，你要怎么样？！\n",
		"神木王鼎" : (: ask_azi :),
	]));
	create_family("星宿派", 2, "弟子");
	setup();
	carry_object("/clone/medicine/nostrum/qingxinsan");
	carry_object("/d/xingxiu/obj/baihuqiu")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("shen") > 0)
	{
		command("say 你看上去真是个假正经，我才不想收你呢。");
		return;
	}
	command("say 嘻嘻，我就收下你了吧。");
	command("recruit " + ob->query("id"));
}
string ask_azi()
{
	mapping fam; 
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if( this_player()->query_temp("smwd/step") )
	{
		this_player()->delete_temp("smwd/step", 1);
		ob=new(__DIR__"obj/ding");
		ob->move(this_object());
		command("fear");
		command("mapi "+this_player()->query("id"));
		return "师父他老人家的宝贝东西怎么会在我这？！这位小"+RANK_D->query_close(this_player())+"一定搞错了吧？";
	}
	else return "师父他老人家的宝贝东西怎么会在我这？！";
}

