// abab.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("包干到户", ({ "abab"}));
	set("gender", "无性");
	set("title", HIY"翰林硕士"HIG"明教雷字门教众"NOR"星宿派第二代弟子");
	set("nickname", HIY"逍遥王府王爷"NOR);
	set("long", "本潭早期玩家。诙谐幽默，颇得女玩家欢心。这是一位
二十岁左右的年青人，身材修长，眉目清秀，浑身散发
出一种迷人的魅力，他正在笑嘻嘻地看着你。\n");
	set("age", 36);
	set("class", "taoist");
	set("attitude", "friendly");

	set("kar", 25);
	set("per", 29);
	set("int", 20);
	set("dex", 19);
	set("con", 21);
	set("str", 20);
	set("weiwang", 70);
	set("shen", -184200);
	set("combat_exp", 591339);
	set("PKS", 12);
	set("MKS", 935);

	set("max_jing", 420);
	set("jing", 420);
	set("max_qi", 971);
	set("qi", 971);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 2140);
	set("neili", 2140);
	set("meili", 40);
	set("env/no_teach", "1");

	set_skill("literate", 121);
	set_skill("force", 147);
	set_skill("unarmed",100);
	set_skill("parry", 103);
	set_skill("dodge", 108);
	set_skill("sword", 144);
	set_skill("cuff", 101);
	set_skill("hand", 101);
	set_skill("claw", 82);
	set_skill("strike", 97);

	set_skill("bixie-jian", 175);
	set_skill("huagong-dafa", 148);
	set_skill("jiuyin-baiguzhao", 82);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "bixie-jian");
	map_skill("parry", "bixie-jian");
	map_skill("sword", "bixie-jian");
	map_skill("claw","jiuyin-baiguzhao");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"skill" : (: do_skills :),
		"score" : (: do_score :),
		"武功"  : (: do_skills :),
	]));

	create_family("星宿派",2, "弟子");
	setup();
	carry_object(__DIR__"abab_sword")->wield();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
        carry_object(CLOTH_DIR"dao-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"≡──────────────────────────────≡\n"+
"  基本爪法 (claw)                          - 驾轻就熟  82/    0\n"+
"  基本拳法 (cuff)                          - 出类拔萃 101/    0\n"+
"  基本轻功 (dodge)                         - 出类拔萃 108/    0\n"+
"  基本内功 (force)                         - 出神入化 147/    0\n"+
"  基本手法 (hand)                          - 出类拔萃 101/    0\n"+
"□化功大法 (huagong-dafa)                  - 出神入化 148/    0\n"+
"□九阴白骨抓 (jiuyin-baiguzhao)            - 驾轻就熟  82/    0\n"+
"  读书写字 (literate)                      - 了然於胸 121/    0\n"+
"  基本招架 (parry)                         - 出类拔萃 103/    0\n"+
"□辟邪剑法 (bixie-jian)                    - 登峰造极 175/    0\n"+
"  基本掌法 (strike)                        - 驾轻就熟  97/    0\n"+
"  基本剑法 (sword)                         - 出神入化 144/    0\n"+
"  基本拳脚 (unarmed)                       - 出类拔萃 100/    0\n"+
"≡──────────────────────────────≡\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  420/  420 (100%)    【 精 力 】    0 /    0 (+0)\n"+
"【 气 血 】  971/  971 (100%)    【 内 力 】 2140 / 2140 (+0)\n"+
"【 食 物 】    0/  300           【 潜 能 】  0\n"+
"【 饮 水 】    0/  300           【 经 验 】  591339\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【 魔  王 】翰林硕士明教雷字门教众星宿派第二代弟子「逍遥王府王爷」包干到户(Abab)\n"+
"\n"+
" 你是一位三十六岁的无性人类，甲寅年一月一日辰时三刻生。\n"+
" 膂力：[ 30]  悟性：[ 32]  根骨：[ 35]  身法：[ 29]\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 战斗攻击力    55941            战斗防御力    95685\n"+
" 战斗伤害力       30            战斗保护力      100\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 947 个人，其中有 12 个是其他玩家。\n"+
"\n"+
" 戾    气：  -184200     潜    能：   0 (100%)   实战经验：   591339\n"+
" 魅    力：       40     综合评价：        0     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
