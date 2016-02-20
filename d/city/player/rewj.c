// rewj.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("阿卡", ({ "rewj"}));
	set("gender", "男性");
        set("long",
"本潭知名的一位老玩家。早期师出峨嵋，凭借一身绝技
 横行武林，成名后修道于昆仑之颠。快意江湖为人豪爽，
 诙谐幽默，插科打诨，活跃气氛，广交朋友，是一个人
 缘极好的老混混。\n");
        set("title", "昆仑派第二代弟子");
        set("nickname", HIR"一生一火花"NOR);
	set("age", 27);
	set("class", "taoist");
	set("attitude", "friendly");
	
	set("kar", 20);
	set("per", 29);
	set("int", 31);
	set("dex", 14);
	set("con", 21);
	set("str", 16);
	set("weiwang", 30);
	set("shen", 47384);
	set("combat_exp", 1016246);
	set("PKS", 2);
	set("MKS", 73);
	
	set("max_jing", 596);
	set("jing", 596);
	set("max_qi", 1210);
	set("qi", 1210);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3096);
	set("neili", 3096);
	set("meili", 60);
	set("env/no_teach", "1");
	
	set_skill("literate", 180);
	set_skill("force", 212);
	set_skill("unarmed",200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("sword", 216);
	set_skill("cuff", 100);
	set_skill("leg", 101);
	set_skill("goplaying", 159);
	set_skill("luteplaying",159);
	set_skill("gambling",4);
	set_skill("strike", 100);

	set_skill("chuanyun-leg", 200);
	set_skill("kunlun-strike", 200);
	set_skill("liangyi-sword", 216);
	set_skill("taxue-wuhen",210);
	set_skill("xuantian-wuji",209);
	set_skill("zhentian-cuff",201);
	set_skill("xunlei-sword",216);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("parry", "liangyi-sword");
	map_skill("sword", "liangyi-sword");
	map_skill("leg","chuanyun-leg");
	map_skill("strike","kunlun-strike");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"skill" : (: do_skills :),
		"score" : (: do_score :),
		"武功"  : (: do_skills :),
	]));
	create_family("昆仑派",2, "弟子");
	setup();
        carry_object(__DIR__"rewj_sword")->wield();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
        carry_object(CLOTH_DIR"dao-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"≡──────────────────────────────≡\n"+
"□穿云腿 (chuanyun-leg)                    - 心领神会 200/    0\n"+
"  基本拳法 (cuff)                          - 平淡无奇 100/    0\n"+
"  基本轻功 (dodge)                         - 心领神会 200/    0\n"+
"  基本内功 (force)                         - 炉火纯青 212/    0\n"+
"  纹枰手谈 (goplaying)                     - 已有小成 159/    0\n"+
"□昆仑掌 (kunlun-strike)                   - 心领神会 200/    0\n"+
"  基本腿法 (leg)                           - 平淡无奇 100/    0\n"+
"□正两仪剑法 (liangyi-sword)               - 炉火纯青 216/    0\n"+
"□踏雪无痕 (taxue-wuhen)                   - 炉火纯青 210/    0\n"+
"  读书写字 (literate)                      - 融会贯通 180/    0\n"+
"  绕梁琴艺 (luteplaying)                   - 已有小成 159/    0\n"+
"  基本招架 (parry)                         - 心领神会 200/    0\n"+
"  基本掌法 (strike)                        - 平淡无奇 100/    0\n"+
"  基本剑法 (sword)                         - 炉火纯青 216/    0\n"+
"  基本拳脚 (unarmed)                       - 心领神会 200/    0\n"+
"□玄天无极功 (xuantian-wuji)               - 心领神会 209/    0\n"+
"  迅雷十六剑 (xunlei-sword)                - 炉火纯青 216/    0\n"+
"□震天拳法 (zhentian-cuff)                 - 心领神会 201/    0\n"+
"≡──────────────────────────────≡\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  596/  596 (100%)    【 精 力 】    0 /    0 (+0)\n"+
"【 气 血 】  1210/  1210 (100%)    【 内 力 】 3096 / 3096 (+0)\n"+
"【 食 物 】    0/  300           【 潜 能 】  0\n"+
"【 饮 水 】    0/  300           【 经 验 】  1016246\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【实习捕快】昆仑派第二代弟子「猎户座照耀的伤心人」阿卡(Rewj)\n"+
"\n"+
" 你是一位二十七岁八个月的男性人类，甲寅年一月一日辰时三刻生。\n"+
" 膂力：[16/ 36]  悟性：[31/ 49]   根骨：[21/ 42]  身法：[14/ 34]\n"+
" 耐力：[ 14]  福缘：[ 20]  胆识：[ 29]  定力：[ 11]  容貌：[ 15]\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 战斗攻击力    57936            战斗防御力   100818\n"+
" 战斗伤害力      230            战斗保护力        2\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 3795 个人，其中有 2 个是其他玩家。\n"+
" 你到目前为止总共死了 73 次了，其中有 68 次是非正常死亡。\n"+
"\n"+
" 正    气：    47384     潜    能： 5241 ( 98%)  实战经验：  1016246\n"+
" 魅    力：       60     江湖阅历：    32366     江湖威望：       30\n"+
"\n", this_object());
	return 1;
}
