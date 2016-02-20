// bixie-jian.c 辟邪剑法
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
inherit F_SSERVER;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *dodge_msg = ({
	"突然之间，白影急幌，$n向后滑出丈余，立时又回到了原地，躲过了$N这一招。\n",
	"$n手臂回转，在$N手肘下一推，顺势闪到一旁。\n",
	"$n右手伸出，在$N手腕上迅速无比的一按，顺势跳到一旁。\n",
	"$n身形飘忽，有如鬼魅，转了几转，移步到$N的身后，躲过了$N这一招。\n",
	"$N只觉眼前一花，似乎见到$n身形一幌，但随即又见$n回到原地，却似从未离开。\n",
	"$N眼睛一花，$n已没了踪影。突然$n从身后拍了一下$N的头，轻轻跃开。\n",
	"$n嫣然一笑，诡异之极，$N竟不知如何是好，停住了攻击。\n",
});

mapping *action = ({
([	"action":"突然之间，白影急幌，$N向后滑出丈余，立时又回到了原地",
	"lvl" : 0,
	"skill_name" : "白影急幌"
]),
([	"action":"$N右手伸出，在$n手腕上迅速无比的一按，$n险些击中自己小腹",
	"lvl" : 10,
	"skill_name" : "自己小腹"
]),
([	"action":"蓦地里$N猱身而上，蹿到$n的身后，又跃回原地",
	"lvl" : 25,
	"skill_name" : "猱身而上"
]),
([	"action":"$N突然间招法一变，$w忽伸忽缩，招式诡奇绝伦。$n惊骇之中方寸大乱",
	"lvl" : 35,
	"skill_name" : "招法一变"
]),
([	"action":"$N身形飘忽，有如鬼魅，转了几转，移步到$n的左侧",
	"lvl" : 40,
	"skill_name" : "有如鬼魅"
]),
([	"action":"$N一声冷笑，蓦地里疾冲上前，一瞬之间，与$n相距已不到一尺，$w随即递出",
	"lvl" : 45,
	"skill_name" : "疾冲上前"
]),
([	"action":"$N喝道：“好！”，便即拔出$w，反手刺出，跟着转身离去",
	"lvl" : 45,
	"skill_name" : "反手刺出"
]),
([	"action":"$n只觉眼前一花，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开",
	"lvl" : 20,
	"skill_name" : "眼前一花"
]),
([	"action":"$N向后疾退，$n紧追两步，突然间$N闪到$n面前，手中$w直指$n的$l",
	"lvl" : 5,
	"skill_name" : "向后疾退"
]),
([	"action":"$N蓦地冲到$n面前，手中$w直刺$n右眼！$n慌忙招架，不想$N的$w突然转向",
	"lvl" : 45,
	"skill_name" : "直刺右眼"
]),
([	"action":"$N飞身跃起，$n抬眼一望，但见得$N从天直落而下，手中$w刺向$n的$l",
	"lvl" : 64,
	"skill_name" : "飞身跃起"
]),
([	"action":"$N腰枝猛摆，$n眼前仿佛突然出现了七八个$N，七八只$w一起刺向$n",
	"lvl" : 79,
	"skill_name" : "腰枝猛摆"
]),
});
int valid_enable(string usage)
{
	return usage == "sword" || usage == "dodge" || usage == "parry";
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int valid_learn(object me)
{
	return notify_fail("辟邪剑法只能通过研习《葵花宝典》来学习。\n");
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
	int d_e1 = -40;
	int d_e2 = -20;
	int p_e1 = -60;
	int p_e2 = -40;
	int f_e1 = 150;
	int f_e2 = 230;
	int m_e1 = 240;
	int m_e2 = 340;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("bixie-jian", 1);
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
int power_point(object me)
{
	if(me->query_skill("kuihua-xinfa",1) > 10) return 1.0; 
	else return 0.6;
}

string perform_action_file(string action)
{
	return __DIR__"bixie-jian/" + action;
}

void double_attack(object me, object victim)
{
	int i,j;
	object other=offensive_target(me);
	if (objectp(other)) victim = other;

	i = me->query_skill("bixie-jian",1)/15; // taiji lian的每招递增 sword/15
	j = (me->query_skill("bixie-jian",1)-1)/100; // 100 = 0 101 = 1 200 = 1 201 = 2 

  if ( j > 1 && !me->query_temp("bixie/guimei") && userp(me)) j = 1;
  
	if (userp(me))
	j = 1; //多于平时的double attack改成pfm出招
				 //注意变量 query_temp("bixie_hit")表示即将出手的是第多少招
         //不如这样，对于npc直接在单招中使用 对于玩家在pfm中使用
	if(  me->query_temp("bixie_hit") < j && 
  objectp(me->query_temp("weapon")) && 
  (me->query_temp("weapon"))->query("skill_type")=="sword"  &&
  me->query_skill_mapped("sword") == "bixie-jian" &&
  me->is_fighting(victim) )
	{
		me->add_temp("bixie_hit", 1);
		me->add_temp("apply/attack", i);
  	me->set_temp("action_flag",1);
		COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),2);
		me->set_temp("action_flag",0);
		me->add_temp("apply/attack", -i);
		me->add_temp("bixie_hit", -1);
	}
}

