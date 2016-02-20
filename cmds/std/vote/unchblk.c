inherit F_CONDITION;

#include <vote.h> 
#include <ansi.h>
#include <net/dns.h>



string *blocks_name = ({
	"rumor",
	"chat",
	"xkx",
	"sing",
	"party",
});

int clear_vote(object victim);

int vote(object me, object victim)
{
  int reason;   // vote for what?
  int vv;	// valid voter numbers
  int vc; 	// vote count;
  int df;
  int i;
  string channel;
  string *juror, my_id ,*ips;
  string my_name, v_name;

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_UNCHBLK))
  {
  	return notify_fail("要把当前的表决完成以后才可以提新的动议。\n");
  }

  if ( !victim->query("chblk_on"))
  	return notify_fail(victim->name()+"的交谈频道已经是打开的了。\n");

  if (reason <= 0)
  {
  	victim->set("vote/reason", (int)V_UNCHBLK); 
  }
  
  //my_id = me->query("id");
  my_id = query_ip_name(me);

  // dont allow me to vote twice for the same issue
  juror = victim->query("vote/juror");
  
  if( !pointerp(juror) )
  {
 	victim->set("vote/juror", ({ my_id }) );
  } else if( member_array(my_id, juror) == -1 || wizardp(me)) 
  {
 	victim->set("vote/juror", juror+({ my_id }) );
  } else
  {
	me->add("vote/abuse", 10);
  	return notify_fail("一人一票！滥用表决权是要受惩罚的！\n");
  }

/*  vv = (int) ("/cmds/std/vote")->valid_voters(me)/3;  
  vc = victim->add("vote/count", 1);

  df = (int)((vv - vc)/2);
  if (vv < 4) df = 4 - vc;
*/
  ips = ("/cmds/std/vote")->valid_voters(me);
  vv = sizeof(ips);
  for (i=0;i<sizeof(juror);i++)
  {
  	if (member_array(juror[i],ips)==-1)
  	 vc = victim->add("vote/count",-1);
  }
  vc = victim->add("vote/count", 1);

  df = vv - vv*2/3 - vc;
  if (vv < 8) df = 4 - vc;
    
  my_name = me->name();
  if (me == victim) v_name = "自己";
  	else  v_name = victim->name();

  if (df>0)
  {
	shout( HIG "【表决】"+my_name+"投票打开" +v_name +"的交谈频道，还差"
			+sprintf("%d", df)+"票。\n" NOR);
	write( HIG "【表决】"+my_name+"投票打开" +v_name +"的交谈频道，还差"
			+sprintf("%d", df)+"票。\n" NOR);
    
	victim->apply_condition("vote_clear", 10);
			        
  } else 
  {
  	if (me != victim)
  	{
	shout( HIG "【表决】"+my_name+"投票打开" +v_name+"的交谈频道。"
		+v_name+"的"+channel+"频道被打开了！\n" NOR);
	write( HIG "【表决】"+my_name+"投票打开" +v_name+"的交谈频道。"
		+v_name+"的"+channel+"频道被打开了！\n" NOR);
	} else 
	{
	shout( HIG "【表决】"+my_name+"投票打开自己的交谈频道。"
		+my_name+"的"+channel+"频道被打开了！\n" NOR);
	write( HIG "【表决】"+my_name+"投票打开自己的交谈频道。"
		+my_name+"的"+channel+"频道被打开了！\n" NOR);
	}		
	
	victim->apply_condition("vote_clear", -10);
	victim->delete("vote/juror");
	victim->delete("chblk_on");
	for (i = 0;i < sizeof(blocks_name);i ++)
		victim->delete("chblk_" + blocks_name[i]);
} 
  
  return 1;
}


