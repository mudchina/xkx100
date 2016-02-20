// Npc: /d/guiyun/npc/lucf.c
// Last Modified by winder on Jul. 9 2001

inherit NPC;

int ask_ci();
int ask_yue();

void create()
{
	set_name("陆乘风", ({"lu chengfeng", "lu", "chengfeng"}) );
	set("nickname", "归云庄主");
	set("long",
		"他脸色枯瘦，身材甚高，坐在榻上一动不动，似乎双腿有残疾。\n");
	set("gender", "男性" );
	set("age", 42);
	set("attitude", "friendly");
	set("apprentice",1);
	set("str",30);
	set("int",29);
	set("con",28);
	set("dex",5);
	set("max_qi", 1600);
	set("max_jing", 1000);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 40);
	set("combat_exp", 800000);


	set_skill("force", 100);
	set_skill("bibo-shengong", 90);
	set_skill("dodge", 30);
	set_skill("anying-fuxiang", 85);
	set_skill("parry", 90);
	set_skill("strike", 100);
	set_skill("luoying-zhang", 90);
	set_skill("leg", 110);
	set_skill("xuanfeng-leg", 100);
	set_skill("sword", 90);
	set_skill("yuxiao-jian", 80);
	set_skill("taoism", 90);
	set_skill("literate", 100);
	set_skill("qimen-wuxing", 140);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "anying-fuxiang");
	map_skill("strike", "luoying-zhang");
	map_skill("leg", "xuanfeng-leg");
	map_skill("parry", "yuxiao-jian");
	map_skill("sword", "yuxiao-jian");
	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-leg");

	set("rank_info/respect", "庄主");
	set("shen_type", 1);
	set("shen", 100);
	set("vendetta_mark", "桃花岛");
	create_family("桃花岛", 2, "弟子");
	set("class", "fighter");

	set("inquiry", ([
		"name": "老夫陆乘风，是这里的庄主。",
		"rumors": "很久没有曲师兄的消息了，不知他是否出了意外？",
		"here": "这里是归云庄，你随便转转吧，累了请到客房休息。",
		"画" : "这幅画上的词是一位大英雄、大豪杰所作。",
		"词" : (: ask_ci :),
		"药" : "灵药我交付小儿冠英保管了。",
		"三才聚精丹": "灵药我交付小儿冠英保管了。",
		"六壬集气丸": "灵药我交付小儿冠英保管了。",
		"九花玉露丸": "灵药我交付小儿冠英保管了。",
		"字" : "这幅字是老朽写的，你看怎么样？",
		"大英雄": "你先看看词再说，难道你没有读过这首词吗？",
		"大豪杰": "你先看看词再说，难道你没有读过这首词吗？",
		"岳飞"  : (: ask_yue :),
		"岳武穆" : (: ask_yue :),
		"东邪": "那是恩师呀，虽然他打断我们的双腿，还逐我们出岛，但一日为师，终生为父呀！",
		"黄药师": "那是恩师呀，虽然他打断我们的双腿，还逐我们出岛，但一日为师，终生为父呀！",
		"恩师" : "就是桃花岛主黄药师了，他聪明绝顶，文才武学，书画琴棋，算数韬略，医卜星相，奇门五行，无一不精。",
		"家师" : "就是桃花岛主黄药师了，他聪明绝顶，文才武学，书画琴棋，算数韬略，医卜星相，奇门五行，无一不精。",
		"黄蓉": "嗯，那是小师妹，是家师的掌上明珠。",
		"桃花岛": "好怀念原来大家在那里的时光呀，曲师兄临离岛时还画了海图呢。",
		"陆乘风": "就是老夫我，有什么事吗？",
		"陆冠英": "那是小犬，以前送在仙都派门下习艺，现在师父恩准在我门下学艺了。",
		"冠英": "那是小犬，以前送在仙都派门下习艺，现在师父恩准在我门下学艺了。",
		"归云庄": "这里是花了我无数心血才建起来的，与别的庄院相比如何？",
		"太湖": "就在庄前不远，是一个烟波浩淼的大湖。",
		"九宫": "九宫之义，法以灵龟。二四为肩，六八为足；左三右七，戴九履一；五居中间。",
		"八卦": "乾三连，坤六段；离中虚，坎中满；震仰盂，艮覆碗；兑上缺，巽下断。",
		"五行": "金生水，水生木，木生火，火生土，土生金。金克木，木克土，土克水，水克火，火克金。",
		"易经": "是一本讲解伏羲六十四卦的奇书，一般人难得看懂。",
		"周易": "是一本讲解伏羲六十四卦的奇书，一般人难得看懂。",
		"九阴真经": "唉，就是这本书连累了我们大家！",
	]) );

	set("chat_chance", 5);
	set("chat_msg",({
		"陆乘风对着那幅画长叹一声，默然不语，似有满腹心事。\n",
	}));
	setup();

	carry_object(WEAPON_DIR+"sword/yudi")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	object letter;
	string letter_desc;

	if (!ob->query("thd/receive"))
	{
		command("say 没有家师的许可，陆某不敢擅自将恩师的武功转授他人！");
		if (!ob->query("family") && ob->query_int() >= 28)
		{
			command("say 不过我看" + RANK_D->query_respect(ob) + "的资质还不错，这样吧，我写一封推荐信，你拿去找家师吧。");
			letter = new("/d/guiyun/obj/tuijian_xin");
			letter->set("owner", ob->query("id"));
			letter_desc = "这是陆乘风写给黄药师的一封信，上面写着：\n恩师在上：今有" + ob->query("name") + "一名，欲拜入本派，弟子不敢擅专，又念其资质不错，特此推荐与恩师定夺。  乘风叩首\n";
			letter->set("long", letter_desc);
			letter->move(ob);
			message_vision("陆乘风掏出一封推荐信，写上$N的名字，交给了$N。\n", ob);
			command("say 家师是桃花岛主黄药师，你需要从临安附近坐船上岛。至于桃花岛的位置嘛，就在...在...让我想想看...");
			command("consider");
			command("doubt chengfeng");
			command("sigh");
			command("say 居然想不起来了！你去问我师兄曲灵风吧，他在临安东南的牛家村开了一间小店。");
		}
		return;
	}
	ob->delete("thd/receive");
	if (ob->query("gender") != "男性" && ob->query("gender") != "女性") {
		command("say 你不男不女的算什么东西？快滚！");
		return;
	}
	if (ob->query("shen") <= -100000) {
		command("say 家师生平最讨厌两种人，你们这种无恶不作的邪魔外道就是其一，再去求家师吧！");
		return;
	}
	if (ob->query("shen") >= 100000) {
		command("say 家师生平最讨厌两种人，你们这种自命大侠的沽名钓誉之徒就是其一，再去求家师吧！");
		return;
	}
	if (ob->query_int() < 28) {
		command("say 你的才气还不够，再去求家师吧！");
		return;
	}
	if (ob->query("class") == "bonze") {
		command("say 家师比较讨厌少林和尚，我可不敢擅自收你。再去求家师吧！");
		return;
	}
	command("say 既然家师有令，我就收你为徒吧。");
	command("recruit " + ob->query("id"));
	ob->set("class", "fighter");
}

