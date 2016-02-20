// lonely-sword.c 独孤九剑
// Last Modified by sir 10.22.2001

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h"

inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
int action_po(object me, object victim, object weapon, int damage);//
int action_busy(object me, object victim, object weapon, int damage);
int action_damage(object me, object victim, object weapon, int damage);//
int action_parry(object me, object victim, object weapon, int damage);
int action_dodge(object me, object victim, object weapon, int damage);


string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *parry_msg = ({
	"却见$n踏前一步，剑式斜指你的右臂，想要使$P闪身而退。\n",
	"$n以攻为守，以进为退，凝神运气向$P猛攻快打地挥出方位大异的泰山"+(order[random(13)])+"「快活三」"NOR"三剑。\n",
	"$n剑法突变，剑势伸缩不定，奔腾矫夭，逆使嵩山剑法的"+(order[random(13)])+"「天外玉龙」"NOR"企图迫使$P变招。\n",
	"$n突然一剑点向$P的$l，虽一剑却暗藏无数后着，$P手足无措，攻势不由自主停了下来！\n",
	"$n不闪不避，举剑闪电般使出"+(order[random(13)])+"「叠翠浮青」"NOR"反削$P的$l，想挡过你此招。\n",
	"$n突然使出青城派松风剑法的"+(order[random(13)])+"「鸿飞冥冥」"NOR"，可是方位却有所偏差，长剑对着$P一绞，企\n图突破$P的攻势！\n",
	"$n挺剑一招象是"+(order[random(13)])+"「白云出岫」"NOR"回刺$P的$l，企图将$P的攻势化解。\n",
	"只见$n不退反进，身如飘风，诡异地一式"+(order[random(13)])+"「天柱云气」"NOR"，动向无定不可捉摸地挡住了$P的\n进攻。\n",
	"$n不退反进，使出恒山剑招"+(order[random(13)])+"「绵里藏针」"NOR"，森森剑气充溢四周！架开了$P的这招\n",
});

