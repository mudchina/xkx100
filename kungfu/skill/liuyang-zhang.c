// liuyang-zhang.c 天山六阳掌
// Last Modified by sir 10.22.2001

#include <ansi.h>
#include <xiaoyao.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
void sun1(object me, object victim, object  weapon, int damage);
void sun2(object me, object victim, object  weapon, int damage);
void sun3(object me, object victim, object  weapon, int damage);
void sun4(object me, object victim, object  weapon, int damage);
void sun5(object me, object victim, object  weapon, int damage);
void sun6(object me, object victim, object  weapon, int damage);

mapping *action = ({

([	"action" : "$N一招"RED"「落日熔金」"NOR"，左掌叠于右掌之上，劈向$n",
	"lvl" : 0,
	"skill_name" : "落日熔金"
]),
([	"action" : "$N一招"HIY"「安禅制毒龙」"NOR"，面色凝重，双掌轻飘飘地拍向$n",
	"lvl" : 20,
	"skill_name" : "安禅制毒龙"
]),
([	"action" : "$N一招"HIR"「日斜归路晚霞明」"NOR"，双掌幻化一片掌影，将$n笼罩于内。",
	"lvl" : 30,
	"skill_name" : "日斜归路晚霞明"
]),

//([	"action" : "$N一招"HIG"「阳关三叠」"NOR"，向$n的$l连击三掌",
//	"lvl" : 40,
//	"skill_name" : "阳关三叠"
//]),
([	"action" : "$N一招"GRN"「阳春一曲和皆难」"NOR"，只见一片掌影攻向$n",
	"lvl" : 40,
	"skill_name" : "阳春一曲和皆难"
]),

([	"action" : "$N双掌平挥，一招"BLU"「云霞出海曙」"NOR"击向$n",
	"lvl" : 60,
	"skill_name" : "云霞出海曙"
]),
([	"action" : "$N一招"HIW"「白日参辰现」"NOR"，只见一片掌影攻向$n",
	"lvl" : 70,
	"skill_name" : "白日参辰现"
]),

([	"action" : "$N左掌虚晃，右掌一记"HIC"「云霞出薛帷」"NOR"击向$n的头部",
	"lvl" : 80,
	"skill_name" : "云霞出薛帷"
]),
([	"action" : "$N施出"HIB"「青阳带岁除」"NOR"，右手横扫$n的$l，左手攻向$n的胸口",
	"lvl" : 90,
	"skill_name" : "青阳带岁除"
]),
//([	"action" : "$N施出"HIR"「阳歌天钧」"NOR"，双掌同时击向$n的$l",
//	"lvl" : 100,
//	"skill_name" : "阳歌天钧"
//])
  ([ "action": 
HIY"$N使出"HBBLU+HIW"天山六阳掌"NOR+HIY"第一掌"HIR"「阳关三叠」"HIY"强劲的掌力以连绵不绝生生不息之力
有如排山倒海之势朝$n击去，一掌三式掌劲浑厚无匹。"NOR,
        "lvl" : 201,
                "force":                500,
     //           "damage":               300,
                 "post_action":               (:sun1:),
                "damage_type":  "内伤",                
       ]),
//2
  ([ "action": 
HIY"$N聚起全身的内力化劲成焰，一招"HIW"「烈阳普照」"HIY"全身上下发出巨大的光芒，刺
眼的光芒使$n无法张眼，$N身上发出强烈的温度使$n全身灼伤有如陷
入焚炉之中痛苦万分。"NOR,
        "lvl" : 210,
        "force":        520,
     //   "damage":       350,
        "post_action":               (:sun2:),
        "damage_type":  "灼伤",
        ]),
//3
  ([ "action":
HIY"$N左手运劲内走奇经八脉化气成焰，右手逆转内劲气走丹田化为霜，使出\n"
HBBLU+HIW"天山六阳掌"NOR+HIY"第三掌"HIC"「阳盛阴衰」"HIY"，强大的内劲催使$n左冷右热两极
交叉内息大乱受到严重的内伤狂吐鲜血。"NOR,
           "lvl" : 220,
           "force":       540,
       //    "damage":      400,
           "post_action":               (:sun3:),
           "damage_type":  "内伤",
      ]),
//4
  ([ "action": 
HIC"$N身法如鹰府冲而下使出"HBBLU+HIW"天山六阳掌"NOR+HIC"第四掌"HIW"「阳歌天钧」"HIC"以诡异的身法游走$n的四方，趁其不备双
手运勾朝$n的脑门扑击而去。"NOR,
        "lvl" : 230,
          "force":        560,
      //    "damage":       450,
          "post_action":          (:sun4:),
          "damage_type":  "瘀伤",
        ]),
//5
  ([ "action": 
HIM"$N使出"HBBLU+HIW"天山六阳掌"NOR+HIM"第五掌"HIC"「春阳白雪」"HIM"，$N身形飞舞全身散发寒劲成霜，当场雪
花漫天飞舞，$n完全看不见四周的情形，$N趁机发动攻势偷袭使其受创。"NOR,
        "lvl" : 240,
           "force":        580,
     //      "damage":       500,
          "post_action":      (:sun5:),
           "damage_type":  "瘀伤",
        ]),
//6
  ([ "action": 
HIR"$N聚劲双臂运劲成焰，凝聚强大的热量使出"HBBLU+HIW"天山六阳掌"NOR+HIR"第六掌"HIY"「骄阳似火」"HIR"，烈焰
掌劲侵入$n全身阵阵如火酷劲有如遭烈焰焚身。"NOR,
        "lvl" : 250,
           "force":        600,
     //      "damage":       600,
           "post_action":      (:sun6:),
           "damage_type":  "焚伤",
        ])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="zhemei-shou"; }

int valid_learn(object me)
{
	if(((int)me->query_skill("bahuang-gong", 1) < 20 ) &&
		((int)me->query_skill("beiming-shengong", 1) < 20 ))
		return notify_fail("你的本门内功还不够娴熟。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练天山六阳掌必须空手。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练六阳掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练天山六阳掌。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
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
	int d_e1 = -30;
	int d_e2 = -10;
	int p_e1 = 10;
	int p_e2 = 40;
	int f_e1 = 160;
	int f_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("liuyang-zhang", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	if ( fam_type(me)=="lingjiu" && (int)me->query_skill("bahuang-gong",1) >= 250)
	{
			seq=sizeof(action)-6+random(6);
			return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : action[seq]["force"],
		"damage"      : action[seq]["damage"],
		"post_action"	: action[seq]["post_action"],
		"damage_type" : random(2) ? "内伤" : "瘀伤",
	  ]);
	}
	if (seq > sizeof(action)-6)
		seq = sizeof(action)-6;
	seq = random(seq);       /* 选择出手招数序号 */
  	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "内伤" : "瘀伤",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"liuyang-zhang/" + action;
}
void sun1(object me, object victim, object weapon, int damage)
{
         if(((me->query("combat_exp")+random(2000000)) > (victim->query("combat_exp")+random(2000000)))
         || random(50)>40)
         {
           message_combatd(HIR"阳关三叠之"HBRED+HIM"【毁山劈天】\n"NOR, me, victim);
           victim->receive_damage("qi",200);
           COMBAT_D->report_status(victim);
           message_combatd(HIR"阳关三叠之"HBBLU+HIC"【形合破灭】\n"NOR, me, victim);
           victim->receive_wound("qi",100);
           COMBAT_D->report_status(victim);
           message_combatd(HIR"阳关三叠之"HBGRN+HIG"【虚空无极】\n"NOR, me, victim);
           if((victim->query("neili")-100)<0)
             victim->set("neili",0);
           else victim->add("neili",-100);
           COMBAT_D->report_status(victim);
         }else message_combatd(HIW"$n顺势闪过了$N烈阳余劲的攻击。\n"NOR, me, victim);          
        
}
void sun2(object me, object victim, object weapon, int damage)
{
	if(((me->query_skill("dodge")+random(100)) > (victim->query_skill("dodge")+random(100)))
         || random(50)>40)
        {
	  message_combatd(HIR"\n$n一个不小心被$N的烈阳余劲所伤。\n"NOR, me, victim);
	  victim->receive_damage("qi",200);
	  victim->apply_condition("hot_poison",random(10)+1);
	  COMBAT_D->report_status(victim);
	}
}
void sun3(object me, object victim, object  weapon, int damage)
{
       if(((me->query_skill("force")+random(500)) > (victim->query_skill("force")+random(500)))
         || random(50)>30)
       {
         message_combatd(HIC"\n$n受不了忽冷忽热的煎熬受了严重的内伤。\n"NOR, me, victim);
         victim->receive_damage("qi",300);
         victim->apply_condition("cuff_power",1);
         COMBAT_D->report_status(victim);
       }
}
void sun4(object me, object victim, object weapon, int damage)
{
       if(((me->query_skill("parry")+random(100)) > (victim->query_skill("parry")+random(100)))
         || random(50)>45)
       {
         message_combatd(HIY"\n$n闪躲不击惨招$N凌厉攻势所伤。\n"NOR, me, victim);
         victim->receive_wound("qi",200);
         victim->apply_condition("bleeding",random(10)+1);
         COMBAT_D->report_status(victim);
       }
}
void sun5(object me, object victim, object weapon, int damage)
{
       if(((me->query("parry")+random(100)) > (victim->query("parry")+random(100)))
         || random(50)>40)
       {
         message_combatd(HIW"\n$N使出天山六阳掌之变招‘天山折梅手’，$n被此招牵制无法使力。\n"NOR, me, victim);
         victim->receive_damage("qi",200);
         victim->start_busy(me->query_skill("liuyang-zhang",1)/100);
         COMBAT_D->report_status(victim);
       }
}

void sun6(object me, object victim, object weapon, int damage)
{
       if(((me->query("combat_exp")+random(2000000)) > (victim->query("combat_exp")+random(2000000)))
         || random(50)>45)
       {
         message_combatd(HIG"$N"HIY"骄阳似火"HIG"一出，$n运劲丹田竟感觉空空荡荡毫无内劲。\n"NOR, me, victim);
         if (victim->query("neili")<500)
          victim->set("neili",0);
         else 
          victim->add("neili",-500);
 //        COMBAT_D->report_status(victim);
       }
}

int help(object me)
{
	write(HIC"\n天山六阳掌："NOR"\n");
	write(@HELP

    天山六阳掌为灵鹫宫武功绝技。

	学习要求：
		北冥神功20级或八荒六合唯我独尊功20级
		内力50
HELP
	);
	return 1;
}

