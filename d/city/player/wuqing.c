// wuqing.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("无情", ({ "wuqing"}));
	set("gender", "无性");
        set("long","本潭最早的玩家之一。性情豪爽，不拘小节，为朋友
两肋插刀，热心扶助武林新人。曾和少林高僧渡天携
手纵横江湖十余载，与各派高手均有不薄情谊。\n");
	set("title", HIY"翰林硕士"HIG"明教天字门教众"HIR"明教护法"NOR);
	set("age", 48);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 10);
	set("per", 25);
	set("int", 26);
	set("dex", 18);
	set("con", 25);
	set("str", 16);
	set("weiwang", 30);
	set("shen", 64400);
	set("combat_exp", 1233655);
	set("PKS", 36);
	set("MKS", 1151);

	set("max_jing", 582);
	set("jing", 582);
	set("max_qi", 1221);
	set("qi", 1221);
	set("max_jingli", 267);
	set("jingli", 267);
	set("max_neili", 2046);
	set("neili", 2046);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 121);
	set_skill("taoism", 102);
	set_skill("claw", 187);
	set_skill("force", 210);
	set_skill("unarmed",95);
	set_skill("parry", 232);
	set_skill("dodge", 201);
	set_skill("sword", 232);
	set_skill("hand", 187);
	set_skill("cuff", 182);
	set_skill("strike", 182);
	set_skill("finger", 177);
	set_skill("begging", 24);
	set_skill("checking", 26);
	set_skill("qimen-wuxing", 24);

	set_skill("tiyunzong", 195);
	set_skill("liangyi-jian", 181);
	set_skill("taiji-shengong", 106);
	set_skill("taiji-quan", 98);
	set_skill("bixie-jian", 202);
	set_skill("shenghuo-ling", 148);
	set_skill("qishang-quan", 43);
	set_skill("jiuyin-baiguzhao", 220);
	set_skill("dagou-bang", 62);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "bixie-jian");
	map_skill("parry", "bixie-jian");
	map_skill("sword", "bixie-jian");
	map_skill("unarmed","taiji-quan");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("staff","dagou-bang");
	map_skill("cuff","qishang-quan");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("明教",35, "弟子");
	setup();
	carry_object(__DIR__"wuqing_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"  叫化绝活 (begging)                       - 粗通皮毛  24/    0\n"+
"  道听途说 (checking)                      - 粗通皮毛  26/    0\n"+
"  基本爪法 (claw)                          - 一代宗师 187/    0\n"+
"  基本拳法 (cuff)                          - 一代宗师 182/    0\n"+
"□打狗棒法 (dagou-bang)                    - 马马虎虎  62/    0\n"+
"  基本轻功 (dodge)                         - 深不可测 201/    0\n"+
"  基本指法 (finger)                        - 登峰造极 177/    0\n"+
"  基本内功 (force)                         - 深不可测 210/    0\n"+
"  基本手法 (hand)                          - 一代宗师 187/    0\n"+
"□九阴白骨抓 (jiuyin-baiguzhao)            - 深不可测 220/    0\n"+
"  两仪剑法 (liangyi-jian)                  - 一代宗师 181/    0\n"+
"  读书写字 (literate)                      - 了然於胸 121/    0\n"+
"  基本招架 (parry)                         - 深不可测 232/    0\n"+
"□辟邪剑法 (bixie-jian)                    - 深不可测 202/    0\n"+
"  奇门五行 (qimen-wuxing)                  - 初窥门径  24/    0\n"+
"□七伤拳 (qishang-quan)                    - 半生不熟  43/    0\n"+
"  圣火令法 (shenghuo-ling)                 - 出神入化 148/    0\n"+
"  基本掌法 (strike)                        - 一代宗师 182/    0\n"+
"  基本剑法 (sword)                         - 深不可测 232/    0\n"+
"□太极拳 (taiji-quan)                      - 驾轻就熟  98/    0\n"+
"□太极神功 (taiji-shengong)                - 出类拔萃 106/    0\n"+
"  道学心法 (taoism)                        - 心领神会 102/    0\n"+
"  梯云纵 (tiyunzong)                       - 一代宗师 195/    0\n"+
"  基本拳脚 (unarmed)                       - 驾轻就熟  95/    0\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  582/  582 (100%)    【 精 力 】  267 /  267 (+0)\n"+
"【 气 血 】 1221/ 1221 (100%)    【 内 力 】 2046 / 2046 (+0)\n"+
"【 食 物 】    0/  260           【 潜 能 】  0\n"+
"【 饮 水 】    0/  260           【 经 验 】  1233655\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【旷世大侠】翰林硕士明教天字门教众明教护法 无情(Wuqing)\n"+
"\n"+
" 你是一位四十八岁的无性人类，甲寅年一月一日辰时三刻生。\n"+
" 膂力：[ 34]  悟性：[ 38]  根骨：[ 46]  身法：[ 38]\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 战斗攻击力   135465            战斗防御力   277643\n"+
" 战斗伤害力       30            战斗保护力        1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 1151 个人，其中有 36 个是其他玩家。\n"+
"\n"+
" 正    气：    64400     潜    能：   0 (100%)   实战经验：  1233655\n"+
" 魅    力：       60     综合评价：        0     江湖威望：       30\n"+
"\n", this_object());
	return 1;
}