mapping *action = ({
([	"action" : "但见$N挺身而上，$w一旋，一招仿佛泰山剑法的"+(order[random(13)])+"「来鹤清泉」"NOR"直刺$n
的$l！",
	"lvl" : 0,
	"skill_name" : "来鹤清泉"
]),
([	"action" : "$N奇诡地向$n挥出"+(order[random(13)])+"「泉鸣芙蓉」"NOR"、"+(order[random(13)])+"「鹤翔紫盖」"NOR"、"+(order[random(13)])+"「石廪书声」"NOR"、"+(order[random(13)])+"「
天柱云气」"NOR"及"+(order[random(13)])+"「雁回祝融」"NOR"衡山五神剑！",
	"lvl" : 10,
	"skill_name" : "衡山五神剑"
]),
([
	"action" : "$N剑随身转，续而刺出十九剑，竟然是华山"+(order[random(13)])+"「玉女十九剑」"NOR"，但奇的
是这十九剑便如一招，手法之快，直是匪夷所思！",
	"lvl" : 20,
	"skill_name" : "玉女十九剑"
]),
([	"action" : "$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢慢
推去！",
	"lvl" : 30,
	"skill_name" : "恒山剑法"
]),
([	"action" : "$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，实人所难测！",
	"lvl" : 40,
	"skill_name" : "神剑之威"
]),
([	"action" : "$N吐气开声，一招似是"+(order[random(13)])+"「独劈华山」"NOR"，手中$w向下斩落，直劈向$n的
$l！",
	"lvl" : 50,
	"skill_name" : "独劈华山"
]),
([	"action" : "$N含笑抱剑，气势庄严，$w轻挥，尽融"+(order[random(13)])+"「达摩剑」"NOR"为一式，闲舒地刺
向$n！",
	"lvl" : 60,
	"skill_name" : "达摩剑"
]),
([	"action" : "$N神声凝重，$w上劈下切左右横扫，挟雷霆万钧之势逼往$n，"+(order[random(13)])+"「伏摩
剑」"NOR"的剑意表露无遗！",
	"lvl" : 70,
	"skill_name" : "伏摩剑"
]),
([	"action" : "却见$N突然虚步提腰，使出酷似武当"+(order[random(13)])+"「蜻蜓点水」"NOR"的一招！",
	"lvl" : 80,
	"skill_name" : "蜻蜓点水"
]),
([	"action" : "$N运剑如风，剑光霍霍中反攻$n的$l，尝试逼$n自守，剑招似是"+(order[random(13)])+"「伏
魔剑」"NOR"的"+(order[random(13)])+"「龙吞式」"NOR"。",
	"lvl" : 90,
	"skill_name" : "龙吞式"
]),
([	"action" : "$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什
么剑法！",
	"lvl" : 100,
	"post_action" : (: action_busy :),
	"skill_name" : "杂乱无章"
]),
([	"action" : "$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，迫
得$n不得不守！",
	"lvl" : 110,
	"post_action" : (: action_parry :),
	"skill_name" : "大开大阖"
]),
([	"action" : "$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力竟然奇大，$n
难以看清剑招来势！",
	"lvl" : 120,
	"post_action" : (: action_dodge :),
	"skill_name" : "有招似无招"
]),
([	"action" : "$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么招
式。",
	"lvl" : 130,
	"post_action" : (: action_busy :),
	"skill_name" : "举剑狂挥"
]),
([	"action" : "$N突然运剑如狂，一手关外的"+(order[random(13)])+"「乱披风剑法」"NOR"，猛然向$n周身乱刺乱
削！",
	"post_action" : (: action_damage :),
	"lvl" : 140,
	"skill_name" : "乱披风剑法"
]),
([	"action" : "$N满场游走，东刺一剑，西刺一剑，令$n莫明其妙，分不出$N剑法的
虚实！",
	"lvl" : 150,
	"post_action" : (: action_dodge :),
	"skill_name" : "莫明其妙"
]),
([	"action" : "却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，竟
化"+(order[random(13)])+"「泰山十八盘」"NOR"为一剑攻向$n！",
	"lvl" : 160,
	"post_action" : (: action_damage :),
	"skill_name" : "泰山十八盘"
]),
([	"action" : "$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不知
如何是好！",
	"post_action" : (: action_busy :),
	"lvl" : 170,
	"skill_name" : "暗藏无数"
]),
([	"action" : "$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向$n
的$l！",
	"post_action" : (: action_parry :),
	"lvl" : 180,
	"skill_name" : "突现笑容"
]),
([	"action" : "$N手中$w越转越快，使的居然是衡山的"+(order[random(13)])+"「百变千幻云雾十三式」"NOR"，剑
式有如云卷雾涌，旁观者不由得目为之眩！",
	"lvl" : 190,
	"post_action" : (: action_dodge :),
	"skill_name" : "百变千幻云雾十三式"
]),
([	"action" : "$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里
，尽括嵩山剑势击向$n的$l！",
	"lvl" : 200,
	"post_action" : (: action_damage :),
	"skill_name" : "长枪大戟"
]),
([	"action" : "$N举起$w运使"+(order[random(13)])+"「太极剑」"NOR"剑意，划出大大小小无数个圆圈，无穷无尽
源源不绝地缠向$n！",
	"post_action" : (: action_busy :),
	"lvl" : 210,
	"skill_name" : "太极剑"
]),
([	"action" : "$N剑招突变，使出衡山的"+(order[random(13)])+"「一剑落九雁」"NOR"，削向$n的$l，怎知剑到中
途，突然转向，大出$n意料之外！",
	"lvl" : 220,
	"post_action" : (: action_parry :),
	"skill_name" : "一剑落九雁"
]),
([	"action" : "$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可
思议！",
	"post_action" : (: action_po :),
	"lvl" : 230,
	"skill_name" : "神妙无伦"
]),
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
//	int f_e1 = 150;
//	int f_e2 = 230;
//	int m_e1 = 220;
//	int m_e2 = 320;
	int f_e1 = 230;
	int f_e2 = 150;
	int m_e1 = 320;
	int m_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("lonely-sword", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	seq = random(seq);       /* 选择出手招数序号 */
	if (!userp(me) || me->query("family/master_id")== "feng qingyang" )
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"post_action" : action[seq]["post_action"],
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "割伤" : "刺伤",
	]);
  else	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
//		"post_action" : action[seq]["post_action"],
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "割伤" : "刺伤",
	]);
}


