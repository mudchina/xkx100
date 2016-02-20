// automan.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("笑三少", ({ "automan"}));
	set("gender", "男性");
	set("title", HIW"圣人"NOR"武当派第三代弟子「"HIC"天网恢恢 "HIR"疏而不漏"NOR"」");
	set("nickname", HIY"侠客行初中分舵舵主"NOR);
	set("long", "本潭初中分舵舵主。姑苏慕容门下第一大侠，斗转星移绝技
唯一传人，以“以彼之道，还施彼身”闻名天下。后来加入武当派，
成为一个不为人知的小道士。所发现的虫虫之多令人震惊。\n");
	set("age", 25);
	set("class", "swordman");
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 30);
	set("int", 30);
	set("dex", 20);
	set("con", 25);
	set("str", 21);
	set("weiwang", 90);
	set("shen", 270000);
	set("combat_exp", 4953266);
	set("PKS", 23);
	set("MKS", 16424);
	set("max_jing", 485);
	set("jing", 485);
	set("max_qi", 2553);
	set("qi", 2553);
	set("max_jingli", 180);
	set("jingli", 180);
	set("max_neili", 3050);
	set("neili", 3050);
	set("meili", 60);
	set("score", 36534);
	set("env/no_teach", "1");

	set_skill("claw", 250);
	set_skill("cuff", 250);
	set_skill("dodge", 301);
	set_skill("douzhuan-xingyi", 150);
	set_skill("finger", 250);
	set_skill("force", 319);
	set_skill("hand", 250);
	set_skill("jiuyin-baiguzhao", 230);
	set_skill("literate", 296);
	set_skill("murong-sword", 201);
	set_skill("parry", 250);
	set_skill("strike", 250);
	set_skill("sword", 330);
	set_skill("liangyi-jian", 345);
	set_skill("taiji-jian", 360);
	set_skill("taiji-quan", 200);
	set_skill("taiji-shengong", 299);
	set_skill("tiyunzong", 259);
	set_skill("taoism", 150);
	set_skill("unarmed", 250);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "liangyi-jian");
	map_skill("unarmed", "taiji-quan");
	map_skill("claw", "jiuyin-baiguzhao");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"skill" : (: do_skills :),
		"score" : (: do_score :),
		"武功"  : (: do_skills :),
	]));

	create_family("武当派", 3, "弟子");
	setup();
	carry_object(__DIR__"automan_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"≡──────────────────────────────≡\n"+
"  基本爪法 (claw)                          - 深不可测 250/    0\n"+
"  基本拳法 (cuff)                          - 深不可测 250/    0\n"+
"  基本轻功 (dodge)                         - 深不可测 301/56468\n"+
"  斗转星移 (douzhuan-xingyi)               - 了然于胸 150/    0\n"+
"  基本指法 (finger)                        - 深不可测 250/    0\n"+
"  基本内功 (force)                         - 深不可测 319/31356\n"+
"  基本手法 (hand)                          - 深不可测 250/    0\n"+
"□九阴白骨抓 (jiuyin-baiguzhao)            - 深不可测 230/   59\n"+
"□两仪剑法 (liangyi-jian)                  - 深不可测 345/55463\n"+
"  读书写字 (literate)                      - 深不可测 296/    0\n"+
"  慕容剑法 (murong-sword)                  - 深不可测 201/    3\n"+
"  基本招架 (parry)                         - 深不可测 250/    0\n"+
"  基本掌法 (strike)                        - 深不可测 250/    0\n"+
"  基本剑法 (sword)                         - 深不可测 330/    1\n"+
"□太极剑法 (taiji-jian)                    - 深不可测 360/ 1415\n"+
"□太极拳 (taiji-quan)                      - 深不可测 200/    2\n"+
"□太极神功 (taiji-shengong)                - 深不可测 299/   37\n"+
"  道学心法 (taoism)                        - 了然于胸 150/    0\n"+
"□梯云纵 (tiyunzong)                       - 深不可测 259/ 3287\n"+
"  基本拳脚 (unamred)                       - 深不可测 250/    0\n"+
"≡──────────────────────────────≡\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  485/  850 (100%)    【 精 力 】  180 /  180 (+0)\n"+
"【 气 血 】 2553/ 2553 (100%)    【 内 力 】 3050 / 3050 (+0)\n"+
"【 食 物 】    0/  300           【 潜 能 】  0\n"+
"【 饮 水 】    0/  300           【 经 验 】  4953266\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【 旷世大侠 】圣人武当派第三代弟子「天网恢恢 疏而不漏」笑三少(Automan)\n"+
" 你是一位二十八岁二个月的男性人类，甲寅年五月十九日辰时三刻生。\n"+
" 膂力：[21/46 ]  悟性：[30/ 59 ]   根骨：[25/ 56]  身法：[20/ 50]\n"+
" 你的师父是 宋远桥。             存款：四十六两黄金十两白银三十六文铜钱。\n"+
" 你还是个光棍。\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
"战斗攻击力   302190         战斗防御力   502991\n"+
"战斗伤害力   200            战斗保护力   2 \n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 16424 个人，其中有 23 个是其他玩家。\n"+
" 你到目前为止总共死了 7 次了，其中有 3 次是非正常死亡。\n"+
"\n"+
" 正    气：   270000     潜    能： 0  ( 100%)    实战经验：   4953266\n"+
" 魅    力：       60     江湖阅历：     36534     江湖威望：        90\n"+
"\n", this_object());
	return 1;
}
