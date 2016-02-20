// lonely-sword.c 独孤九剑
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *parry_msg = ({
	"却见$n踏前一步，剑式斜指你的右臂，想要使$P闪身而退。\n",
	"$n以攻为守，以进为退，凝神运气向$P猛攻快打地挥出方位大异的泰山「快活三」三剑。\n",
	"$n剑法突变，剑势伸缩不定，奔腾矫夭，逆使嵩山剑法的「天外玉龙」企图迫使$P变招。\n",
	"$n突然一剑点向$P的$l，虽一剑却暗藏无数后着，$P手足无措，攻势不由自主停了下来！\n"
	"$n不闪不避，举剑闪电般使出「叠翠浮青」反削$P的$l，想挡过你此招。\n",
	"$n突然使出青城派松风剑法的「鸿飞冥冥」，可是方位却有所偏差，长剑对着$P一绞，企\n图突破$P的攻势！\n"
	"$n挺剑一招象是「白云出岫」回刺$P的$l，企图将$P的攻势化解。\n",
	"只见$n不退反进，身如飘风，诡异地一式「天柱云气」，动向无定不可捉摸地挡住了$P的\n进攻。\n",
	"$n不退反进，使出恒山剑招「绵里藏针」，森森剑气充溢四周！架开了$P的这招\n",
});

