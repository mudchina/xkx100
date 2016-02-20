//jiuyin-baiguzhao.c 九阴白骨爪
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N势若疯虎，形若邪魔，双爪如钢抓铁钩，左手手腕翻处，右手疾伸，五根手指抓向$n$l",
]),
([	"action" : "突然人影闪动，$N迫到$n身后，袖中伸出手，五根手指向$n$l插了下去",
]),
([	"action" : "$N手臂关节喀喇一响，手臂斗然长了半尺，一掌按在$n$l，五指即要插进",
]),
([	"action" : "$N双手微张，十根尖尖的指甲映出灰白光芒，突然翻腕出爪，五指猛地插落",
]),
([	"action" : "$N左手突然在$n眼前上围下钩，左旋右转，连变了七八般，蓦地里右手一伸，五根手指直插$n$l",
]),
([	"action" : "$N双掌不住地忽伸忽缩，手臂关节喀喇声响，右掌一立，左掌啪的一下朝$n$l击去",
]),
([	"action" : "$N身形挫动，风声虎虎，接着朝$n连发八掌，一掌快似一掌，一掌猛似一掌",
]),
([	"action" : "$N攸地变爪为掌，身子不动，右臂陡长，潜运内力，一掌朝$n$l劈去",
]),
([	"action" : "$N一声怪啸，形如飘风，左掌已如风行电挚般拍向$n，掌未到，风先至，迅猛已极",
]),
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练九阴白骨爪必须空手。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法练九阴白骨爪。\n");
	return 1;
}
int practice_skill(object me)
{
	object* ob, obj;
	int i,skill,damage,cost;

	cost = 40;
	skill = me->query_skill("jiuyin-baiguzhao",1);
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 120)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练九阴白骨爪。\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("这里练功会误伤他人。\n");
	if( environment(me)->query("sleep_room") )
		return notify_fail("这里练功会打扰别人休息。\n");
	if( !objectp(obj=present("corpse", environment(me))))
		return notify_fail("练九阴白骨抓需有尸体。\n");
	if( skill > 100 && me->query("shen") > -100)
		return notify_fail("这种邪恶武功不是侠义道当练的。\n");
	if (skill > 150) cost = 80;
	if (skill >= 250) cost = 120;
	me->receive_damage("qi", cost);
	me->add("neili", -40);
//	tell_room(environment(me), 
  message_vision(
HIB"只见$N左手上圈下钩、左旋右转，连变了七八般花样，蓦地里右手一伸，噗的
一响，五根手指直插入地上尸体的脑门。随后五根手指"HIR"血淋淋"HIB"的提将起来。\n"NOR,me);
/*
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i]) || ob[i]->query_temp("noliving") ||
			ob[i]==me ) continue;
		if(skill+random(skill/2)<(int)ob[i]->query("con")*2) continue;
		damage = skill - ((int)ob[i]->query("neili") );
		if( damage > 0 )
		{
			ob[i]->receive_damage("qi", damage );
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_wound("qi", damage);
			tell_object(ob[i], HIB"忽然眼前黑影狂舞，你觉得眼前一阵阴气直袭面门，全身骤然感到要被撕裂开一样！\n"NOR);
		}
		if( userp(ob[i]) ) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
	}
*/
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
	int d_e1 = 20;
	int d_e2 = 5;
	int p_e1 = -20;
	int p_e2 = -60;
	int f_e1 = 300;
	int f_e2 = 600;
	int i, lvl, seq, ttl = sizeof(action);

	seq = random(ttl);       /* 选择出手招数序号 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "抓伤" : "内伤",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me)
    { 
      if ((int)me->query("shen")<=-100000) return 1; 
      else if ((int)me->query("shen")<0)  return 0.8;
      else return 0.6;
     }

void skill_improved(object me)
{
	tell_object(me, HIR"你忽然从心底生出一股恶念：杀、杀、杀！我要杀绝天下人！\n" NOR );
//	me->add("shen", -200);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/3) > victim->query_str() ) 
	{
    victim->receive_wound("qi", (damage_bonus - 80) / 3, me);
		return HIR "你听到「喀啦」一声轻响，竟似是骨碎的声音！\n" NOR;	
	}
}

int help(object me)
{
	write(HIC"\n九阴白骨爪："NOR"\n");
	write(@HELP

    徽宗皇帝于政和年间，遍搜普天下道家之书，雕版印行，一共
有五千四百八十一卷，称为‘万寿道藏’。皇帝委派刻书之人，叫
做黄裳。他生怕这部大道藏刻错了字，皇帝发觉之后不免要杀他的
头，因此上一卷一卷的细心校读。他居然便因此精通道学，更因此
而悟得了武功中的高深道理。他无师自通，修习内功外功，竟成为
一位武功大高手。他因此涉及江湖仇杀，退隐山林。不知不觉竟已
过了四十多年，终于对每一个敌人所使过的招数，他都想通了破解
的法子对付。于是出得山来，去报仇雪恨。不料那些敌人全都已不
在人世了。黄裳心想：‘原来我也老了，可也没几年好活啦。’他
花了这几十年心血，想出了包含普天下各家各派功夫的武学，过得
几年，这番心血岂不是就此湮没？于是他将所想到的法门写成了上
下两卷书，那就是《九阴真经》。九阴白骨爪就是依此书练成的霸
道功夫。

	学习要求：
		内力200
HELP
	);
	return 1;
}