void init()
{
	object ob = this_player();

	add_action("do_answer","answer");
	add_action("do_answer","huida");
	add_action("do_kill","kill");
	::init();
	if (ob->query("family/family_name") == "桃花岛") {
		if ((int)ob->query("shen") <= -100000) {
			message_vision("陆乘风对$N喝道：你做恶多端，有辱家师清名，还敢来见我？！\n", ob);
			message_vision("陆乘风对$N喝道：从今天起，你再也不是桃花岛的弟子了！\n", ob);
			ob->delete("family");
			ob->set("title", "桃花岛弃徒");
		}
		else if ((int)ob->query("shen") >= 100000) {
			message_vision("陆乘风对$N喝道：你是大侠，我早就说过，家师最恨沽名吊誉的伪君子。\n", ob);
			message_vision("陆乘风对$N喝道：从今天起，你再也不是桃花岛的弟子了！\n", ob);
			ob->delete("family");
			ob->set("title", "桃花岛弃徒");
		}
	}
}

int do_kill(string arg)
{
	object ob;
	object me = this_player();
	int perform, payed;

	if (!arg) return 0;
	ob = present(arg, environment(me));
	if (ob == this_object() || ob == me) return 0;
	if (!ob || !ob->is_character()) return 0;
	if (ob->query("family/family_name") == "桃花岛") {
		if (me->query("family/family_name") == "桃花岛") {
			message_vision("陆乘风向$N喝道：小奴才，要造反吗？连自己的同门都杀？！\n", me);
		}
		else {
			message_vision("陆乘风向$N喝道：大胆狂徒，竟敢来归云庄撒野？！\n", me);
			message_vision("陆乘风对$N说道：你先让开，让我来收拾这个" + RANK_D->query_rude(me) + "！\n", ob);
			kill_ob(me);
		}
		me->set("vendetta/桃花岛", 1);
		return 1;
	}
	return 0;
}

int ask_ci()
{
	object ob = this_player();

	command("say 写这首词的大英雄、大豪杰就是岳武穆。\n");
	if(!ob->query_temp("guiyun_lutemp"))
		ob->set_temp("guiyun_lutemp", 1);
	return 1;
}

int ask_yue()
{
	object ob = this_player();

	if(ob->query_temp("guiyun_lutemp") >= 1) {
		command("say 可惜我的字意有一句与岳武穆原意不太相符，不知" + RANK_D->query_respect(ob) + "能否看出来？\n");
		ob->set_temp("guiyun_lutemp", 2);
	}
	else {
		command("say 岳武穆是我非常敬重的一位大英雄。\n");
	}
	return 1;
}

int do_answer(string arg)
{
	object ob = this_player();

	if (ob->query_temp("guiyun_lutemp") == 2) {
		tell_room(environment(ob), ob->name() + "向着陆乘风侃侃而谈。\n", ({ob}));
		if (arg == "知音少,弦断有谁听?" || arg == "知音少，弦断有谁听？" 
		|| arg == "知音少,弦断有谁听" || arg == "知音少，弦断有谁听") {
			if (!present("tuifa tujie", ob) && query_temp("tuifa_give") < 5) {
				say("陆乘风长嘘一声：我这番心情，今日才被你看破，可谓平生一知已，这本腿法就送给你吧。\n");
				new("/d//guiyun/obj/tuifa")->move(ob);
				ob->delete_temp("guiyun_lutemp");
				add_temp("tuifa_give",1);
			}
			else {
				say("陆乘风长嘘一声：我这番心情，今日才被你看破，可谓平生一知已，只可惜老夫我没有什么可以相赠的。\n");
			}
		}
		else {
			command("? " + ob->query("id"));
			message_vision("陆乘风疑惑地看着$N：" + RANK_D->query_respect(ob) + "似乎应该多学些书法绘画吧？\n", ob);
		}
		return 1;
	}
//		say("陆乘风说：这一句字透纸背，你可能谌透我的心境？\n");
	return 0;
}