mapping *action = ({
([	"action" : "但见$N挺身而上，$w一旋，一招仿佛泰山剑法的「来鹤清泉」直刺$n
的$l！",
	"lvl" : 0,
	"skill_name" : "来鹤清泉"
]),
([	"action" : "$N奇诡地向$n挥出「泉鸣芙蓉」、「鹤翔紫盖」、「石廪书声」、「
天柱云气」及「雁回祝融」衡山五神剑！",
	"lvl" : 7,
	"skill_name" : "衡山五神剑"
]),
([
	"action" : "$N剑随身转，续而刺出十九剑，竟然是华山「玉女十九剑」，但奇的
是这十九剑便如一招，手法之快，直是匪夷所思！",
	"lvl" : 14,
	"skill_name" : "玉女十九剑"
]),
([	"action" : "$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢慢
推去！",
	"lvl" : 21,
	"skill_name" : "恒山剑法"
]),
([	"action" : "$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里
，尽括嵩山剑势击向$n的$l！",
	"lvl" : 28,
	"skill_name" : "长枪大戟"
]),
([	"action" : "却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，竟
化「泰山十八盘」为一剑攻向$n！",
	"lvl" : 35,
	"skill_name" : "泰山十八盘"
]),
([	"action" : "$N剑招突变，使出衡山的「一剑落九雁」，削向$n的$l，怎知剑到中
途，突然转向，大出$n意料之外！",
	"lvl" : 42,
	"skill_name" : "一剑落九雁"
]),
([	"action" : "$N吐气开声，一招似是「独劈华山」，手中$w向下斩落，直劈向$n的
$l！",
	"lvl" : 49,
	"skill_name" : "独劈华山"
]),
([	"action" : "$N手中$w越转越快，使的居然是衡山的「百变千幻云雾十三式」，剑
式有如云卷雾涌，旁观者不由得目为之眩！",
	"lvl" : 56,
	"skill_name" : "百变千幻云雾十三式"
]),
([	"action" : "$N含笑抱剑，气势庄严，$w轻挥，尽融「达摩剑」为一式，闲舒地刺
向$n！",
	"lvl" : 63,
	"skill_name" : "达摩剑"
]),
([	"action" : "$N举起$w运使「太极剑」剑意，划出大大小小无数个圆圈，无穷无尽
源源不绝地缠向$n！",
	"lvl" : 70,
	"skill_name" : "太极剑"
]),
([	"action" : "$N神声凝重，$w上劈下切左右横扫，挟雷霆万钧之势逼往$n，「伏摩
剑」的剑意表露无遗！",
	"lvl" : 77,
	"skill_name" : "伏摩剑"
]),
([	"action" : "却见$N突然虚步提腰，使出酷似武当「蜻蜓点水」的一招！",
	"lvl" : 84,
	"skill_name" : "蜻蜓点水"
]),
([	"action" : "$N运剑如风，剑光霍霍中反攻$n的$l，尝试逼$n自守，剑招似是「伏
魔剑」的「龙吞式」。",
	"lvl" : 91,
	"skill_name" : "龙吞式"
]),
([	"action" : "$N突然运剑如狂，一手关外的「乱披风剑法」，猛然向$n周身乱刺乱
削！",
	"lvl" : 98,
	"skill_name" : "乱披风剑法"
]),
([	"action" : "$N满场游走，东刺一剑，西刺一剑，令$n莫明其妙，分不出$N剑法的
虚实！",
	"lvl" : 105,
	"skill_name" : "莫明其妙"
]),
([	"action" : "$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什
么剑法！",
	"lvl" : 112,
	"skill_name" : "杂乱无章"
]),
([	"action" : "$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不知
如何是好！",
	"lvl" : 119,
	"skill_name" : "暗藏无数"
]),
([	"action" : "$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，迫
得$n不得不守！",
	"lvl" : 126,
	"skill_name" : "大开大阖"
]),
([	"action" : "$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力竟然奇大，$n
难以看清剑招来势！",
	"lvl" : 133,
	"skill_name" : "有招似无招"
]),
([	"action" : "$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么招
式。",
	"lvl" : 140,
	"skill_name" : "举剑狂挥"
]),
([	"action" : "$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可
思议！",
	"lvl" : 147,
	"skill_name" : "神妙无伦"
]),
([	"action" : "$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向$n
的$l！",
	"lvl" : 154,
	"skill_name" : "突现笑容"
]),
([	"action" : "$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，实人所难测！",
	"lvl" : 180,
	"skill_name" : "神剑之威"
])
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}
int valid_learn(object me)
{
	object ob;

	mapping myfam;
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "华山派"|| myfam["master_id"] != "feng qingyang")
		return notify_fail("独孤九剑只有向风清扬老前辈学习。\n");
	if( (int)me->query("max_neili") < 600 )
		return notify_fail("你的内力不够，没有办法练独孤九剑。\n");
	if( (int)me->query_skill("zixia-shengong",1)<100)
		return notify_fail("独孤九剑必须配合紫霞神功才能练习。\n");
	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	if ((int)me->query_skill("lonely-sword",1) > 120)
		return notify_fail("这套剑法我就教到这儿，以后就要靠你自己练了。\n");

	return 1;
}
int practice_skill(object me)
{
	return notify_fail("独孤九剑只能通过「总诀式」来演练。\n");
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = -25;
	int d_e2 = -5;
	int p_e1 = -55;
	int p_e2 = -35;
	int f_e1 = 150;
	int f_e2 = 230;
	int m_e1 = 220;
	int m_e2 = 320;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("lonely-sword", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	seq = random(seq);       /* 选择出手招数序号 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "割伤" : "刺伤",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point() { return 1.0; }

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
	return __DIR__"lonely-sword/" + action;
}

int help(object me)
{
	write(HIC"\n独孤九剑："NOR"\n");
	write(@HELP

    “独孤九剑，有进无退！”
    创制这套剑法的独孤求败前辈，名字叫做‘求败’，他毕生想
求一败而不可得，这剑法施展出来，天下无敌，当年他仗剑江湖，
无敌于天下，连找一个对手来逼得他回守一招都不可得，委实令人
可惊可佩。
    无招胜有招，敌强我更强。独孤九剑不含招式，有招既无招，
无招亦有招。独孤九剑要旨在于「悟」，不可拘泥不化，讲究料敌
机先，出奇制胜。通晓了九剑剑意，则无所施而不可。
    独孤九剑，自“总诀式”、“破剑式”、“破刀式”以至“破
枪式”、“破鞭式”、“破索式”、“破掌式”、“破箭式”而到
第九剑“破气式”。九剑的第一招“总诀式”，有种种变化，用以
体演总诀，便于修习。第二招“破剑式”，用以破解普天下各门各
派的剑法。第三招“破刀式”，用以破解单刀、双刀、柳叶刀、鬼
头刀、大砍刀、斩马刀种种刀法。第四招“破枪式”，包括破解长
枪、大戟、蛇矛、齐眉棍、狼牙棒、白蜡杆、禅杖、方便铲种种长
兵刃之法。第五招“破鞭式”，用以破解钢鞭、铁锏、点穴橛、拐
子、蛾眉刺、匕首、板斧、铁牌、八角槌、铁椎等等短兵刃，第六
招“破索式”，破解的是长索、软鞭、三节棍、链子枪、铁链、渔
网、飞锤流星等等软兵刃。第七招“破掌式”，破的是拳脚指掌上
的功夫，将长拳短打、擒拿点穴、魔爪虎爪、铁沙神掌，诸般拳脚
功夫尽数包括内在。第八招“破箭式”这个“箭”字，则总罗诸般
暗器，练这一剑时，须得先学听风辨器之术，不但要能以一柄长剑
击开敌人发射来的种种暗器，还须借力反打，以敌人射来的暗器反
射伤敌。第九剑“破气式”，是为对付身具上乘内功的敌人而用，
神而明之，存乎一心。

	学习要求：
		只能向风清扬学习
		紫霞神功100级
		内力600
HELP
	);
	return 1;
}

