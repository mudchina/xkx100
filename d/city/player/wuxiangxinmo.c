// wuxiangxinmo.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("无相心魔", ({ "wuxiangxinmo"}));
	set("gender", "男性");
        set("long","无相心魔是个胖娃娃，
巫师玩家都很喜欢他。
但是他有一点点可怕，
经常揣了臭虫手里抓。

鱼儿鱼儿水里游，
臭虫臭虫岸上爬；
无相别来可无恙?
我们想念你一家。
                 \n");
	set("age", 14);
	set("class", "swordman");
	set("attitude", "friendly");

	set("kar", 27);
	set("per", 18);
	set("int", 19);
	set("dex", 15);
	set("con", 21);
	set("str", 25);
//	set("weiwang", 30);
	set("shen", 0);
	set("combat_exp", 0);
//	set("PKS", 0);
//	set("MKS", 0);

	set("max_jing", 100);
	set("jing", 100);
	set("max_qi", 100);
	set("qi", 100);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 0);
	set("neili", 0);
//	set("meili", 0);
	set("env/no_teach", "1");

	set_skill("persuading", 1);
	set_skill("checking", 1);
	set_skill("unarmed", 1);
	set_skill("hand", 1);
	set_skill("sword", 1);
	set_skill("blade", 1);
	set_skill("force", 1);
	set_skill("literate", 1);
	set_skill("cuff", 1);
	set_skill("array", 1);
	set_skill("begging", 1);
	set_skill("parry", 1);
	set_skill("whip", 1);
	set_skill("throwing", 1);
	set_skill("claw", 1);
	set_skill("staff", 1);
	set_skill("taoism", 1);
	set_skill("strike", 1);
	set_skill("club", 1);
	set_skill("dodge", 1);
	set_skill("finger", 1);
	set_skill("hammer", 1);

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("日月神教",101, "弟子");
	setup();
	carry_object(__DIR__"wuxiang_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"  基本阵法 (array)                         - 新学乍用   1/    0\n"+
"  叫化绝活 (begging)                       - 初学乍练   1/    0\n"+
"  基本刀法 (blade)                         - 初学乍练   1/    0\n"+
"  道听途说 (checking)                      - 初学乍练   1/    0\n"+
"  基本爪法 (claw)                          - 初学乍练   1/    0\n"+
"  基本棍法 (club)                          - 初学乍练   1/    0\n"+
"  基本拳法 (cuff)                          - 初学乍练   1/    0\n"+
"  基本轻功 (dodge)                         - 初学乍练   1/    0\n"+
"  基本指法 (finger)                        - 初学乍练   1/    0\n"+
"  基本内功 (force)                         - 初学乍练   1/    0\n"+
"  基本锤法 (hammer)                        - 初学乍练   1/    0\n"+
"  基本手法 (hand)                          - 初学乍练   1/    0\n"+
"  读书写字 (literate)                      - 新学乍用   1/    0\n"+
"  基本招架 (parry)                         - 初学乍练   1/    0\n"+
"  渡世济人 (persuading)                    - 新学乍用   1/    0\n"+
"  基本杖法 (staff)                         - 初学乍练   1/    0\n"+
"  基本掌法 (strike)                        - 初学乍练   1/    0\n"+
"  基本剑法 (sword)                         - 初学乍练   1/    0\n"+
"  道学心法 (taoism)                        - 新学乍用   1/    0\n"+
"  基本暗器 (throwing)                      - 初学乍练   1/    0\n"+
"  基本拳脚 (unarmed)                       - 初学乍练   1/    0\n"+
"  基本鞭法 (whip)                          - 初学乍练   1/    0\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  100/  100 (100%)    【 精 力 】    0 /    0 (+0)\n"+
"【 气 血 】  100/  100 (100%)    【 内 力 】    0 /    0 (+0)\n"+
"【 食 物 】    0/  350           【 潜 能 】  0\n"+
"【 饮 水 】    0/  350           【 经 验 】  0\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【 小和尚 】日月神教第一百零一代弟子 无相心魔(Wuxiangxinmo)\n"+
"\n"+
" 你是一位十四岁的男性人类，甲寅年一月一日辰时三刻生。\n"+
" 膂力：[ 25]  悟性：[ 19]  根骨：[ 21]  身法：[ 15]\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 战斗攻击力        1            战斗防御力        1\n"+
" 战斗伤害力       30            战斗保护力        1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 0 个人，其中有 0 个是其他玩家。\n"+
"\n"+
" 正    气：        0     潜    能：   0 (100%)   实战经验：        0\n"+
" 魅    力：        0     综合评价：        0     江湖威望：        0\n"+
"\n", this_object());
	return 1;
}
