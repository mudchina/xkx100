inherit F_CONDITION;

#include <vote.h> 
#include <ansi.h>



int clear_vote(object me);

int vote(object me, object victim)
{
  int reason;   // vote for what?
  int vv;	// valid voter numbers
  int vc; 	// vote count;
  int df;
  int i;
  string *juror, *ips, my_id;

  if (me == victim)
  {
	if (random(2)) me->add("vote/abuse", 10);
  	return notify_fail("你不是开玩笑吧？当心被剥夺表决权！\n");
  }

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_CHBLK))
  {
  	return notify_fail("要把当前的表决完成以后才可以提新的动议。\n");
  }

  if( victim->query("chblk_on") ) 
  {
  	return notify_fail(victim->name()+"的交谈频道已经是关闭的了。\n");
  }

  if (reason <= 0)
  {
  	victim->set("vote/reason", (int)V_CHBLK); 
  }
  
  my_id = query_ip_name(me);

  // don't allow me to vote twice for the same issue
  juror = victim->query("vote/juror");
  
  if( !pointerp(juror) )
  {
 	juror = victim->set("vote/juror", ({ my_id }) );
  } else if( member_array(my_id, juror) == -1 || wizardp(me)) 
  {
 	juror = victim->add("vote/juror", ({ my_id }) );
  } else
  {
  	me->add("vote/abuse", 10);
  	return notify_fail("一人一票！滥用表决权是要受惩罚的！\n");
  }

/*  vv = (int) ("/cmds/std/vote")->valid_voters(me)/2;  
  vc = victim->add("vote/count", 1);

  df = (int)((vv - vc)/2);
  if (vv < 4) df = 4 - vc;*/
  ips = ("/cmds/std/vote")->valid_voters(me);
  vv = sizeof(ips);
  for (i=0;i<sizeof(juror);i++)
  {
  	if (member_array(juror[i],ips)==-1)
  	 vc = victim->add("vote/count",-1);
  }
  vc = victim->add("vote/count", 1);

  df = vv - vv/2 - vc;
  if (vv < 8) df = 4 - vc;

  if (df>0)
  {
	shout( HIG "【表决】"+me->name()+"投票关闭" +victim->name()
			+"的交谈频道，还差"+sprintf("%d", df)+"票。\n" NOR);
	write( HIG "【表决】"+me->name()+"投票关闭" +victim->name()
			+"的交谈频道，还差"+sprintf("%d", df)+"票。\n" NOR);
	victim->apply_condition("vote_clear", 10);
  } else 
  {
	shout( HIG "【表决】"+me->name()+"投票关闭" +victim->name()
			+"的交谈频道。"+victim->name()+"的交谈频道被关闭了！\n" NOR);
	write( HIG "【表决】"+me->name()+"投票关闭" +victim->name()
			+"的交谈频道。"+victim->name()+"的交谈频道被关闭了！\n" NOR);
			
	victim->apply_condition("vote_clear", -10);
	
	victim->set("chblk_on", 1);
	victim->delete("vote/juror");
		/* if (victim->query("chblk_rumor")) victim->delete("chblk_rumor");
	if (victim->query("chblk_chat")) victim->delete("chblk_chat"); */
  } 
  
  return 1;
}


