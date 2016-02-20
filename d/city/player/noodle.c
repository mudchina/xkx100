//noodle.c
# include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
int do_saite();
void create()
{
	set_name("萧邪", ({ "noodle"}));
	set("gender", "男性");
	set("long","   生性愚钝。无忧无虑过了少年，混混噩噩度了青年。
   人到中年，却对培养新手起了极大兴趣。主id沦为大米,培养新角色无数。
所练之新角色曾经在一次比武中，勇夺300万与500万两个桂冠，成为双料冠军。
在此期间，偶遇挚友赛特，从此两人联手，笑傲江湖（哈哈，现在还在我身边呢）。
   渐入晚年，与周伯通习得不老之术后，整日与郭靖为伍，为国为民，
武功也突飞猛进，擂台上鲜有敌手。某日在擂台上碰一知己，结为连理。
唯憾老婆生性懒惰，使我身负相妻教子之重任。
   终其一生，发现bug无数，最擅长从日常之小事物中发现大bug。\n");
	set("title", HIW"圣人"NOR"吸星小教教主"NOR"逍遥派掌门大师兄"NOR);
	set("nickname", HIW"我喜欢bug"NOR);
	set("age", 46);
	set("class", "swordman");
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 30);
	set("int", 33);
	set("dex", 69);
	set("con", 41);
	set("str", 70);
	set("weiwang", 70);
	set("shen", 3);
	set("combat_exp", 16055317);
	set("PKS", 6);
	set("MKS", 30171);
	set("env/no_teach", "1");

	set("max_jing", 765);
	set("jing", 765);
	set("max_qi", 2436);
	set("qi", 2436);
	set("max_jingli", 740);
	set("jingli", 740);
	set("max_neili", 8130);
	set("neili", 8130);
	set("meili", 60);

	set_skill("literate", 542);
	set_skill("taoism", 200);
	set_skill("force", 542);
	set_skill("unarmed",542);
	set_skill("parry", 542);
	set_skill("dodge", 542);
	set_skill("staff", 542);
	set_skill("cuff", 542);
	set_skill("hand", 542);
	set_skill("claw", 542);
	set_skill("strike", 542);

	set_skill("hamagong", 542);
	set_skill("hamaquan", 542);
	set_skill("jiuyin-baiguzhao", 542);
	set_skill("kongming-quan", 542);
	set_skill("lingboweibu", 542);
	set_skill("lingshe-zhangfa", 542);
	set_skill("shexing-diaoshou", 542);

	map_skill("force", "hamagong");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");
	map_skill("unarmed","kongming-quan");
	map_skill("cuff","hamaquan");
	map_skill("strike","hamagong");
	map_skill("hand","shexing-diaoshou");
	map_skill("claw","jiuyin-baiguzhao");
	prepare_skill("claw","jiuyin-baiguzhao");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
		"赛特"  : (: do_saite :),
	]));

	create_family("逍遥派",2, "弟子");
		
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  765/  765 (100％)   【 精 力 】  740 /  740 (+0)\n"+
"【 气 血 】 2436/ 2436 (100％)   【 内 力 】 8130 / 8130 (+0)\n"+
"【 正 气 】       3              【 体 力 】  340 /  340\n"+
"【 食 物 】  262/  260           【 潜 能 】  4409\n"+
"【 饮 水 】  260/  260           【 经 验 】  16055317\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【 老秀才 】圣人吸星小教教主逍遥派掌门大师兄「我喜欢bug」萧邪(Noodle)\n"+
"\n"+
"  你是一位四十六岁十二个月性格普通的男性人类，甲寅年一月一日辰时三刻生。\n"+
"  膂力[16/ 70]  悟性[30/ 84]  根骨[19/ 73]  身法[15/ 69]  耐力[15/ 69]\n"+
"  灵性[10/ 30]  福缘[16/ 16]  胆识[15/ 15]  定力[21/ 21]  容貌[38/ 41]\n"+
"\n"+
" 你的师父是 苏星河。 你的伴侣是 蓝点。\n"+
" 存款：五万一千六百零五两黄金五十三两白银十五文铜钱。\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 食物：■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" 饮水：■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 到目前为止你总共杀了 30171 个人，其中有 6 个是其他玩家。\n"+
" 到目前为止你总共杀了 1 个同门，其中有 1 个是你的师长。\n"+
" 到目前为止你总共杀了 0 个帮中弟兄，其中有 0 个是你的上司。\n"+
" 到目前为止你总共杀了 7882 个无辜百姓，其中有 204 个是儿童。\n"+
" 到目前为止你总共死了 130 次了，其中有 11 次是非正常死亡。\n"+
" 到目前为止你总共叛师了 0 次了，被开除了 0 次。\n"+
"\n"+
" 正    气：        3     潜    能： 4409 ( 99%)  实战经验： 16055317\n"+
" 魅    力：       60     江湖阅历：     8432     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
int do_skills()
{
command("secret noodle");
return 1;	
}
int do_saite()
{
message_vision("$N说：他呀，是我的铁哥们，我们一起挖泥大半生了。喏，就在我身边呢
。\n",this_object());
	return 1;
}