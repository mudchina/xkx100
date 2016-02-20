// lingboweibu.c 凌波微步
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }
#include <xiaoyao.h>

string *dodge_msg = ({
	"$n轻轻巧巧地往前一步，衣袂飘忽，一式"HIW"「轻云蔽月」"NOR"身影恍惚如浮云，\n$N只觉眼花缭乱。\n",
	"$n袍袖轻拂，拔地而起，在空中转了一圈，一式"HIW"「流风回雪」"NOR"有如漫天\n琼花飞舞，$N目眩神迷，辨不清方向。\n",
	"$n抬手掩面，嫣然一笑，左一步，右二步，斜刺里又三步，一式"MAG"「罗袜生尘」"NOR"\n轻捷婀娜，只见地上纤尘纷扬，$N呆立半晌，浑忘了如何出招。\n",
	"$n待$N攻近面门，突然身形后仰，后退几步，一式"MAG"「轻裾曳雾」"NOR"施施然\n躲过了$N这一招。\n",
	"$n一式"HIM"「惊鸿回眸」"NOR"，一个侧身飘然掠起，转眼已在$N身后。\n",
	"$n舒展身体，抖擞精神，一式"HIY"「游龙翩飞」"NOR"迅捷如电，侧身让过了$N这招。\n",
	"$n回眸粲然，一式"HIG"「清流弄履」"NOR"有如流水溅湿文履，刹那间滑出丈余许，\n$N这一招扑了个空。\n",
	"$n泰然自若，左足上挑，右足力蹬，一式"HIG"「神渚濯足」"NOR"纵跃于几丈开外。\n",
	"$n气定神闲，笼袖不动，足下却是风生水起，一式"HIB"「屏翳收风」"NOR"飘然避过\n$N这招。\n",
	"$n身形将倾未倾，若往若还，一式"HIC"「川后静波」"NOR"如微风轻掠水面，倏忽已\n不见人影。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("beiming-shengong", 1) < 10 )
	return notify_fail("你的北冥神功不够精熟，无法领会凌波微步。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 10 )
		return notify_fail("你的体力太差了，无法练习凌波微步。\n");
	me->receive_damage("qi", 50);
	me->add("neili", -10);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"lingboweibu/" + action;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { 
	if (fam_type(me)=="xiaoyao")	return 1.5;
	return 1.0;
}

int help(object me)
{
	write(HIC"\n凌波微步："NOR"\n");
	write(@HELP

    洛神赋：“凌波微步，罗袜生尘……转盼流精，光润玉颜。含
辞未吐，气若幽兰。华容婀娜，令我忘餐。［禾农］纤得衷，修短
合度，肩若削成，腰如红素，延颈秀项，皓质呈露，芳泽无加，铅
华弗御。云髻峨峨，修眉连娟。丹唇外朗，皓齿内鲜。明眸善睐，
辅薜承权。环姿艳逸，仪静体闲。柔情绰态，媚于语言……皎若太
阳升朝霞，灼若芙蓉出绿波”。
    凌波微步原载于北冥神功帛卷卷末，按伏羲六十四卦而排，内
劲行遍一周天，脚步亦踏遍六十四卦一周天。步法轻灵迅捷，有如
凌波而行，罗袜生尘，巧妙已极。
    凌波微步乃逃命之妙法，非害人之本领也，练之有百利而无一
害。

	学习要求：
	  北冥神功10级
HELP
	);
	return 1;
}

