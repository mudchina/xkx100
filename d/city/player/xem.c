// xem.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("静梅", ({ "xem"}));
	set("gender", "女性");
        set("long","本潭第一大侠。武林至尊。武功之精湛当世无人能及。
为人谦和冲淡，练功精益求精。峨嵋派由此得以发扬光
大。在江湖最险恶的时日里，挺身而出，那唇边的轻笑
如一缕春风，带走人们心中肃杀的寒意。她，是一个神
话，至今仍在街巷酒肆中被人们传诵。\n");
	set("title", HIW"圣人"HIG"明教地字门教众"NOR"峨嵋派第四代弟子");
	set("age", 40);
	set("class", "bonze");
	set("attitude", "friendly");

	set("kar", 28);
	set("per", 27);
	set("int", 30);
	set("dex", 16);
	set("con", 15);
	set("str", 19);
	set("weiwang", 70);
	set("shen", 0);
	set("combat_exp", 49927955);
	set("PKS", 6);
	set("MKS", 1587);

	set("max_jing", 804);
	set("jing", 804);
	set("max_qi", 2732);
	set("qi", 2732);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 8610);
	set("neili", 8610);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("blade", 561);
	set_skill("buddhism", 200);
	set_skill("claw", 254);
	set_skill("cuff", 254);
	set_skill("dagou-bang", 784);
	set_skill("dodge", 561);
	set_skill("feixing-shu", 787);
	set_skill("finger", 561);
	set_skill("force", 561);
	set_skill("hanbing-mianzhang", 792);
	set_skill("huifeng-jian", 794);
	set_skill("jinding-zhang", 794);
	set_skill("jiuyin-baiguzhao", 702);
	set_skill("kongming-quan", 792);
	set_skill("linji-zhuang", 586);
	set_skill("literate", 300);
	set_skill("mahayana", 204);
	set_skill("parry", 561);
	set_skill("qishang-quan", 792);
	set_skill("qiufeng-chenfa", 776);
	set_skill("shenxing-baibian", 300);
	set_skill("staff", 250);
	set_skill("strike", 257);
	set_skill("sword", 561);
	set_skill("throwing", 250);
	set_skill("tiangang-zhi", 787);
	set_skill("unarmed", 560);
	set_skill("whip", 250);
	set_skill("yanxing-dao", 794);
	set_skill("zhutian-bu", 781);

	map_skill("unarmed", "kongming-quan");
	map_skill("sword", "huifeng-jian");
	map_skill("blade", "yanxing-dao");
	map_skill("force", "linji-zhuang");
	map_skill("cuff", "qishang-quan");
	map_skill("parry", "jingding-zhang");
	map_skill("whip", "qiufeng-chenfa");
	map_skill("throwing", "feixing-shu");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("staff","dagou-bang");
	map_skill("strike", "jinding-zhang");
	map_skill("finger", "tiangang-zhi");
	map_skill("dodge", "zhutian-bu");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("峨嵋派",4, "弟子");
	setup();
	carry_object(__DIR__"xem_sword")->wield();
	carry_object(CLOTH_DIR"ni-cloth")->wear();
        carry_object(CLOTH_DIR"ni-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"≡──────────────────────────────≡\n"+
"  基本刀法 (blade)                         - 深不可测 561/    0\n"+
"  禅宗心法 (buddhism)                      - 深不可测 200/    0\n"+
"  基本爪法 (claw)                          - 深不可测 254/    0\n"+
"  基本拳法 (cuff)                          - 深不可测 254/    0\n"+
"□打狗棒法 (dagou-bang)                    - 深不可测 784/    0\n"+
"  基本轻功 (dodge)                         - 深不可测 561/    0\n"+
"□飞星术 (feixing-shu)                     - 深不可测 787/    0\n"+
"  基本指法 (finger)                        - 深不可测 561/    0\n"+
"  基本内功 (force)                         - 深不可测 561/    0\n"+
"  寒冰绵掌 (hanbing-mianzhang)             - 深不可测 792/    0\n"+
"□回风拂柳剑 (huifeng-jian)                - 深不可测 794/    0\n"+
"□金顶绵掌 (jinding-zhang)                 - 深不可测 794/    0\n"+
"□九阴白骨抓 (jiuyin-baiguzhao)            - 深不可测 702/    0\n"+
"□空明拳 (kongming-quan)                   - 深不可测 792/    0\n"+
"□临济十二庄 (linji-zhuang)                - 深不可测 586/    0\n"+
"  读书写字 (literate)                      - 深不可测 300/    0\n"+
"  大乘涅磐功 (mahayana)                    - 深不可测 204/    0\n"+
"  基本招架 (parry)                         - 深不可测 561/    0\n"+
"□七伤拳 (qishang-quan)                    - 深不可测 792/    0\n"+
"□秋风拂尘 (qiufeng-chenfa)                - 深不可测 776/    0\n"+
"  神行百变 (shenxing-baibian)              - 深不可测 300/    0\n"+
"  基本杖法 (staff)                         - 深不可测 250/    0\n"+
"  基本掌法 (strike)                        - 深不可测 257/    0\n"+
"  基本剑法 (sword)                         - 深不可测 561/    0\n"+
"  基本暗器 (throwing)                      - 深不可测 250/    0\n"+
"□天罡指穴法 (tiangang-zhi)                - 深不可测 787/    0\n"+
"  基本拳脚 (unarmed)                       - 深不可测 560/    0\n"+
"  基本鞭法 (whip)                          - 深不可测 250/    0\n"+
"□雁行刀 (yanxing-dao)                     - 深不可测 794/    0\n"+
"□诸天化身步 (zhutian-bu)                  - 深不可测 781/    0\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  804/  804 (100%)    【 精 力 】    0 /    0 (+0)\n"+
"【 气 血 】 2732/ 2732 (100%)    【 内 力 】 8610 / 8610 (+0)\n"+
"【 食 物 】    0/  290           【 潜 能 】  0\n"+
"【 饮 水 】    0/  290           【 经 验 】  49927955\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【 神  尼 】翰林硕士明教地字门教众峨嵋派第四代弟子 静梅(Xem)\n"+
"\n"+
" 你是一位四十岁的女性人类，甲寅年一月一日辰时三刻生。\n"+
" 膂力：[ 55]  悟性：[ 60]  根骨：[ 61]  身法：[ 52]\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 战斗攻击力 11571809            战斗防御力 -21221796\n"+
" 战斗伤害力       30            战斗保护力         1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 1593 个人，其中有 6 个是其他玩家。\n"+
"\n"+
" 你到目前为止总共死了 0 次了，其中有 0 次是非正常死亡。\n"+
"\n"+
" 正    气：        0     潜    能：   0 (100%)   实战经验： 49927955\n"+
" 魅    力：       60     江湖阅历：        0     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}

