// xxqqf.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("标准情人", ({ "xxqqf"}));
	set("gender", "男性");
	set("long","桃花岛弟子，师从黄老邪经年苦练终成本潭武林至尊。开
创天龙门提携新手声名远扬。年轻气盛时曾独步中原，凭
借本门绝技“兰花拂穴”和“天外清音”狂傲不可一世，
后经历一番情感波折，悄然归隐桃花岛，潜心武学，不问
江湖。他的须发皆白，神色有些苍凉，然眼中不时掠过一
丝青芒，似七月的流星坠落天际。\n");
	set("title", HIW"圣人"NOR"天龙门门主"NOR);
	set("nickname", HIR"爱"HIG"你一万"HIB"年"NOR);
	set("age", 79);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 27);
	set("int", 30);
	set("dex", 18);
	set("con", 21);
	set("str", 20);
	set("weiwang", 30);
	set("shen", 10819664);
	set("combat_exp", 12129747);
	set("PKS", 28);
	set("MKS", 29859);

	set("max_jing", 485);
	set("jing", 485);
	set("max_qi", 1353);
	set("qi", 1353);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 4050);
	set("neili", 4050);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 201);
	set_skill("force", 290);
	set_skill("unarmed",250);
	set_skill("parry", 300);
	set_skill("dodge", 251);
	set_skill("sword", 270);
	set_skill("cuff", 250);
        set_skill("array",233);
        set_skill("bibo-shengong",260);
        set_skill("blade",250);
        set_skill("claw",250);
        set_skill("count",103);
        set_skill("finger",250);
        set_skill("hand",250);
        set_skill("jiuyin-baiguzhao",270);
        set_skill("kuangfeng-blade",182);
        set_skill("lanhua-shou",444);
        set_skill("lingboweibu",50);
        set_skill("luoying-zhang",443);
        set_skill("qimen-wuxing",51);
        set_skill("shenxing-baibian",375);
        set_skill("strike",250);
        set_skill("taixuan-gong",248);
        set_skill("tanzhi-shentong",369);
        set_skill("xuanfeng-leg",427);
        set_skill("yuxiao-jian",444);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "shenxing-baibian");
	map_skill("parry", "lanhua-shou");
	map_skill("sword", "yuxiao-jian");
	map_skill("unarmed","xuanfeng-leg");
	map_skill("hand","lanhua-shou");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("桃花岛",3, "弟子");
	setup();
	carry_object(__DIR__"xxqqf_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"  暗影浮香 (anying-fuxiang)                - 深不可测 340/  303\n"+
"  基本阵法 (array)                         - 深不可测 233/12605\n"+
"□碧波神功 (bibo-shengong)                 - 深不可测 260/13541\n"+
"  基本刀法 (blade)                         - 深不可测 250/    0\n"+
"  基本爪法 (claw)                          - 深不可测 250/    0\n"+
"  阴阳八卦 (count)                         - 心领神会 103/  283\n"+
"  基本拳法 (cuff)                          - 深不可测 250/    0\n"+
"  基本轻功 (dodge)                         - 深不可测 251/ 3268\n"+
"  基本指法 (finger)                        - 深不可测 250/    0\n"+
"  基本内功 (force)                         - 深不可测 290/29861\n"+
"  基本手法 (hand)                          - 深不可测 250/    5\n"+
"□九阴白骨抓 (jiuyin-baiguzhao)            - 深不可测 270/   59\n"+
"□狂风刀法 (kuangfeng-blade)               - 一代宗师 182/27564\n"+
"□兰花拂穴手 (lanhua-shou)                 - 超凡入圣 444/78267\n"+
"  凌波微步 (lingboweibu)                   - 半生不熟  50/  380\n"+
"  读书写字 (literate)                      - 深不可测 201/    0\n"+
"□落英神剑掌 (luoying-zhang)               - 超凡入圣 443/117000\n"+
"  基本招架 (parry)                         - 深不可测 300/76467\n"+
"  奇门五行 (qimen-wuxing)                  - 略知一二  51/  861\n"+
"□神行百变 (shenxing-baibian)              - 深不可测 375/10342\n"+
"  基本掌法 (strike)                        - 深不可测 250/    0\n"+
"  基本剑法 (sword)                         - 深不可测 270/    1\n"+
"  太玄功 (taixuan-gong)                    - 深不可测 248/    0\n"+
"□弹指神通 (tanzhi-shentong)               - 深不可测 369/93330\n"+
"  基本拳脚 (unarmed)                       - 深不可测 250/    0\n"+
"□旋风扫叶腿 (xuanfeng-leg)                - 超凡入圣 427/   14\n"+
"□玉箫剑法 (yuxiao-jian)                   - 超凡入圣 444/37462\n", this_object());
	return 1;
}
int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  485/  485 (100%)   【 精 力 】    0 /    0 (+0)\n"+
"【 气 血 】 1353/ 1353 (100%)   【 内 力 】 4050 / 4050 (+0)\n"+
"【 食 物 】  222/  280          【 潜 能 】  49584\n"+
"【 饮 水 】  225/  280          【 经 验 】  12129747\n"+
"≡──────────────────────────────≡\n", this_object());
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【旷世大侠】圣人天龙门门主桃花岛第三代弟子「爱你一万年」标准情人(Xxqqf)\n"+
"\n"+
" 你是一位七十九岁十二个月的男性人类，戊午年二月二十七日丑时一刻生。\n"+
" 膂力：[ 18]  悟性：[ 30]  根骨：[ 21]  身法：[ 24]\n"+
"\n"+
" 你的师父是陆乘风。             存款：十八万三千五百五十两黄金。\n"+
" 你还是个光棍。\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 战斗攻击力   317578            战斗防御力   860038\n"+
" 战斗伤害力      260            战斗保护力        1\n"+
"\n"+
" 食物：■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" 饮水：■■■■■■■■■■■■■■■■■■■■■■□□□\n"+
"\n"+
" 你到目前为止总共杀了 29860 个人，其中有 28 个是其他玩家。\n"+
" 你到目前为止总共死了 5 次了，其中有 -1 次是非正常死亡。\n"+
"\n"+
" 正    气： 10820830     潜    能： 49612 ( 95%)         实战经验： 12130073\n"+
" 魅    力：       60     江湖阅历：    43898     江湖威望：       30\n"+
"\n", this_object());
	return 1;
}

