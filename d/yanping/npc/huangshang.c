// huangshan.c 黄裳
// Last Modified by winder on Aug. 18 2002

inherit NPC;
string ask_book();
string ask_jing();

void create()
{
	set_name("黄裳", ({ "huang shang", "huang", "shang" }));
	set("long","
　　黄裳，剑浦人，字冕仲、号演山。生卒年不详。
　　黄裳为书生时，常有魁天下之志。自叙门状，予家剑潭之滨，斗牛之
光，上下相照，风雷之信，时有变现。又题黄龙州云：“看取黄龙沙斗起， 
满城风雨入丰年。”元丰四年（1081），郡之谯门，忽为风雷所击，黄裳
闻之，赋诗道：“风雷昨夜破枯枝，借问天公有意无，莫是卧龙踪迹困，
放教头角入亨衢。”次年，黄裳对策，果为天下第一。宋神宗对黄裳之文
章极为喜爰，礼部奏进士，有黄裳名，及进读试策，前几位皆不合神宗之
意，神宗等黄裳名出现，但未甲才始听到，遂亲擢为第一。考官因高下失
实被处罚金。
　　黄裳为官清正恬退。政和间（1111—1118），知福州，尝为礼部侍郎，
迁尚书。当时三舍法实行，黄裳认为“宜近不宜远，宜少不宜老，宜富不
宜贫，不如遵祖宗科举之制。”黄裳享年八十七岁，著有《演山集》六十
卷行于世。
    历史上，黄裳乃一介书生，与武无缘。

");
	set("gender", "男性");
	set("age", 61);
	set("attitude", "peaceful");
	set("class", "scholar");
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_jing", 3000);
	set("max_qi", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 50);
	set("combat_exp", 5000000);
	set("score", 60000);
	set("inquiry", ([
		"秘籍" : (: ask_jing :),
		"jing" : (: ask_jing :),
		"book" : (: ask_book :),
		"九阴真经" : (: ask_jing :),
		"万寿道藏" : (: ask_book :),
	]));
	set("book_count", 1);
	set("jing_count", 1);
	setup();
}

string ask_book()
{
	mapping fam; 
	object ob, me = this_player();

	if (query("book_count") < 1)
		return "这么笨重的书，"+RANK_D->query_respect(me)+ "要来又有啥用？";
	if (me->query_skill("taoism",1) < 100)
		return "这部万寿道藏太过艰深，"+RANK_D->query_respect(me)+ "恐怕读不懂罢？";
	add("book_count", -1);
	ob = new(BOOK_DIR"daojing");
	if (ob->violate_unique())
	{
		destruct(ob);
		return "这么笨重的书，"+RANK_D->query_respect(me)+ "要来又有啥用？";
  }
	ob->move(environment(me));
	command("rumor "+me->query("name")+"拿到万寿道藏啦。\n");
	tell_room(environment(me), "黄裳转过身去，从书架上抱下一部大书，堆在地上。\n", ({ob}));
	return "好吧，这部「万寿道藏」你拿回去好好钻研。";
}

string ask_jing()
{
	mapping fam; 
	object ob, me = this_player();
	mixed sks;
	string skl;
	
	if (query("jing_count") < 1)
		return "《九阴真经》是我几十年心血所驻，岂能轻给？";
	if ( !me->query("xkd/skill") )
		return "《九阴真经》所载武功博大精深，"+RANK_D->query_respect(me)+ "恐怕读不懂罢？";
	if ( me->query("kar") != query("kar") && !wizardp(me))
		return "万事随缘，学习武功也是这样的，你看，很不巧，你要的《九阴真经》给人借阅未还。";
	add("jing_count", -1);
	ob = new(BOOK_DIR"9book");
	if (ob->violate_unique()) 
	{
		destruct(ob);
		return "《九阴真经》是我几十年心血所驻，岂能轻给？";
	}
	sks = me->query("xkd/skill");
	if (arrayp(sks))
		skl = sks[random(sizeof(sks))];
	else	if (stringp(sks))
		skl = sks;
//	ob->set("skill/name", me->query("xkd/skill") );
	ob->set("skill/name", skl );
	ob->set("skill/exp_required", 1000000);
	ob->set("skill/jing_cost", 50);
	ob->set("skill/difficulty", 50);
	ob->set("skill/min_skill", 300);
	ob->set("skill/max_skill", 350);
	ob->move(me);
	command("rumor "+me->query("name")+"拿到九阴真经原本啦。\n");
	return "这本「九阴真经」你拿去好好钻研，当有进益。";
}