int help(object me)
{
	write(HIC"\n辟邪剑法："NOR"\n");
	write(@HELP

    要说辟邪剑法，就要从《葵花宝典》谈起。

    《葵花宝典》是一位宦官所作。这样一位大高手，为什麽在皇
宫中做太监，那是谁也不知道。至於宝典中所载的武功，却是精深
之极，三百多年来，始终无一人能据书练成。百余年前，这部宝典
为福建莆田少林寺下院所得。其时莆田少林寺方丈红叶禅师，乃是
一位大智大慧的了不起人物，依照他的武功悟性，该当练成宝典上
所载武功才是。但他研究多年，直到逝世，始终没有起始练宝典中
的武功。

    一日华山派的岳肃和蔡子峰到莆田少林寺作客，偷看到《葵花
宝典》。其时匆匆之际，二人不及同时阅遍全书，当下二人分读，
一人读一半，後来回到华山，共同叁悟研讨。不料二人将书中功夫
一加印证，竟然牛头不对马嘴，全然合不上来。二人都深信对方读
错了书，只有自己所记的才是对的。华山的剑气二宗之分由此而起。

    红叶禅师不久发现此事，他知道这部宝典所载武学不仅博大精
深，且蒹凶险之极。这最难的还是第一关，只消第一关能打通，到
後来也没什麽。第一关只要有半点岔差，立时非死即伤。红叶当下
派遣得意弟子渡元禅师前往华山，劝论岳蔡二位，不可修习宝典中
的武学。

    渡元禅师上得华山，岳蔡二人对他好生相敬，承认私阅《葵花
宝典》，一面深致歉意，一面却以经中所载武学向他请教。殊不知
渡元虽是红叶的得意弟子，宝典中的武学却未蒙传授。当下渡元禅
师并不点明，听他们背诵经文，随口加以解释，心中却暗自记下。
渡元禅师武功本极高明，又是绝顶机智之人，听到一句经文，便己
意演绎几句，居然也说来头头是道。

    不过岳蔡二人所记的本已不多，经过这麽一转述，不免又打了
折扣。渡元禅师在华山上住了八日，这才作别，但从此却也没再回
到莆田少林寺去。不久红叶禅师就收到渡元禅师的一通书信，说道
他凡心难抑，决意还俗，无面目再见师父云云。

    由於这一件事，华山派弟子偷窥《葵花宝典》之事也流传於外。
过不多时，魔教十长老来攻华山，在华山脚下一场大战。魔教十长
老多身受重伤，大败而去。但岳肃和蔡子峰两人均在这一役中毙命，
而二人所录《葵花宝典》也被魔教夺了去。

    渡元禅师还俗之後，复了原姓，将法名颠倒过来取名远图，娶
妻生子，创立镖局，在江湖上轰轰烈烈干了一番事业。

    莆田少林寺的红叶禅师园寂之时，召集门人弟子，说明这部宝
典的前因後果，便即将其投如炉中火化。红叶说：这部武学秘笈精
妙奥妙，但其中许多关键之处，当年的撰作人并未能妥为叁通解透，
留下的难题太多。尤其是第一关难过，不但难过，简直是不能过不
可过，流传後世，实非武林之福。

    林远图的辟邪剑法，是从《葵花宝典》残篇中悟出的武功，两
者系出同源。辟邪剑法有七十二路，但一来从不外传，二来使用此
剑法之人个个动作迅捷诡异，外间无人得知其招法的名目，只知道
其招式乃匪夷所思。林远图所自录的《辟邪剑谱》加了许多自己的
解释，故较魔教所藏的《葵花宝典》易入门，但少了些内容。所以
玩家欲习此功，当遵循先易後难之序。致於如何得到这两部武林秘
笈，则一直是江湖上避而不谈的秘密。如泄露此秘，会招来杀身之
祸。

	学习要求：
		自宫做太监
HELP
	);
	return 1;
}

