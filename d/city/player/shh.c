// shh.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("沈浪", ({ "shh"}));
	set("gender", "男性");
	set("long","明教第一大侠，数十年潜心武学，淡泊名利。他喜欢
在黄昏时牵一匹白马，披一件大氅，独自伫立于昆仑
山巅的雪原里，凝望天边的落日。谁能了解他内心的
孤寂呢？也许武学的最高境界就是将刀光剑影敛藏于
心。人生的荣耀已随着岁月流逝，他的额头隐现皱纹，
面容清癯，眼里有一丝淡淡的忧伤。\n");
	set("title", HIW"圣人"HIG"明教天字门教众"NOR"明教第三十五代弟子"NOR);
	set("nickname", HIR"落日"HIY"一笑"NOR);
	set("age", 68);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 20);
	set("per", 20);
	set("int", 24);
	set("dex", 16);
	set("con", 22);
	set("str", 20);
	set("weiwang", 20);
	set("shen", 205010);
	set("combat_exp", 11313839);
	set("PKS", 1);
	set("MKS", 13844);

	set("max_jing", 616);
	set("jing", 616);
	set("max_qi", 1459);
	set("qi", 1459);
	set("max_jingli", 531);
	set("jingli", 531);
	set("max_neili", 4190);
	set("neili", 4190);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 300);
	set_skill("force", 300);
	set_skill("unarmed",260);
	set_skill("parry", 295);
	set_skill("dodge", 298);
	set_skill("sword", 260);
	set_skill("cuff", 260);
	set_skill("qishang-quan", 423);
	set_skill("qiankun-danuoyi", 260);
	set_skill("jiuyang-shengong", 282);
	set_skill("tianyu-qijian", 292);
	set_skill("shenxing-baibian", 435);
        set_skill("strike", 250);
        set_skill("hanbing-mianzhang", 283);
        set_skill("taoism", 120);
        set_skill("hand", 250);
        set_skill("hubo", 110);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "shenxing-baibian");
	map_skill("parry", "qiankun-danuoyi");
	map_skill("sword", "tianyu-qijian");
	map_skill("unarmed","qiankun-danuoyi");
	map_skill("cuff","qishang-quan");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("明教",35, "弟子");
	setup();
	carry_object(__DIR__"shh_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"  基本剑法 (sword)                         - 深不可测 260/    0\n"+
"□七伤拳 (qishang-quan)                    - 深不可测 423/    0\n"+
"  基本轻功 (dodge)                         - 深不可测 298/    0\n"+
"  基本内功 (force)                         - 深不可测 300/    0\n"+
"□天羽奇剑 (tianyu-qijian)                 - 深不可测 292/    0\n"+
"□九阳神功 (jiuyang-shengong)              - 深不可测 282/    0\n"+
"  读书写字 (literate)                      - 深不可测 300/    0\n"+
"  基本招架 (parry)                         - 深不可测 295/    0\n"+
"□神行百变 (shenxing-baibian)              - 深不可测 435/    0\n"+
"  基本拳法 (cuff)                          - 深不可测 260/    0\n"+
"  基本拳脚 (unarmed)                       - 深不可测 260/    0\n"+
"  基本掌法 (strike)                        - 深不可测 250/    0\n"+
"  寒冰绵掌 (hanbing-mianzhang)             - 深不可测 283/    0\n"+
"  基本手法 (hand)                          - 深不可测 250/    0\n"+
"  道学心法 (taoism)                        - 了然於胸 120/    0\n"+
"  左右互搏 (hubo)                          - 出类拔萃 110/    0\n"+
"□乾坤大挪移 (qiankun-danuoyi)             - 深不可测 260/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  616/  616 (100%)    【 精 力 】  531 /  531 (+0)\n"+
"【 气 血 】 1459/ 1459 (100%)    【 内 力 】 4190 / 4190 (+0)\n"+
"【 食 物 】    0/  300           【 潜 能 】  0\n"+
"【 饮 水 】    0/  300           【 经 验 】  11313839\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【旷世大侠】圣人明教天字门教众天下第二大侠明教第三十五代弟子「落日一笑」沈浪(Shh)\n"+
"\n"+
" 你是一位六十八岁十个月的男性人类，甲寅年一月一日辰时三刻生。\n"+
" 膂力：[ 46]  悟性：[ 54]  根骨：[ 52]  身法：[ 45]"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 战斗攻击力  2100000            战斗防御力   2300000\n"+
" 战斗伤害力       30            战斗保护力         1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 13844 个人，其中有 1 个是其他玩家。\n"+
"\n"+
" 正    气：   205010     潜    能：   0 (100%)   实战经验： 11313839\n"+
" 魅    力：       60     江湖阅历：   0          江湖威望：       20\n"+
"\n", this_object());
	return 1;
}
