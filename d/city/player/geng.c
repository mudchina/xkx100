// geng.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("滑滑小笼包", ({ "geng"}));
	set("gender", "男性");
	set("long","本潭早期玩家，终老于少林。苦心钻研武学，亦不避尘世
烟云。青灯古佛，佳人红袖添香；木鱼铜铎，痴心一段梵
唱。此生有一红颜知己，远在白驼大漠，从少林出山后曾
偕爱侣行走江湖，豪侠多情壮士也。\n");
	set("title", HIY"翰林硕士"HIG"明教风字门教众"NOR"少林派第三十五代弟子");
	set("nickname", HIC"花心大萝卜"NOR);
	set("age", 42);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 22);
	set("per", 26);
	set("int", 19);
	set("dex", 20);
	set("con", 20);
	set("str", 24);
	set("weiwang", 70);
	set("shen", 0);
	set("combat_exp", 2404210);
	set("PKS", 3);
	set("MKS", 1437);

	set("max_jing", 1004);
	set("jing", 1004);
	set("max_qi", 1251);
	set("qi", 1251);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3260);
	set("neili", 3260);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 121);
	set_skill("buddhism", 120);
	set_skill("club", 250);
	set_skill("claw",250);
	set_skill("force", 251);
	set_skill("unarmed",250);
	set_skill("parry", 255);
	set_skill("dodge", 250);
	set_skill("sword", 250);
	set_skill("blade", 250);
	set_skill("damo-jian", 219);
	set_skill("finger", 250);
	set_skill("fumo-jian", 260);
	set_skill("hunyuan-yiqi", 250);
	set_skill("jingang-quan", 203);
	set_skill("kongming-quan", 244);
	set_skill("lingboweibu", 268);
	set_skill("nianhua-zhi", 100);
	set_skill("qianye-shou", 110);
	set_skill("sanhua-zhang", 101);
	set_skill("sougu", 271);
	set_skill("strike", 250);
	set_skill("wuyun-jian", 265);
	set_skill("xiuluo-dao", 140);
	set_skill("yijinjing", 201);
	set_skill("zui-gun", 282);
	set_skill("qianye-shou", 110);
	set_skill("hand", 250);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "zui-gun");
	map_skill("sword", "damo-jian");
	map_skill("unarmed","kongming-quan");
	map_skill("club","zui-gun");
	map_skill("finger","nianhua-zhi");
	map_skill("strike","sanhua-zhang");
	map_skill("claw","sougu");
	map_skill("blade","xiuluo-dao");
        map_skill("hand","hand");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("少林派",35, "弟子");
	setup();
	carry_object(__DIR__"geng_sword")->wield();
	carry_object(CLOTH_DIR"seng-cloth")->wear();
        carry_object(CLOTH_DIR"seng-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"  基本刀法 (blade)                         - 深不可测 250/    0\n"+
"  禅宗心法 (buddhism)                      - 了然於胸 120/    0\n"+
"  基本轻功 (dodge)                         - 深不可测 250/    0\n"+
"  基本内功 (force)                         - 深不可测 251/    0\n"+
"  基本棍法 (club)                          - 深不可测 250/    0\n"+
"□达摩剑 (damo-jian)                       - 深不可测 219/    0\n"+
"  基本指法 (finger)                        - 深不可测 250/    0\n"+
"□空明拳 (kongming-quan)                   - 深不可测 244/    0\n"+
"  读书写字 (literate)                      - 了然於胸 121/    0\n"+
"  基本招架 (parry)                         - 深不可测 255/    0\n"+
"  伏摩剑 (fumo-jian)                       - 深不可测 260/    0\n"+
"  混元一气功 (hunyuan-yiqi)                - 深不可测 200/    0\n"+
"□大金刚拳 (jingang-quan)                  - 深不可测 203/    0\n"+
"  基本剑法 (sword)                         - 深不可测 250/    0\n"+
"□拈花指 (nianhua-zhi)                     - 出类拔萃 100/    0\n"+
"  基本拳脚 (unarmed)                       - 出神入化 250/    0\n"+
"□如来千叶手 (qianye-shou)                 - 出类拔萃 110/    0\n"+
"□散花掌 (sanhua-zhang)                    - 出类拔萃 101/    0\n"+
"  基本掌法 (strike)                        - 深不可测 250/    0\n"+
"  基本手法 (hand)                          - 深不可测 250/    0\n"+
"  基本爪法 (claw)                          - 深不可测 250/    0\n"+
"□易筋经神功 (yijinjing)                   - 深不可测 201/    0\n"+
"□少林醉棍 (zui-gun)                       - 深不可测 282/    0\n"+
"  五韵七弦剑 (wuyun-jian)                  - 深不可测 265/    0\n"+
"□修罗刀 (xiuluo-dao)                      - 出神入化 140/    0\n"+
"□搜骨鹰爪功 (sougu)                       - 深不可测 271/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】 1004/ 1004 (100%)    【 精 力 】    0 /   0 (+0)\n"+
"【 气 血 】 1251/ 1251 (100%)    【 内 力 】 3260 / 3260 (+0)\n"+
"【 食 物 】    0/  340           【 潜 能 】  0\n"+
"【 饮 水 】    0/  340           【 经 验 】  2404210\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【 圣  僧 】翰林硕士明教风字门教众少林派第三十五代弟子「花心大萝卜」滑滑小笼包(Geng)\n"+
"\n"+
" 你是一位四十二岁三个月的男性人类，甲午年十二月七日亥时二刻生。\n"+
" 膂力：[ 49]  悟性：[ 31]  根骨：[ 46]  身法：[ 42]\n"+
"\n"+
" 你的师父是达摩老祖。             你没有存款。\n"+
" 你还是个光棍。\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 战斗攻击力   450000            战斗防御力   880000\n"+
" 战斗伤害力       30            战斗保护力        1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 1437 个人，其中有 3 个是其他玩家。\n"+
"\n"+
" 正    气：        0     潜    能： 112 ( 99%)   实战经验：  2404210\n"+
" 魅    力：       60     江湖阅历：       54     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
