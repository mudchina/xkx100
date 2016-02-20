// ÕâÊÇÍæ¼Ò×Ô´´Îä¹¦³ÌĞò¡£
// waiter
// µêĞ¡¶ş
// ÎäÁÖÖÁ×ğåĞÒ£ÅÉ»¤·¨Ê¹Õß
// 15395700
// ÄĞĞÔ
// unarmed
// ĞşÚ¤ÉñÕÆ
#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
string owner() {return "waiter";}

mapping *action = ({
// ZHAOSHI :0
([
	"action" : "$N×óÊÖĞé»ÎÁ½ÕĞ£¬ºöµÄÒ»¸ö´Ü²½¹¥µ½$nÉíÇ°£¬ÓÒÕÆÒ»Ê½¡¸ÀäÈĞ¾÷¡¹£¬Ö±ÅÄ$nÄ³µÄ²¿Î»¡£[2;37;0m",
	"lvl" : 0,
	"skill_name" : "ÀäÈĞ¾÷",
]),
// ZHAOSHI :1
([
	"action" : "$N×ó½ÅĞéÌ¤£¬È«ÉíÓÒ×ª£¬Ò»ÕĞ¡¸¶Ï³¦¾÷¡¹£¬ÓÒÕÆÃÍµØ²åÏò$nµÄ$l¡£[2;37;0m",
	"lvl" : 20,
	"skill_name" : "¶Ï³¦¾÷",
]),
// ZHAOSHI :2
([
	"action" : "$N×óÕÆÈ¦»¨ÑïÆğ£¬ÇüÖâµ±ĞØ£¬»¢¿Ú³¯ÉÏ£¬Ò»ÕĞ¡¸´ßĞÄ¾÷¡¹´òÏò$nµÄ$l¡£[2;37;0m",
	"lvl" : 40,
	"skill_name" : "´ßĞÄ¾÷",
]),
// ZHAOSHI :3
([
	"action" : "$NÊ¹Ò»ÕĞ¡¸Õğ»ê¾÷¡¹£¬ÉÏÉíÇ°Ì½£¬Ë«ÊÖ»®ÁË¸ö°ëÈ¦£¬»÷Ïò$nµÄ$l¡£[2;37;0m",
	"lvl" : 60,
	"skill_name" : "Õğ»ê¾÷",
]),
});
// ZHAOSHI :4
int valid_learn(object me)
{
	string creater;

	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎŞ·¨Á·"+"ĞşÚ¤ÉñÕÆ"+"¡£\n");
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("Á·"+"ĞşÚ¤ÉñÕÆ"+"±ØĞë¿ÕÊÖ¡£\n");
	creater = this_object()->owner();
	if (userp(me) &&
	me->query("id")!=creater && 
	me->query("couple/couple_id")!=creater)
	return notify_fail("²»ÄÜÏòÆäËûÍæ¼ÒÑ§Ï°×Ô´´µÄÎä¹¦¡£\n");
	return 1;
}
int valid_enable(string usage)
{
	return usage== "unarmed" || usage=="parry";
}
int practice_skill(object me)
{
	string skname=explode(__FILE__,"/")[<1][0..<3];
	int lvl = me->query_skill(skname,1);
	int i=sizeof(action);
	int qicost;
	int nlcost;

	qicost = (126 + 231)/10;
	nlcost = (126 + 231)/15;
	if( (int)me->query("qi") < qicost )
		return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ĞİÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	if( (int)me->query("neili") < nlcost )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ĞİÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	me->receive_damage("qi", qicost);
	me->add("neili", -nlcost);
	if (lvl>=action[i-1]["lvl"]+20)
		return notify_fail("ÕâÒ»ÕĞÄãÒÑ¾­Á·µ½¶¥ÁË£¬¸Ã×êÑĞ×êÑĞĞÂµÄÕĞÊ½ÁË¡£\n");
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
	int d_e1 = 18;
	int d_e2 = 0;
	int p_e1 = 39;
	int p_e2 = 23;
	int f_e1 = 126;
	int f_e2 = 231;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("xuanminzhang-unarmed", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* »ñµÃÕĞÊıĞòºÅÉÏÏŞ */
			break;
		}
	seq = random(seq);       /* Ñ¡Ôñ³öÊÖÕĞÊıĞòºÅ */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
                "damage_type" : random(2) ? "ÄÚÉË" : "ğöÉË",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__+"xuanminzhang-unarmed"+"/" + action;
}
int help(object me)
{
	write(HIC"\n"+"ĞşÚ¤ÉñÕÆ"+"£º"NOR"\n");
	write(@HELP

	ĞşÚ¤ÉñÕÆÎªÎ÷Óò¾øÑ§Ö®Ò»£¬ÖÁÒõÖÁº®£¬ÍşÁ¦¼«´ó¡£
HELP
	);
	return 1;
}