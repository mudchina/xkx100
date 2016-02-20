// anran-zhang.c
// Last Modified by sir 10.21.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action=({
([	"action":"$N抬头向天，浑若不见，呼的一掌向自己头顶空空拍出，手掌斜下，掌力化成弧形，四散落下。这一式"HIB"「杞人忧天」"NOR"力似穹庐，圆转广被，$n实是无可躲闪",
	"skill_name":"杞人忧天",
	"lvl":0
]),
([	"action":"$N手臂下垂，绝无半点防御姿式，待得$n攻到近肉寸许，突然间手足齐动，左掌右袖、双足头锤，一招"HIB"「无中生有」"NOR"连带胸背腰腹尽同时出招，无一不足伤敌",
	"skill_name":"无中生有",
	"lvl":10
]),
([	"action":"$N右手云袖飘动，宛若流水，左掌却重滞之极，便似带着几千斤泥沙一般。右袖是北方癸水之路，左掌是中央戊土之家，一式"HIB"「拖泥带水」"NOR"轻灵沉猛，兼而有之",
	"skill_name":"拖泥带水",
	"lvl":20
]),
([	"action": "$N缓步向前，瞅准$n出招空隙，无声无息发出一掌，正是"HIB"「徘徊空谷」"NOR"。",
	"skill_name":"徘徊空谷",	
	"lvl":30
]),
([	"action":"$N退后几步，似乎久战疲倦，力有不逮，等到$n趋近身前，“呼”地一
掌，一式"HIB"「力不从心」"NOR"劈向$n",
	"skill_name":"力不从心",
	"lvl":40
]),
([	"action":"$N退步避开，踢出一脚，使出一招"HIB"「行尸走肉」"NOR"，这一脚发出时恍恍
惚惚，隐隐约约，若有若无，踢向$n胸口",
	"skill_name":"行尸走肉",
	"lvl":60
]),
([	"action":"$N突然高高跃起，一招"HIB"「倒行逆施」"NOR"头下脚上，倒过身子，拍出一掌",
	"skill_name":"倒行逆施",
	"lvl":70
]),
([	"action":"$N收掌不动，待$n出招将至未至之际，眼中精光四射，肘弯一沉，突地
发出一掌，正是一招"HIB"「废寝忘食」"NOR"。",
	"skill_name":"废寝忘食",
	"lvl":80
]),
([	"action":"$N茕茕鹄立，傲然望天，待$n袭至身畔，凝然拍出一掌，一招"HIB "「孤形只影」"NOR"挥向$n肩背",
	"skill_name":"孤形只影",
	"lvl":100
]),
([	"action":"只见$N身形飘忽，神情怅然，猛地一式"HIB"「饮恨吞声」"NOR"，重重拍向$n身上",
	"skill_name":"饮恨吞声",
	"lvl":110
]),
([	"action":"$N身形晃动，长袖飘动，左掌飞扬，使出一招"HIB"「六神不安」"NOR"，将$n裹
在掌风之中",
	"skill_name":"六神不安",
	"lvl":120
]),
([	"action":"$N长叹一声，负手踽踽而行，浑然不理$n的攻击，直至最后一刻，蓦然
长声冷笑，转身就是一式"HIB"「穷途末路」"NOR"。",
	"skill_name":"穷途末路",
	"lvl":140
]),
([	"action":"$N一声清嘶，一式"HIB"「心惊肉跳」"NOR"，掌风如电，霎时间似乎千军万马一
齐杀到，将$n罩在掌影中",
	"skill_name":"心惊肉跳",
	"lvl":150
]),
([	"action":"$N脸上喜怒哀乐，怪状百出，$n一见，登时心神难以自制，呆立在$N
面前，$N见机“呼”地一掌"HIB"「面无人色」"NOR"拍向$n胸口",
	"skill_name":"面无人色",
	"lvl":160
]),
([	"action":"$N若有所思，自顾自疾步冲向$n，突然发招，一式"HIB"「想入非非」"NOR"出手如
电，扣向$n手腕，掌风兀自不歇，猛击$n小腹",
	"skill_name":"想入非非",
	"lvl":170
]),
([	"action":"$N呆立不动，怅然若失，催动内力硬生生抵住$n的一记重招，趁$n未及
撤招，蓦然一式"HIB"「呆若木鸡」"NOR"攻出，全身劲力倾注掌中",
	"skill_name":"呆若木鸡",
	"lvl":180
]),
([	"action":"$N面色惨白，双目无光，万念俱灰，没精打采地挥袖卷出，拍出一掌，
正是一招"HIB"「魂不守舍」"NOR"。",
	"skill_name":"魂不守舍",
	"lvl":200
]),
});

int valid_enable(string usage) {return usage=="unarmed" || usage=="parry";}

int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
	if(myfam["master_id"]!="yang guo")
		return notify_fail("你只能向杨过学这门武功。\n");
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("你的内力太弱，无法练黯然销魂掌。\n");
	if ((int)me->query_skill("yunv-xinfa", 1) < 100)
		return notify_fail("你的玉女心法不熟练，无法练黯然销魂掌。\n");
/*
	if((me->query("normal_die")<10)&&(time()-me->query("dietime")>300))
		return notify_fail("你没有能体会这门武功的心境。\n");
*/
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练黯然销魂掌必须空手。\n");
	return 1;
}
int practice_skill(object me)
{	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练黯然销魂掌。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -30);
	return 1;
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
	int d_e1 = 10;
	int d_e2 = 30;
	int p_e1 = -45;
	int p_e2 = 25;
	int f_e1 = 300;
	int f_e2 = 400;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("anran-zhang", 1);
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
		"damage_type" : random(2) ? "内伤" : "瘀伤",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"anran-zhang/" + action;
}
int help(object me)
{
	write(HIC"\n黯然销魂掌："NOR"\n");
	write(@HELP

    杨过自和小龙女在绝情谷断肠崖前分手，不久便由神雕带着在
海潮之中练功，数年之后，除了内功循序渐进之外，别的无可再练，
心中整日价思念小龙女，渐渐的形销骨立，了无生趣。一日在海滨
悄然良久，百无聊赖之中随意拳打脚踢，其时他内功火候已到，一
出手竟具极大威力，轻轻一掌，将海滩上一只大海龟的背壳打得粉
碎。他由此深思，创出了一套完整的掌法，出手与寻常武功大异，
厉害之处，全在内力，一共是一十七招。
    杨过生平受过不少武学名家的指点，自全真教学得玄门正宗内
功的口诀，自小龙女学得【玉女心经】，在古墓中见到【九阴真经
】，欧阳锋以蛤蟆功和逆转经脉，洪七公与黄蓉授以打狗棒法，黄
药师授以弹指神通和玉箫剑法，除了一阳指之外，东邪、西毒、北
丐、中神通的武学无所不窥，而古墓派的武学又于五大高人之外别
创蹊径，他依此融会贯通，卓然成家，创立此掌法。只因他单剩一
臂，是以不在招数变化取胜，反而故意与武学通理相反。将这套掌
法定名为“黯然销魂掌”，取的是江淹【别赋】中那一句“黯然销
魂者，唯别而已矣”之意。实饱含对小龙女的刻骨思念之情。

	学习要求：
		玉女心法100级
		内力1500
		只能向杨过学习
HELP
	);
	return 1;
}

