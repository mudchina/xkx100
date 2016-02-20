// laughing.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("笑笑生", ({ "laughing"}));
	set("gender", "男性");
	set("long","这是一位江湖著名游侠，早些年曾在丐帮呆过，降龙掌
的雷霆一击无人能敌，但后来却淡出江湖，如闲云野鹤
般浪迹天涯。人们忘记了他的威仪和强悍，却时常能在
街市里见到他懒散儒雅的微笑。\n"); 
	set("title", HIW"圣人"NOR"普通百姓"NOR);
	set("nickname", HIB"独立小桥"HIG"风满袖"NOR);
	set("age", 45);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 10);
	set("per", 27);
	set("int", 30);
	set("dex", 16);
	set("con", 14);
	set("str", 20);
	set("weiwang", 70);
	set("shen", 0);
	set("combat_exp", 6238756);
	set("PKS", 0);
	set("MKS", 3107);

	set("max_jing", 700);
	set("jing", 700);
	set("max_qi", 1500);
	set("qi", 1500);
	set("max_jingli", 500);
	set("jingli", 500);
	set("max_neili", 3900);
	set("neili", 3900);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 210);
	set_skill("taoism", 100);
	set_skill("force", 260);
	set_skill("unarmed",265);
	set_skill("parry", 260);
	set_skill("dodge", 260);
	set_skill("blade", 250);
	set_skill("staff", 250);
	set_skill("xianglong-zhang", 380);
	set_skill("lingboweibu", 380);
	set_skill("huntian-qigong", 260);
	set_skill("kuangfeng-blade", 380);
	set_skill("dagou-bang", 380);

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "xianglong-zhang");
	map_skill("blade", "kuangfeng-blade");
	map_skill("unarmed","xianglong-zhang");
	map_skill("staff","dagou-bang");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("丐帮",18, "弟子");
	setup();
	carry_object(__DIR__"laughing_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"  基本刀法 (blade)                         - 深不可测 250/    0\n"+
"□打狗棒法 (dagou-bang)                    - 深不可测 380/    0\n"+
"  基本轻功 (dodge)                         - 深不可测 260/    0\n"+
"  基本内功 (force)                         - 深不可测 260/    0\n"+
"□狂风刀   (kuangfeng-blade)               - 深不可测 380/    0\n"+
"□混天气功 (huntian-qigong)                - 深不可测 260/    0\n"+
"  读书写字 (literate)                      - 深不可测 210/    0\n"+
"  基本招架 (parry)                         - 深不可测 260/    0\n"+
"□凌波微步 (lingboweibu)                   - 深不可测 380/    0\n"+
"  基本杖法 (staff)                         - 深不可测 250/    0\n"+
"  道学心法 (taoism)                        - 心领神会 100/    0\n"+
"  基本拳脚 (unarmed)                       - 深不可测 265/    0\n"+
"□降龙十八掌 (xianglong-zhang)             - 深不可测 380/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  700/  700 (100%)    【 精 力 】  500 /  500 (+0)\n"+
"【 气 血 】 1500/ 1500 (100%)    【 内 力 】 3900 / 3900 (+0)\n"+
"【 食 物 】    0/  300           【 潜 能 】  0\n"+
"【 饮 水 】    0/  300           【 经 验 】  6238756\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【旷世大侠】圣人普通百姓「独立小桥风满袖」笑笑生(Laughing)\n"+
"\n"+
" 你是一位四十五岁的男性人类，甲寅年一月一日辰时三刻生。\n"+
" 膂力：[ 46]  悟性：[ 51]  根骨：[ 40]  身法：[ 42]\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 战斗攻击力   800000            战斗防御力   1000000\n"+
" 战斗伤害力       30            战斗保护力         1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 3107 个人，其中有 0 个是其他玩家。\n"+
"\n"+
" 正    气：        0     潜    能：   0 (100%)   实战经验：  6238756\n"+
" 魅    力：       60     综合评价：        0     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