int action_damage(object me, object victim, object weapon, int damage)
{
       	string msg;
        string *limbs=victim->query("limbs");
        int dam;
        int skill= me->query_skill("lonely-sword", 1);
        if (!me->is_fighting(victim)) return 0;
	      if( damage == RESULT_DODGE && !victim->is_busy()
	            && skill > 100
	            && me->query("neili") > 100
	            && random(skill) > victim->query_skill("force",1)/2 ) //躲过
        {
        	me->add("neili",-50);
        	message_combatd("\n$N一声长啸:"HIW"「剑旋离身，剑啸震山河」"NOR", 瞬间剑芒大作,朝$n激射而至！\n",me,victim);
          dam = skill*2 + me->query_temp("apply/damage");
          dam -= victim->query_temp("apply/armor");
          if (dam < 0 ) dam = 0;
          victim->receive_damage("qi",dam);
          msg = damage_msg(dam, "刺伤"); //此次伤害
          msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
          msg = replace_string(msg, "$w", weapon->query("name"));
          message_combatd(msg,me,victim);
          COMBAT_D->report_status(victim);
          return 1;
        }
        else if (  damage > 0 && !victim->is_busy()
	            && skill > 100
	            && me->query("neili") > 100
	            && random(skill) > victim->query_skill("force",1)/4)   //打中对方
        {
        	me->add("neili",-50);
          message_combatd("\n$N突然悟出"HIW"「练精化气, 练气化神, 练神还虚」"NOR"之真理, 手中长剑突然消失, 朝$n飞至！\n",me,victim);
          dam = skill + me->query_temp("apply/damage");
          dam -= victim->query_temp("apply/armor");
          if (dam < 0 ) dam = 0;
          victim->receive_damage("qi",dam);
          msg = damage_msg(skill*2, "刺伤"); //此次伤害
          msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
          msg = replace_string(msg, "$w", weapon->query("name"));
          message_combatd(msg,me,victim);
          COMBAT_D->report_status(victim);
        	return 1;
        }
        return 1;

}

