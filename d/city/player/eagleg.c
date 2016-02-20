// eagleg.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("孤鹰", ({ "eagleg"}));
	set("gender", "男性");
	set("long","本潭最早的玩家之一。桃花岛第一大侠。他石雕似的方脸配着
鹰隼般锐利的双眼，不时闪射出寒冰似的杀机；浑身上下每寸
肌肉都显示出无穷的力量，象尊掌管生死的地狱之魔。\n");
	set("title", HIW"圣人"NOR"桃花岛第二代弟子");
	set("nickname", HIB"黑羽掠空"HIW"了无痕"NOR);
	set("age", 47);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 29);
	set("per", 26);
	set("int", 28);
	set("dex", 32);
	set("con", 36);
	set("str", 26);
	set("weiwang", 70);
	set("shen", 6217202);
	set("combat_exp", 5455577);
	set("PKS", 4);
	set("MKS", 6628);

	set("max_jing", 548);
	set("jing", 548);
	set("max_qi", 1501);
	set("qi", 1501);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3300);
	set("neili", 3300);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 206);
	set_skill("array", 250);
	set_skill("count", 250);
	set_skill("force", 253);
	set_skill("unarmed",250);
	set_skill("parry", 278);
	set_skill("dodge", 268);
	set_skill("sword", 250);
	set_skill("lanhua-shou", 375);
	set_skill("hand", 250);
	set_skill("hanbing-mianzhang", 372);
	set_skill("luoying-shenjian", 375);
	set_skill("qimen-wuxing", 102);
	set_skill("shenxing-baibian", 375);
	set_skill("tanzhi-shentong", 370);
	set_skill("yuxiao-jian", 376);
	set_skill("bibo-shengong", 204);
	set_skill("strike", 250);
	set_skill("luoying-zhang", 259);
        set_skill("xuanfeng-leg", 273);
        set_skill("finger", 250);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "shenxing-baibian");
	map_skill("parry", "yuxiao-jian");
	map_skill("finger", "tanzhi-shentong");
	map_skill("hand", "lanhua-shou");
	map_skill("sword", "yuxiao-jian");
	map_skill("unarmed","xuanfeng-leg");
	map_skill("strike","luoying-zhang");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("桃花岛",2, "弟子");
	setup();
	carry_object(__DIR__"eagleg_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"  基本阵法 (array)                         - 深不可测 250/    0\n"+
"□碧波神功 (bibo-shengong)                 - 深不可测 204/    0\n"+
"  基本轻功 (dodge)                         - 深不可测 268/    0\n"+
"  基本内功 (force)                         - 深不可测 253/    0\n"+
"  阴阳八卦 (count)                         - 深不可测 250/    0\n"+
"  基本指法 (finger)                        - 深不可测 250/    0\n"+
"  寒冰绵掌 (hanbing-mianzhang)             - 深不可测 372/    0\n"+
"  基本手法 (hand)                          - 深不可测 250/    0\n"+
"  读书写字 (literate)                      - 了然於胸 206/    0\n"+
"  基本招架 (parry)                         - 深不可测 278/    0\n"+
"□兰花拂穴手 (lanhua-shou)                 - 深不可测 375/    0\n"+
"  神行百变 (shenxing-baibian)              - 粗通皮毛 375/    0\n"+
"  落英神剑 (luoying-shenjian)              - 深不可测 375/    0\n"+
"  基本剑法 (sword)                         - 深不可测 250/    0\n"+
"  落英神剑掌 (luoying-zhang)               - 深不可测 259/    0\n"+
"  基本拳脚 (unarmed)                       - 出神入化 250/    0\n"+
"  奇门五行 (qimen-wuxing)                  - 心领神会 102/    0\n"+
"  基本掌法 (strike)                        - 深不可测 250/    0\n"+
"□旋风扫叶腿 (xuanfeng-leg)                - 深不可测 273/    0\n"+
"□玉箫剑法 (yuxiao-jian)                   - 深不可测 376/    0\n"+
"□弹指神通 (tanzhi-shentong)               - 深不可测 370/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  548/  548 (100%)    【 精 力 】    0 /    0 (+0)\n"+
"【 气 血 】 1501/ 1501 (100%)    【 内 力 】 3300 / 3300 (+0)\n"+
"【 食 物 】    0/  360           【 潜 能 】  0\n"+
"【 饮 水 】    0/  360           【 经 验 】  5455577\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【旷世大侠】圣人 桃花岛第二代弟子 孤鹰(Eagleg)\n"+
"\n"+
" 你是一位四十七岁五个月的男性人类，戊子年七月十日巳时四刻生。\n"+
" 膂力：[ 51]  悟性：[ 48]  根骨：[ 61]  身法：[ 58]\n"+
"\n"+
" 你的师父是 黄药师。             你没有存款。\n"+
" 你的伴侣是 走走。\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 战斗攻击力   448204            战斗防御力  1045272\n"+
" 战斗伤害力       30            战斗保护力        1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 6628 个人，其中有 4 个是其他玩家。\n"+
"\n"+
" 正    气：  6217202     潜    能：   0 (100%)   实战经验：  5455577\n"+
" 魅    力：       60     江湖阅历：      172     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
