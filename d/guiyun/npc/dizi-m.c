// Npc: /d/guiyun/npc/dizi-m.c
// Last Modified by winder on Jul. 9 2001

inherit NPC;

void create()
{
	int name_no = random(4); 
	string *name_string = ({"伯","仲","叔","季"});

	set_name("男弟子", ({"nan dizi", "nan", "dizi"}) );
	set("long", "他正在专心致志地练习功夫。\n");
	set("gender", "男性" );
	set("age", 26);
	set("attitude", "peaceful");
	set("str",22);
	set("int",28);
	set("con",18);
	set("dex",20);
	set("max_qi", 700);
	set("max_jing", 270);
	set("neili", 500);
	set("max_neili", 340);
	set("jiali", 12);
	set("combat_exp", 20000);

	set_skill("force", 35);
	set_skill("bibo-shengong", 30);
	set_skill("dodge", 35);
	set_skill("anying-fuxiang", 30);
	set_skill("parry", 40);
	set_skill("strike", 30);
	set_skill("luoying-zhang", 28);
	set_skill("leg", 30);
	set_skill("xuanfeng-leg", 25);
	set_skill("sword", 40);
	set_skill("yuxiao-jian", 35);
	set_skill("taoism", 20);
	set_skill("literate", 40);
	set_skill("qimen-wuxing", 40);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "anying-fuxiang");
	map_skill("strike", "luoying-zhang");
	map_skill("leg", "xuanfeng-leg");
	map_skill("parry", "luoying-zhang");
	map_skill("sword", "yuxiao-jian");
	prepare_skill("strike", "luoying-zhang");

	set("shen_type", 0);
	create_family("桃花岛", 3, "弟子");
	set("class", "fighter");

	set("inquiry", ([
		"name"  :"在下复姓司马，名唤"+name_string[name_no]+ "雄，从十六岁起便投在这里学艺。",
		"rumors":"听说师祖收徒很重视悟性和文化，我得多读些书了。",
		"here"  :"这里是归云庄，你随便转转吧，累了请到客房休息。",
		"东邪"  :"那是师祖呀，，蒙他老人家恩准，我才能跟陆庄主学艺。",
		"黄药师":"那是师祖呀，，蒙他老人家恩准，我才能跟陆庄主学艺。",
		"桃花岛":"听说是师祖住的地方，可惜没有去看过。",
		"陆乘风":"是我的师父，这里的庄主，你找他老人家有什么事吗？",
		"归云庄":"听说这里是花了庄主无数心血才建起来的，与别的庄院相比如何？",
		"太湖"  :"就在庄前不远，是一个烟波浩淼的大湖。",
	]) );
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
}
