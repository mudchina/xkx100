inherit SKILL;

mapping *action = ({
([  "action" : "\n$N一记勾拳，勾向$n的$l。\n",
        "force" : 180,
        "dodge" : 5,
        "damage": 50,
        "damage_type" : "抓伤",
]),
([      "action" : "$N一记直拳，直捣$n的$l。",
        "force" : 200,
        "dodge" : 10,
        "damage": 60,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一记摆拳，直摆$n的$l。",
        "force" : 230,
        "dodge" : 10,
        "damage": 60,
        "damage_type" : "瘀伤"
]),
([      "action" : "\n$N一记重拳，击向$n的$l。",
        "force" : 230,
        "dodge" : 25,
        "damage": 70,
        "damage_type" : "内伤"
]),
([      "action" : "$N一套组合拳，直攻$n的要害部位。",
        "force" : 220,
        "dodge" : 15,
        "damage": 90,
        "damage_type" : "瘀伤",
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"|| usage=="hand"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练拳击必须空手。\n");
        if ((int)me->query("max_force") < 200)
                return notify_fail("你的内力太弱，无法练拳击。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("boxing", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 10)
                return notify_fail("你的内力不够练拳击。\n");
        me->receive_damage("kee", 15);
        me->add("force", -5);
        return 1;
}