int action_po(object me, object victim, object weapon, int damage)
{
	// 破对方武功、内功  为终极效果
	      int skill= me->query_skill("lonely-sword", 1);
        string v_force = victim->query_skill_mapped("force");
        int jiali;
        if (!me->is_fighting(victim)) return 0;
	      if (damage > 0)// 打中对方 破内功 或者破内力
	      {
	      	if (v_force && skill > 250 
	      	   && random(skill/2) > random(victim->query_skill("force"))  
	      	   && random(skill) > 200 
	      	   && victim->query_map_skill("force") 
	      	   && random(3)==1 )
	      	{
	      		me->add("neili",-100);
	      		victim->map_skill("force");
            message_combatd(HIC "$N一剑得手，剑招源源而出，剑尖直刺$n丹田！\n",me,victim);
            message_combatd(RED "$n只觉混身如遭电击，真气劲力紊乱难控，已然不能施展"+to_chinese(v_force)+"！\n" NOR,me,victim);
	        return 1;
	        }
	        else if (random(me->query_skill("lonely-sword",1)) > 100 &&
          random(me->query_skill("sword",1))>100 &&
         	me->query_skill("force",1) > 120
      	  && !victim->is_busy() )	
          {
          	me->add("neili",-50);
            if (victim->query("neili")>600)
               victim->add("neili", -500);
            else
               victim->set("neili",0);
          message_combatd(HIC "\n$N一剑得手，剑招源源而出，欲将$n团团困住！\n",me,victim);
          message_combatd(HIM "$n急运内力，使出浑身解数，方才脱出剑圈！\n"NOR , me, victim);
          return 1;
          }        
	      }
        else if( damage == RESULT_DODGE && !victim->is_busy()) //躲过  震慑对方
        {
        	me->add("neili",-50);
        	message_combatd(HIY "$n只觉$N剑中暗藏无数玄机，稍一胆怯，不敢攻上前去！\n"NOR,me,victim);
          victim->start_busy(1+random(skill/50));
        	return 1;
        }
        else if ( damage == RESULT_PARRY ) //对手招架住 可顺势再创对手
        {
        	jiali = me->query("jiali");
          if (!jiali) jiali=10;
	        if( random(skill)>140 )
	        {
	        	me->add("neili",-50);
            message_combatd(HIC "$N相交一招，已然看破$n武功套路，胸有成竹地刺出一剑!\n",me,victim);
	          victim->receive_wound("qi", (random(jiali)*2+100));
	          message_combatd(HIM"$N剑气纵横! 一道剑气划过了$n的胸口。结果鲜血狂喷!\n"NOR,me,victim);
            COMBAT_D->report_status(victim,1);
           }
        	return 1;
        }
        return 1;
	
}
int action_busy(object me, object victim, object weapon, int damage)
{
	      int skill=me->query_skill("lonely-sword",1);
        if (!me->is_fighting(victim)) return 0;
        if( damage <= 0 && !victim->is_busy() 
            && skill > 100
            && me->query("neili") > 100
            && random(me->query("combat_exp")) > victim->query("combat_exp")/3 ) //威力极小,如果没有上两个 则包括躲过和招架
        {
         me->add("neili",-50);
         message_combatd("$N顿然领悟了"HIW"「剑在神先, 绵绵不绝」"NOR"之真意, 剑尖瞬间爆出无数大大小小,\n正反斜直各种各样的圆圈, 将$n团团困住。\n",me,victim);
         victim->start_busy(2+random(skill/50));
       	return 1;
        }
	      else if (damage > 0  && !victim->is_busy() 
          && skill > 100
	        && random(skill) > victim->query_skill("force",1)/3)
	      {
	      	  me->add("neili",-30);
	         	message_combatd(CYN"$N以意驭剑，画出数个"RED"圆圈"CYN"，左右兼顾，将$n缠在正中！\n" NOR,me,victim);
		        victim->start_busy(1+random(skill/50));
	      }
	      return 1;
}

int action_dodge(object me, object victim, object weapon, int damage)
{
	      int skill=me->query_skill("lonely-sword",1);
	      string msg;
        string *limbs=victim->query("limbs");
        if (!me->is_fighting(victim)) return 0;
        if (random(me->query_skill("lonely-sword",1)) >= 200 &&
            random(me->query_skill("sword",1))>180 &&
          	me->query_skill("force",1) >= 200 &&
          	victim->query_map_skill("dodge")
           	)
       {
          me->add("neili", -50);
          victim->map_skill("dodge");
         if( !victim->is_busy() )
         {
           victim->start_busy(random(3)+1);
         }
         msg = HIC "\n$N突然举剑一刺，剑招随便无章，却莫明奇妙地突破了$n的攻势，大出$n意料！\n" ;
         msg += HIR"$n大吃一惊，竟然忘了闪避！\n"NOR;
         message_combatd(msg,me,victim);
         return 1;
       }
	     else if (damage <= 0 && random(skill) > random(victim->query_skill("dodge",1)/3))
       {          
          me->add("neili", -50);
  	      message_combatd("\n却见$N飘身而上，半空中举剑上挑，剑光已封住了$n身周数尺之地，攻得精巧无比！\n",me,victim);
  	      victim->receive_damage("qi",skill/2);
          msg = damage_msg(skill/2, "刺伤");
          msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
          msg = replace_string(msg, "$w", weapon->query("name"));
          message_combatd(msg,me,victim);
          COMBAT_D->report_status(victim);
          return 1;
       }
       return 1;
}

