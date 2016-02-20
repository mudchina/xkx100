inherit SKILL;

string *dodge_msg = ({
    "$n一个〖开〗步，躲过了$N这一招。\n",
    "$n一个〖绷〗步，避过了$N的攻击。\n",
    "$n一个〖直〗步，在千钧一发间躲过了$N的攻势。\n",
    "$n一个〖立〗步，潇洒地避了开去。\n"
});

int valid_enable(string usage)
{
    return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if( (int)me->query("kee") < 40 )
   return notify_fail("你的体力太差了，不能练芭蕾。\n");
    if (me->query_skill("balei", 1) < 30)
   me->receive_damage("kee", 10);
    else if (me->query_skill("balei", 1) < 60)
   me->receive_damage("kee", 20);
    else
   me->receive_damage("kee", 30);
    return 1;
}
