// perform.c
// modified by sega 99/1/16
// 添加比武perform限制，参考/d/city/npc/referee.c modified by sega 2000/02/05
// 斗转星移
// hubo出双重pfm by qingyun 04/9/25
//inherit F_CLEAN_UP;lijia
inherit F_SSERVER;

#include <ansi.h>


string *prep_skl = ({"finger","hand","cuff","claw","strike","unarmed","leg"});
private int do_perform(object me, string arg);

int main(object me, string arg)
{
	string and;//第二个pfm
	int result;
  int busy;
  int lvl;
  int suc;
  string msg="\n";
	object target;
	seteuid(getuid());

	if( me->is_busy() )
			return notify_fail("( 你上一个动作还没有完成，不能施用外功。)\n");
//	if ( environment(me)->is_chat_room())
//      return notify_fail("这里禁止打斗。\n");
	if( !living(me) || me->query_temp("noliving") )
			return notify_fail("你行将晕倒，无法施用外功。\n");
	if (me->query("jing") < 0 || me->query("qi") < 0)
			return notify_fail("你行将晕倒，无法施用外功。\n");
	if( me->query_temp("bixie/ciwan") )
			return notify_fail("你的手腕受伤，不能施用外功。\n");
	if( me->query_temp("dagou/feng") )
			return notify_fail("你的招式被打狗棒封住，不能施用外功。\n");
	if( !arg ) 
			return notify_fail("你要用外功做什么？\n");
  if (me->query_temp("no_perform"))
    	return notify_fail(HIR "你只觉全身力道竟似涣散了一般，全然无法控制。\n" NOR);

//比武perform限制
	
	if (me->query_temp("biwu/perform_time"))
	{
		if (time()-(int)me->query_temp("biwu/perform_time")<8+random(3))
	 	{
			me->start_busy(1+random(2));
			if (target = offensive_target(me))
			{
				message_combatd(HIY"$P刚要使出本门绝技，不想 $p早有准备，先发制人，一阵急攻令$P手忙脚乱。\n"NOR,me,target);
				if (!target->is_busy())
					COMBAT_D->do_attack(target,me,target->query_temp("weapon"), 0);
			}
			return 1;
		}
		write("呵呵。\n");
		me->set_temp("biwu/perform_time",time());
	}
	//判断开始出pfm
/////////add from here/////////////////
  if (sscanf(arg, "%s and %s", arg, and) == 2)
      {
       lvl = me->query_skill("hubo", 1);
       if (! lvl)
       		return notify_fail("你要干什么？以为自己有三头六臂啊！\n");

       if (me->query_skill("qimen-wuxing", 1))
          return notify_fail("你杂学太多，心头烦乱，难以分心二用。\n");
       if (lvl <= 100)
          return notify_fail("你的左右互搏修为太浅，难以分心二用。\n");
       if (! me->is_fighting())
          return notify_fail("只有战斗中才能施展左右互搏。\n");
       if (lvl < 250 && random(lvl) < 70)
          {
          me->start_busy(2);
          message_combatd("$N试图分心二用，但是手就是不听使唤。\n",me);
          return 1;
          }
       }
       result = do_perform(me, arg);//出一招pfm
	if (me->query_temp("murong/xingyi")) me->delete_temp("murong/xingyi");
       if (! and || (me->query("int")>=25 && random(lvl)<150))
            return result; //如果没有第二招 那么结束
        if (! result)
//						write(me->query_temp("notify_fail"));
//呜呜 没有query_notify_fail()这个函数  只好用自己的描述了
				  message_combatd(HIY"$N招式未老，身形斗转，忽然变招。\n\n"NOR, me);
        else
        {
          switch (random(4))
          	    {
               case 0:
                        msg += HIY "$N" HIY "大喝一声，双手分"
                              "使两招，一起攻出。\n" NOR;
                        break;

                case 1:
                        msg += HIY "$N" HIY "双手齐出，分使不"
                              "同招式，令人眼花缭乱。\n" NOR;
                        break;

                case 2:
                        msg += HIY "$N" HIY "左右手分使两招，"
                              "毫不停滞，宛如两人同时攻出。\n" NOR;
                        break;

                case 3:
                        msg += HIY "$N" HIY "左手一招，右手一"
                              "招，两招来路各异，令人难以低档！\n" NOR;
                        break;
                }
								msg += "\n";
                message_combatd(msg, me);
        }
//from here
//怎么处理的两次的busy? 
//        busy = me->query_busy();
//        me->interrupt_busy(0);
//        if (intp(busy) && intp(me->query_busy()) &&
//            busy > me->query_busy())
//        {
//                me->interrupt_busy(0);
//               me->start_busy();
//       }
        result = do_perform(me, and); //出第二招pfm
	if (me->query_temp("murong/xingyi")) me->delete_temp("murong/xingyi");
				return result;
//        if (! result)
//						return 0;
//                write(query_notify_fail());

//        return 1;
/////////add finish///////////////
}
private int do_perform(object me, string arg)
{	
	object weapon, target;
	string martial, skill,pfarg, uarg, parg;
	int result,i,j,ap,dp,plvl,xlvl;

	object tweapon;
	mapping skl, pre_skl;
	string *sskl, *file, skname, sktype, skpf, msg;
	target = offensive_target(me);
	if( sscanf(arg, "%s.%s", martial, arg)!=2 )
	{
		if( weapon = me->query_temp("weapon") )
			martial = weapon->query("skill_type");
		else martial = "unarmed";
	}
/*
	if ( userp(me) )
	     if( !wizardp(me) )
	{
		if( sscanf(arg, "%s %s", parg, uarg)==2 )
		{
			pfarg = "perform/" + parg;
			if( me->query(pfarg,1)<1 )
				return notify_fail("你必须先向贵派掌门请教如何运用这门外功。\n");
		}
//		else if( sscanf(arg, "%s.%s", martial, parg)==2 )
//		{
//			pfarg = "perform/" + parg;
//			if( me->query(pfarg,1)<1 )
//				return notify_fail("你必须先向贵派掌门请教如何运用这门外功。\n");			
//		}
		else 
		{
			pfarg = "perform/" + arg;
			if( me->query(pfarg,1)<1 )
				return notify_fail("你必须先向贵派掌门请教如何运用这门外"+arg+"。\n");
		}		
	}*/
	if (!stringp(me->query_skill_mapped("force")))
		return notify_fail("没有任何内功做为基础，是发挥不出招式威力的。\n");
	if( martial == "parry" && arg != "xingyi")
		return notify_fail( "不能用基本招架出手外功。\n");
	if( !me->query_temp("weapon") && martial!="unarmed" &&
		martial!="parry" && martial!="dodge")
	{
		pre_skl = me->query_skill_prepare();
		if( !pre_skl ) 
			return notify_fail( "请先用 prepare 指令准备你要使用的外功。\n");
		else
		{
			sskl = keys(pre_skl);
			j = 0;
			for( i=0; i<sizeof(sskl); i++)
				if( martial == sskl[i]) j=1;
			if( j == 0)
				return notify_fail( "你只能使用已经用 prepare 指令准备好的武功的外功。\n");
		}
	}
/* 以下是正常出手 */
	if( me->query_temp("lonely-sword/pozhang") && 
	member_array(martial,prep_skl)!=-1 )
			return notify_fail(HIR"你的手掌受伤，手里使不上劲。\n"NOR);
	if (arg != "xingyi")
	{
		if( stringp(skill = me->query_skill_mapped(martial)) )
		{
			notify_fail("你所使用的外功中没有这种功能。\n");
			if( SKILL_D(skill)->perform_action(me, arg) )
			{
				if( random(120) < (int)me->query_skill(skill) )
					me->improve_skill(skill, 1, 1);
				return 1;
			} else
				if( SKILL_D(martial)->perform_action(me, arg) )
				{
					if( random(120) < (int)me->query_skill(martial, 1) ) me->improve_skill(martial, 1, 1);
					return 1;
				}
				return 0;
		}
		return notify_fail("请先用 enable 指令选择你要使用的外功。\n");
	}
/* 以下为斗转星移 */
	else
	{
		me->clean_up_enemy();
		target = me->select_opponent(); 

		if (martial != "parry" ||
			me->query_skill_mapped("parry") != "douzhuan-xingyi")
			return notify_fail("你所使用的外功中没有这种功能。\n");
		if (me->query("neili") < 500)
			return notify_fail("你内力不够，不能使用「星移」！\n");
		plvl = me->query_skill("parry",1);
		if( plvl < 120)
			return notify_fail("基本招架未熟练，怎能「星移」？\n");
		xlvl = me->query_skill("douzhuan-xingyi",1);
		if( xlvl < 120)
			return notify_fail("斗转星移不熟练，无法「星移」！\n");
		if( me->query_skill("shenyuan-gong",1) < 120)
			return notify_fail("神元功不精熟，也无法「星移」！\n");
		if( !(me->is_fighting() ))
			return notify_fail("「星移」只能在战斗中使用。\n");

		target = offensive_target(me);
		if( !target->is_character() )
			return notify_fail("看清楚一点，那并不是生物。\n");
		if (!living(target) || target->query_temp("noliving") )
			return notify_fail(target->name()+ "已经没知觉了，你用不了对方的力道了。\n"); 

		msg = HIG"$N运起神元功，一口真气自丹田猛地提了上来！\n"NOR;
		message_combatd(msg,me,target);
/* 出手有兵器，则使用其兵器的perform */
		if( objectp(weapon = me->query_temp("weapon")))
		{
			sktype = weapon->query("skill_type"); 
			if( !objectp(tweapon = target->query_temp("weapon")) ||
				sktype != tweapon->query("skill_type") ) 
					return notify_fail(HIR"你和"+target->query("name")+"没有持相同类型的兵器，没法「星移」。\n"NOR); 
			else
			{
				if( me->query_skill(sktype,1) < 120) 
					return notify_fail(HIR"你的"+to_chinese(sktype)+"修为太浅，没法使用「星移」。\n"NOR); 
				skname = target->query_skill_mapped(sktype);
				if( skname == "murong-sword" ||
					skname == "murong-blade")
					return notify_fail(HIR+target->query("name")+"深谙慕容世家的功夫，你没法使用「星移」。\n"NOR); 
				if(!file = get_dir("/kungfu/skill/"+skname+"/"))
					return notify_fail(HIR+target->query("name")+"目前使的武功没有绝招，没法「星移」。\n"NOR); 
				skpf = file[random(sizeof(file))];

				ap=random(plvl/2)+xlvl/2;
				dp=target->query_skill("parry") / 2;
				if(dp < 1) dp = 1; 
				if (strsrch(skpf, ".c") >= 0 && ap > dp)
				{
					skpf=replace_string(skpf,".c","");
					msg = HIY "$N使出斗转星移的绝招"HIR"  「星移」  "HIY"，用$n"HIY"的"+to_chinese(skname)+"的绝招更快、更狠地出手！\n"NOR;
					message_combatd(msg, me, target);
/* 星移的标志 */
					me->set_temp("murong/xingyi", 1);
					if( SKILL_D(skname)->perform_action(me, skpf) )
					{
						result = 1;
//						me->start_busy(random(2)+1);
					}
					else
					{
						result = 0;
						msg = HIG"$N一时没捉摸到$n出手时的力道所在，使出「星移」落在了空处！\n"NOR;
						message_combatd(msg,me,target);
					}
					me->delete_temp("murong/xingyi");
				}
				else
				{
					result = 1;
					msg = HIG"$N真气流转不顺，一时无法使出「星移」！\n"NOR;
					message_combatd(msg,me,target);
				}
				return result;
			}
		}
		else
/* 你没有兵器 */
		{
			if( objectp(tweapon = target->query_temp("weapon")))
				return notify_fail(HIR"你和"+target->query("name")+"没有持相同类型的兵器，没法「星移」。\n"NOR); 
			else
			{
				if( !mapp(pre_skl = target->query_skill_prepare()) || !sizeof(pre_skl))
					sktype = "unarmed";
  			else sktype = keys(pre_skl)[random(sizeof(pre_skl))];
				
				if( me->query_skill(sktype, 1) < 120) 
					return notify_fail(HIR"你的"+to_chinese(sktype)+"修为太浅，没法使用「星移」。\n"NOR); 

				skname = target->query_skill_mapped(sktype);
				if( skname == "xingyi-strike" ||
					skname == "canhe-finger")
					return notify_fail(HIR+target->query("name")+"深谙慕容世家的功夫，你没法使用「星移」。\n"NOR); 
/* 对方徒手没有perform */
				if(!file = get_dir("/kungfu/skill/"+skname+"/"))
				{
					msg = HIG"$N运起斗转星移，真气流动加快，出手陡然加快！加重！！\n"NOR;
					message_combatd(msg,me,target);
					me->add_temp("apply/attack", 20);
					me->add_temp("apply/dodge", 10);
					me->add_temp("apply/defense", 10);
					COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
					COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
					me->add_temp("apply/attack", -20);
					me->add_temp("apply/dodge", -10);
					me->add_temp("apply/defense", -10);
					me->start_busy(random(3)+1);
					return 1;
				}
				skpf = file[random(sizeof(file))];

				ap=random(plvl/2)+xlvl/2;
				dp=target->query_skill("parry") / 2;
				if(dp < 1) dp = 1; 
				if (strsrch(skpf, ".c") >= 0 && ap > dp)
				{
					skpf=replace_string(skpf,".c","");
					msg = HIY "$N使出斗转星移的绝招"HIR"  「星移」  "HIY"，用$n的"+to_chinese(skname)+"的绝招更快、更狠地出手！\n"NOR;
					message_combatd(msg, me, target);
/* 星移的标志 */
					me->set_temp("murong/xingyi", 1);
					if( SKILL_D(skname)->perform_action(me, skpf) )
					{
						result = 1;
//						me->start_busy(random(2)+1);
					}
					else
					{						
						result = 0;
						msg = HIG"$N一时没捉摸到$n出手时的力道所在，使出「星移」落在了空处！\n"NOR;
						message_combatd(msg,me,target);
						return 0;
					}
					me->delete_temp("murong/xingyi");
				}
				else
				{
					result = 1;
					msg = HIG"$N真气流转不顺，一时无法使出「星移」！\n"NOR;
					message_combatd(msg,me,target);
				}
				return result;
			}
		}
		me->start_busy(random(2)+1);
		me->delete_temp("murong/xingyi");
		return 1;
	}
}
int help (object me)
{
	write(@HELP
指令格式：perfrom | yong [<武功种类>.]<招式名称> [<施用对象>]
          perform | yong 招式1 [<对象1>] and 招式2 [<对象2>]

    如果你所学的外功（拳脚、剑法、刀法....）有一些特殊的攻击方
式或招式，可以用这个指令来使用，你必须先用 enable 指令指定你使
用的武功，不指定武功种类时，空手的外功是指你的拳脚功夫，使用武
器时则是兵刃的武功。空手外功的施展，必须先准备好 （prepare）你
的技能。有的特别的外功可以激发相应技能为parry来施展。

    若是你的外功中有种类不同，但是招式名称相同的，或者不属於拳
脚跟武器技能的武功(如轻功)，可以用 <武功>.<招式>  的方式指定，
如：

    perform sword.chan
    perform sword.chan and sword.lian

    换句话说，只要是 enable 中的武功有特殊招式的，都可以用这个
指令使用。很多武功的特殊攻击法都非常凌厉，一旦使用，将招致对方
的拼死反击，就是说，被攻击方将自动开始ｋｉｌｌ你。所以要谨慎使
用哦:)。

如果你精通左右互搏，可以同时使用两个招式攻击同一对手或则分别
攻击两人。左右互搏修炼的越是精深，则成功率越高。

HELP
	);
	return 1;
}
