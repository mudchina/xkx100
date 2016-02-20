// dingdang.c 丁当

inherit NPC;
string inquiry_yu();

void create()
{
	set_name("丁当", ({ "ding dang","ding"}) );
	set("gender", "女性" );
	set("age", 18);
	set("long", "一个十七八岁的少女，身穿淡绿衫子，一张瓜子脸，秀丽美艳。\n");
	set("shen_type", 1);
	set("combat_exp", 100000);
	set("str", 18);
	set("dex", 22);
	set("con", 25);
	set("int", 35);
	set("per",30);
	set("attitude", "friendly");

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);

	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 200);
	set_skill("taiji-shengong", 200);
	set_skill("taiji-quan", 200);
	set_skill("tiyunzong", 500);

	map_skill("force","taiji-shenfong");
	map_skill("unarmed","taiji-quan");
	map_skill("parry","taiji-quan");
	map_skill("dodge","tiyunzong");
	set("chat_change",15);

	set("chat_msg",({
		"丁当念叨着: 也不知道我的玉哥哥现在怎么样了。\n",
		"丁当暗暗抹了把眼泪。\n",
		"丁当一跺脚，说道: 不行，我要上摩天崖把我的玉哥哥救回来。\n",
		"丁当叹了口气，说道: 要是有玄铁令就好了。\n",
	}) );
	set("inquiry",([
		"石中玉" : (: inquiry_yu :),
		"摩天崖" : "前面这座山就是了，你要小心呀，那个老头的武功好强呀。\n",
		"玄铁令" : "据说是在石破天手里，真假我就不知道了。\n",
	]) );
	set_temp("shoupa",1);
	setup();
	carry_object("/clone/jewelry/shouzhuo")->wear();
	carry_object("/clone/jewelry/yupei")->wear();
	add_money("gold", 1);
}

string inquiry_yu()
{
	object me=this_player();
	object obn;

	message_vision("丁当说道：这位"+ RANK_D->query_respect(me)+"，玉哥哥是我的夫君，\n"+"可是去年在雪山派被谢烟客抓去，囚禁起来。现在也不知是死是活。唉！\n", me );
	if(query_temp("shoupa")==0)
	{
		message_vision("丁当又说道：这位"+ RANK_D->query_respect(me)+"，我已经托"+"人去摩天崖看看了，也不知道怎么样了。\n",me);
		return "真急人！";
	}
	message_vision("丁当从怀里拿出一个漂亮的手帕，交给$N。\n", me);
	obn=new("/d/xiakedao/obj/shoupa");
	obn->move(me);
	set_temp("shoupa",0);
	
	return "这位" +RANK_D->query_respect(me)+"，我这里有一个手帕，是我随身之物，你看到我的玉哥哥\n你就把手帕交给他，他会明白的。拜托了。";
}