int action_parry(object me, object victim, object weapon, int damage)
{
	     int skill=me->query_skill("lonely-sword",1);
       string msg;
       string *limbs=victim->query("limbs");
        if (!me->is_fighting(victim)) return 0;
       if (damage == RESULT_DODGE &&
           random(me->query_skill("lonely-sword",1)) > 140 &&	
	         random(me->query_skill("sword",1))>140 &&
           me->query_skill("force",1) >= 200 &&
          	victim->query_map_skill("parry")
           )	
         {
           me->add("neili", -50);
           victim->map_skill("parry");
           if( !victim->is_busy() )
           {
             victim->start_busy(random(2)+1);
           }
           msg = HIC "\n$N举剑反攻，后发先至地刺向$n，不仅把$n招术封死，更进一步发出攻击！\n" NOR;
           msg += HIY"$n难以看清剑招来势,竟然忘了招架！\n"NOR;
           message_combatd(msg,me,victim);
        }
	      else if (damage <= 0 && random(skill) > random(victim->query_skill("parry",1)/3))
       {
          me->add("neili", -50);
        	msg = "\n$N一个箭步纵到$n身前，手腕微颤，挥剑斜撩，横削$n$l，剑法极尽灵动轻捷\n";
  	      victim->receive_damage("qi",skill/2);
          msg += damage_msg(skill/2, "刺伤"); //此次伤害
          msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
          msg = replace_string(msg, "$w", weapon->query("name"));
          message_combatd(msg,me,victim);
          COMBAT_D->report_status(victim);
       }
}
//被击中效果
mixed be_hit_ob(object me, object ob, int damage, int factor)
{
		   object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        if ((int)me->query("qi")>1 && (int)me->query("eff_qi")>1)
            i = (int)me->query("eff_qi") / (int)me->query("qi") + 1;
        else i=1;
        if ( i > 5 ) i = 5;
        limbs = ob->query("limbs");
        level = me->query_skill("lonely-sword", 1);

//        if( me->is_busy()) return 0;
        if( damage < 100 ) return 0;
        if ( living(me) 
         && !me->query_temp("noliving")
         && random(level) > 100 /i 
         && me->query_skill_mapped("sword") =="lonely-sword"
         && me->query_skill_mapped("parry") =="lonely-sword"
         && weapon
         && weapon->query("skill_type") == "sword"
         && me->query_skill("sword") > 300
         && random(me->query_skill("sword",1)) > 150
         && me->query("neili") > 200 
         && me->query("max_neili") >= 3000
         && random(me->query_int()) >= 20 ){
            me->add("neili", -100);
            msg = HIW"$N行动不便，知道这一招无可躲避，当即挺剑刺出，后发先至，噗的一声刺向$n的咽喉。\n"NOR;
            if ( random(level) > ob->query_skill("dodge", 1) / i){
             q = damage * i ;
             if ( q > 3500 ) q = 3500 + ( q - 3500 )/ 100;
             ob->receive_damage("qi", q);
             ob->receive_wound("qi", q/3);
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
     //        if ( random(me->query("combat_exp")) > ob->query("combat_exp") / i)
             p = ob->query("qi")*100/ob->query("max_qi");
             msg += damage_msg(q, "刺伤") + "( $n"+status_msg(p)+" )\n";
             msg = replace_string(msg, "$l", "喉咙");
             msg = replace_string(msg, "$w", weapon->query("name"));
           //  j = -(damage/2+random(damage/2));
             j = 0;
            }
            else {
              dodge_skill = ob->query_skill_mapped("dodge");
              if( !dodge_skill ) dodge_skill = "dodge";
              msg += SKILL_D(dodge_skill)->query_dodge_msg(ob);
              j = -damage/4; 
            }
            message_combatd(msg, me, ob);
            return j;
        }
}

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

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

