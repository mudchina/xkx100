// fall.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("朱七七", ({ "fall"}));
	set("gender", "女性");
	set("long","本潭泥巴文学代表作《恐龙手记》的作者。该作品曾
被许多著名站点转载，并连载于《电脑游戏》等刊物。
在短暂的泥潭生涯里，她经历了死的寂灭与生的喜悦，
也体验了练功的艰辛和爱情的甜美，至今她的身影仍
如一朵紫云开放在昆仑的皑皑白雪中。\n");
	set("title", HIY"翰林硕士"HIG"明教天字门教众"NOR"明教第三十五代弟子"NOR);
	set("nickname", HIM"天边紫云飞"NOR);
	set("age", 28);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 20);
	set("per", 30);
	set("int", 30);
	set("dex", 16);
	set("con", 17);
	set("str", 17);
	set("weiwang", 70);
	set("shen", 250000);
	set("combat_exp", 2717986);
	set("PKS", 0);
	set("MKS", 1011);

	set("max_jing", 540);
	set("jing", 540);
	set("max_qi", 1250);
	set("qi", 1250);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3300);
	set("neili", 3300);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 121);
	set_skill("force", 250);
	set_skill("unarmed",250);
	set_skill("parry", 250);
	set_skill("dodge", 250);
	set_skill("sword", 250);
	set_skill("cuff", 250);
	set_skill("qishang-quan", 200);
	set_skill("qiankun-danuoyi", 210);
	set_skill("jiuyang-shengong", 210);
	set_skill("shenghuo-ling", 200);
	set_skill("shenxing-baibian", 250);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "shenxing-baibian");
	map_skill("parry", "qiankun-danuoyi");
	map_skill("sword", "shenghuo-ling");
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
	carry_object(__DIR__"fall_sword")->wield();
	carry_object(CLOTH_DIR"female-cloth")->wear();
        carry_object(CLOTH_DIR"female-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"  基本剑法 (sword)                         - 深不可测 250/    0\n"+
"□七伤拳 (qishang-quan)                    - 深不可测 200/    0\n"+
"  基本轻功 (dodge)                         - 深不可测 250/    0\n"+
"  基本内功 (force)                         - 深不可测 250/    0\n"+
"□圣火令 (shenghuo-ling)                   - 深不可测 200/    0\n"+
"□九阳神功 (jiuyang-shengong)              - 深不可测 210/    0\n"+
"  读书写字 (literate)                      - 了然於胸 121/    0\n"+
"  基本招架 (parry)                         - 深不可测 250/    0\n"+
"□神行百变 (shenxing-baibian)              - 深不可测 250/    0\n"+
"  基本拳法 (cuff)                          - 深不可测 250/    0\n"+
"  基本拳脚 (unarmed)                       - 深不可测 250/    0\n"+
"□乾坤大挪移 (qiankun-danuoyi)             - 深不可测 210/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  540/  540 (100%)    【 精 力 】    0 /    0 (+0)\n"+
"【 气 血 】 1250/ 1250 (100%)    【 内 力 】 3300 / 3300 (+0)\n"+
"【 食 物 】    0/  270           【 潜 能 】  0\n"+
"【 饮 水 】    0/  270           【 经 验 】  2717986\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【旷世女侠】翰林硕士明教天字门教众明教第三十五代弟子\朱七七(fall)n"+
"\n"+
" 你的师父是 张无忌。\n"+
" 你的伴侣是 白云飞。\n"+
"\n"+
" 你是一位二十八岁的女性人类，甲寅年一月一日辰时三刻生。\n"+
" 膂力：[ 42]  悟性：[ 42]  根骨：[ 42]  身法：[ 41]\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 战斗攻击力   400000            战斗防御力   500000\n"+
" 战斗伤害力       30            战斗保护力         1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 1011 个人，其中有 0 个是其他玩家。\n"+
"\n"+
" 正    气：   250000     潜    能：   0 (100%)   实战经验：  2717986\n"+
" 魅    力：       60     江湖阅历：    12517     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
