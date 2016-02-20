// qinqin.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("司马菁菁", ({ "qinqin"}));
	set("gender", "女性");
        set("long","本潭最早的玩家之一，对本潭贡献良多，其侠骨柔肠影响
了几代玩家。华山风清扬嫡传弟子，独孤九剑乃其成名绝
技。曾叱咤江湖数十年，武功之高强几近求败境界。武林
泰山北斗级人物，虽已归隐山林，依然享有崇高的威望。\n");
	set("title", HIY"翰林硕士"NOR"华山派第十三代弟子");
	set("age", 32);
	set("class", "swordsman");
	set("attitude", "friendly");

	set("kar", 24);
	set("per", 22);
	set("int", 33);
	set("dex", 20);
	set("con", 14);
	set("str", 18);
	set("weiwang", 70);
	set("shen", 248860);
	set("combat_exp", 2002380);
	set("PKS", 6);
	set("MKS", 1412);

	set("max_jing", 808);
	set("jing", 808);
	set("max_qi", 956);
	set("qi", 956);
	set("max_jingli", 720);
	set("jingli", 720);
	set("max_neili", 2530);
	set("neili", 2530);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 120);
	set_skill("taoism", 178);
	set_skill("force", 208);
	set_skill("unarmed",101);
	set_skill("parry", 180);
	set_skill("dodge", 185);
	set_skill("sword", 272);
	set_skill("cuff", 100);
	set_skill("hand", 100);
	set_skill("claw", 100);
	set_skill("strike", 100);
	set_skill("finger", 100);

	set_skill("shenxing-baibian", 272);
	set_skill("lonely-sword", 272);
	set_skill("poyu-quan", 186);
	set_skill("taiji-quan", 98);
	set_skill("zhemei-shou", 270);
	set_skill("taiji-jian", 97);
	set_skill("liangyi-jian", 178);
	set_skill("feiyan-huixiang", 177);
	set_skill("huashan-sword", 248);
	set_skill("tiyunzong", 272);
	set_skill("zixia-shengong", 150);
	set_skill("hunyuan-zhang", 174);
	set_skill("jiuyin-baiguzhao", 270);

	map_skill("force", "zixia-shengong");
	map_skill("dodge", "shenxing-baibian");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("unarmed","taiji-quan");
	map_skill("cuff","poyu-quan");
	map_skill("strike","hunyuan-zhang");
	map_skill("hand","zhemei-shou");
	map_skill("claw","jiuyin-baiguzhao");
	prepare_skill("cuff","poyu-quan");
	prepare_skill("strike","hunyuan-zhang");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("华山派",13, "弟子");
	setup();
	carry_object(__DIR__"qinqin_sword")->wield();
	carry_object(CLOTH_DIR"female-cloth")->wear();
        carry_object(CLOTH_DIR"female-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"  基本爪法 (claw)                          - 出类拔萃 100/    0\n"+
"  基本拳法 (cuff)                          - 出类拔萃 100/    0\n"+
"  基本轻功 (dodge)                         - 一代宗师 185/    0\n"+
"  飞燕回翔 (feiyan-huixiang)               - 登峰造极 177/    0\n"+
"  基本指法 (finger)                        - 出类拔萃 100/    0\n"+
"  基本内功 (force)                         - 深不可测 208/    0\n"+
"  基本手法 (hand)                          - 出类拔萃 100/    0\n"+
"  华山剑法 (huashan-sword)                 - 深不可测 248/    0\n"+
"□混元掌 (hunyuan-zhang)                   - 登峰造极 174/    0\n"+
"□九阴白骨抓 (jiuyin-baiguzhao)            - 深不可测 270/    0\n"+
"  两仪剑法 (liangyi-jian)                  - 登峰造极 178/    0\n"+
"  读书写字 (literate)                      - 了然於胸 120/    0\n"+
"□独孤九剑 (lonely-sword)                  - 深不可测 272/    0\n"+
"  基本招架 (parry)                         - 一代宗师 180/    0\n"+
"□劈石破玉拳 (poyu-quan)                   - 一代宗师 186/    0\n"+
"□神行百变 (shenxing-baibian)              - 深不可测 272/    0\n"+
"  基本掌法 (strike)                        - 出类拔萃 100/    0\n"+
"  基本剑法 (sword)                         - 深不可测 272/    0\n"+
"  太极剑法 (taiji-jian)                    - 驾轻就熟  97/    0\n"+
"□太极拳 (taiji-quan)                      - 驾轻就熟  98/    0\n"+
"  道学心法 (taoism)                        - 举世无双 178/    0\n"+
"  梯云纵 (tiyunzong)                       - 深不可测 272/    0\n"+
"  基本拳脚 (unarmed)                       - 出类拔萃 101/    0\n"+
"□天山折梅手 (zhemei-shou)                 - 深不可测 270/    0\n"+
"□紫霞神功 (zixia-shengong)                - 出神入化 150/    0\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  808/  808 (100%)    【 精 力 】  720 /  720 (+0)\n"+
"【 气 血 】  956/  956 (100%)    【 内 力 】 2530 / 2530 (+0)\n"+
"【 食 物 】    0/  280           【 潜 能 】  0\n"+
"【 饮 水 】    0/  280           【 经 验 】  2002380\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【旷世女侠】翰林硕士华山派第十三代弟子 司马菁菁(Qinqin)\n"+
"\n"+
" 你是一位三十二岁的女性人类，甲寅年一月一日辰时三刻生。\n"+
" 膂力：[ 28]  悟性：[ 45]  根骨：[ 34]  身法：[ 38]\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 战斗攻击力   229987            战斗防御力   531755\n"+
" 战斗伤害力       30            战斗保护力        1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 1418 个人，其中有 6 个是其他玩家。\n"+
"\n"+
" 正    气：   248860     潜    能：   0 (100%)   实战经验：  2002380\n"+
" 魅    力：       60     综合评价：        0     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
