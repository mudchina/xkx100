// /cmds/std/sleep.c
// Dec.11 1997 by Venus
// Modified by Zeratul Jan 11 2001 记录夫妻上次交流时间
//第60行注意了：ahda
//Modified by Qingyun 2004.9.30 调整睡觉时间长度、把baby改成condition怀孕

#include <ansi.h>
#include <command.h>
void wakeup(object me, object where);
int wakeup2(object me,object slept,object where);
void del_sleeped(object me);

int main(object me, string arg)
{
	object obj, old_target;
	int i,sleeptime;
	object *inv;
	mapping fam;
	object where = environment(me);

	seteuid(getuid());

	if ( (!(fam = me->query("family")) ||
		fam["family_name"] != "丐帮") &&
		!(where->query("sleep_room")) ||
		(where->query("no_sleep_room")) ||
                (where->query_temp("no_sleep")))
		return notify_fail("这里不是你能睡的地方！\n");
	if( me->query_temp("no_sleep") ) return notify_fail("你现在睡不着觉。\n");
	if( me->query_temp("noliving") ) return notify_fail("");   // 非活动玩家
	if( me->is_busy()) return notify_fail("你正忙着呢！\n");
	if( me->is_fighting() ) return notify_fail("战斗中不能睡觉！\n");
	if( (fam = me->query("family")) && fam["family_name"] == "丐帮")
	{
		inv = all_inventory(where);
		for(i=0; i<sizeof(inv); i++)
	if((living(inv[i]) || !inv[i]->query_temp("noliving")) &&
	inv[i]!=me && inv[i]->is_fighting())
			return notify_fail("这里有人在打架，你还照样睡？\n");
	}
	if (where->query("hotel") && !(me->query_temp("rent_paid")))
	{
		message_vision("店小二从门外对$N大叫：把这里当避难所啊！先到一楼付钱后再来睡！\n",me);
		return 1;
	}
	//限制连续睡觉
	if (me->query_temp("sleeped"))
		return notify_fail("你刚睡过一觉，先活动活动吧。 \n");
//加上感冒不能睡觉
		if (me->query_condition("ill_kesou"))
				{
					tell_object(me, "你想合上眼睛好好睡上一觉，可是" +
					"咳嗽"+"不断折磨着你，让你辗转难眠。\n");
					return 1;
				}
		if (me->query_condition("ill_shanghan"))
				{
					tell_object(me, "你想合上眼睛好好睡上一觉，可是" +
					"伤寒"+"不断折磨着你，让你辗转难眠。\n");
					return 1;
				}
		if (me->query_condition("ill_fashao"))
				{
					tell_object(me, "你想合上眼睛好好睡上一觉，可是" +
					"发烧"+"不断折磨着你，让你辗转难眠。\n");
					return 1;
				}
		if (me->query_condition("ill_dongshang"))
				{
					tell_object(me, "你想合上眼睛好好睡上一觉，可是" +
					"冻伤"+"不断折磨着你，让你辗转难眠。\n");
					return 1;
				}
		if (me->query_condition("ill_zhongshu"))
				{
					tell_object(me, "你想合上眼睛好好睡上一觉，可是" +
					"满身的热气" + "不断折磨着你，让你辗转难眠。\n");
					return 1;
				}
// 感冒到此结束 
	if((!arg) || arg==(string)me->query("id"))
	{
		if (where->query("sleep_room"))
		{
			write("你往床上一躺，开始睡觉。\n");
			write("不一会儿，你就进入了梦乡。\n");
			me->set_temp("block_msg/all",1);
			message_vision("$N一歪身，倒在床上，不一会便鼾声大作，进入了梦乡。\n",me);
		}
		else
		{
			write("你往地下角落一躺，开始睡觉。\n");
			write("不一会儿，你就进入了梦乡。\n");
			me->set_temp("block_msg/all",1);
			message_vision("$N往地下角落屈身一躺，不一会便鼾声大作，做起梦来。\n",me);
		}
		where->add("no_fight", 1);
		where->add_temp("sleeping_person", 1);

		me->set("no_get", 1);
		me->set("no_get_from", 1);
		me->set_temp("sleeped",1);


		if( userp(me) ) me->set_temp("noliving/sleeped", 1);
		else me->disable_player("<睡梦中>");
//	call_out("wakeup", random(45-me->query("con"))+45, me, where);
		sleeptime=random(45-me->query("con"))+20;
		if (me->query("mud_age")<86400*4)//18以下加快醒来
			sleeptime-=20;
		if (where->query("hotel")) 
		{//客栈睡觉时间减少
			me->delete_temp("rent_paid");
			sleeptime=sleeptime*1/2;
		}
		if (sleeptime < 10) sleeptime=10;
//		call_out("wakeup", sleeptime, me, where);
		me->start_call_out((:call_other,__FILE__,"wakeup",me,where:),sleeptime);
		return 1;
	}
	if(!objectp(obj = present(arg, where)))
		return notify_fail("你想跟谁一起睡？\n");
	if( !obj->is_character() )
		return notify_fail("？脑袋出毛病了？\n");
// can't sleep with npc...
	if( !userp(obj) )
		return notify_fail("人家可不愿理你！\n");
	if(me->query("gender") == "无性")
		return notify_fail("你是太监啊．．．\n");
	if(me->query("gender") == obj->query("gender"))
		return notify_fail("？对方跟你可是同性呢．．．\n");
	if( !living(obj) || obj->query_temp("noliving") )
		return notify_fail(obj->name() + "没法跟你睡了。\n");
	if (!where->query("if_bed"))
		return notify_fail("就在这里？不太好吧。\n");
	if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 50 )
		return notify_fail("你现在是心有余而力不足。\n");

	if( userp(obj) && (object)obj->query_temp("pending/sleep")!=me )
	{
		message_vision(RED"\n$N含情脉脉地对$n说：我．．．\n\n"NOR, me, obj);
		if( objectp(old_target = me->query_temp("pending/sleep")) &&
			!((string)old_target->query("id")==(string)obj->query("id")))
			tell_object(old_target, YEL + me->name() + "改变主意不想跟你睡了。\n" NOR);
		me->set_temp("pending/sleep", obj);
		tell_object(obj, YEL "看来" + me->name() + "("+(string)me->query("id")+")"+ "很想跟你．．．如果你愿意，请也下一次 sleep 指令。\n" NOR);
		write(YEL "对方正在考虑中．．．\n" NOR);
		return 1;
	}
	message_vision(RED "\n$N冲着$n会心地一笑，点了点头。\n\n" NOR, me, obj);

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
		REMOVE_CMD->do_remove(me, inv[i]);
	inv = all_inventory(obj);
	for(i=0; i<sizeof(inv); i++)
		REMOVE_CMD->do_remove(obj, inv[i]);

	if(me->query("gender")=="男性")
	{
		tell_object(me, HIY"\n\n你搂着"+obj->query("name")+"温软的身体，不由得心醉神迷．．．\n\n\n" NOR);
		tell_object(obj, HIY"\n\n你躺在"+me->query("name")+"的怀里，不由得心醉神迷．．．\n\n\n" NOR);
	}
	else
	{
		tell_object(obj, HIY"\n\n你搂着"+me->query("name")+"温软的身体，不由得心醉神迷．．．\n\n\n" NOR);
		tell_object(me, HIY"\n\n你躺在"+obj->query("name")+"的怀里，不由得心醉神迷．．．\n\n\n" NOR);
	}
	me->set("last_slp",me->query("mud_age"));
	obj->set("last_slp",obj->query("mud_age"));
	if (me->query("couple/couple_id")==obj->query("id"))		me->set("last_sleep_couple",time());
	if (obj->query("couple/couple_id")==me->query("id"))		obj->set("last_sleep_couple",time());
	me->set_temp("block_msg/all",1);
	obj->set_temp("block_msg/all",1);
	me->delete_temp("pending/sleep");
	obj->delete_temp("pending/sleep");
	message_vision(HIY "$N和$n钻入被中，搂在一起睡着了．．．\n\n\n" NOR,me,obj);
	if( userp(me) ) me->set_temp("noliving/sleeped", 1);
	else me->disable_player("<睡梦中>");
	if( userp(obj) ) obj->set_temp("noliving/sleeped", 1);
	else obj->disable_player("<睡梦中>");
// 做记录
	if (!me->query("sex/number"))
		me->set("sex/first",obj->query("id"));
	me->add("sex/number",1);
	me->add("sex/"+obj->query("id"),1);
	if (!obj->query("sex/number"))
		obj->set("sex/first",me->query("id"));
	obj->add("sex/number",1);
	obj->add("sex/"+me->query("id"),1);
// 记录结束

//	call_out("wakeup2",random(45 - me->query("con")) + 30+3, me,obj, where);
//	call_out("wakeup2",random(45 - obj->query("con")) + 30+1, obj, me,where);
  me->start_call_out((:call_other,__FILE__,"wakeup2",me,obj,where:),random(45 - me->query("con")) + 30+1);
	obj->start_call_out((:call_other,__FILE__,"wakeup2",obj,me,where:),random(45 - obj->query("con")) + 30+3);
	return 1;
}
void wakeup(object me,object where)
{
	if(!me) return;
	me->delete("no_get");
	me->delete("no_get_from");
	if (!me->query_temp("block_msg/all"))	return;// 已经能看到东西了 就无所谓醒过来
	if ((me->query("mud_age")-me->query("last_slp"))<120 && me->query("max_jing")>160)
	{
		//在时间限制内  恢复一半的精气和四分一内力
		//精气短的比如新手也让恢复一半 
		me->add("qi", me->query("eff_qi")/2 - me->query("qi")/2 );
		me->add("jing", me->query("eff_jing")/2 - me->query("jing")/2 );
		if (me->query("neili") < me->query("max_neili"))
			me->add("neili", me->query("max_neili")/4 - me->query("neili")/4 );
		me->add("tili", me->query("max_tili")/2 - me->query("tili")/2 );
		message_vision("$N迷迷糊糊的睁开眼睛，懒散无神的爬了起来。\n",me);
		me->set_temp("block_msg/all", 0);
		tell_object(me, "你一觉醒来，由于睡得太多，精神没有恢复多少。\n");
	}
	else
	{
		me->set("qi", me->query("eff_qi"));
		me->set("jing", me->query("eff_jing"));
//		if (me->query("neili") < me->query("max_neili"))
		me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
		me->set("tili", me->query("max_tili") );
		me->set("last_slp",me->query("mud_age"));//记录最近一次完全睡眠的时间
		message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。\n",me);
		me->set_temp("block_msg/all", 0);
		tell_object(me, "你一觉醒来，只觉精力充沛。该活动一下了。\n");
	}

	if( userp(me)) me->delete_temp("noliving");
	else me->enable_player();

//	remove_call_out("del_sleeped");

//	call_out("del_sleeped", 1, me);//两次睡觉不管怎样都限制 这里限制1s
	me->start_call_out((:call_other,__FILE__,"del_sleeped",me:),1);

	if (where->query("no_fight") >= 2)
		where->add("no_fight", -1);
	else
		if ((!where->query("sleep_room") && !where->query("hotel")) ||
			where->query("no_fight")==1 )
			where->delete("no_fight");

	where->add_temp("sleeping_person", -1);
	return;
}

int wakeup2(object me,object slept,object where)
{
	int qi_cost;
	object obj;

	me->set("qi", me->query("eff_qi"));
	me->set("jing", me->query("eff_jing"));
	me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
	if( userp(me)) me->delete_temp("noliving");
	else me->enable_player();

	qi_cost=50+5*((int)me->query("str")-(int)me->query("con"));
	if(qi_cost>(int)me->query("max_qi")/2)
		qi_cost=(int)me->query("max_qi")/2+1;
	me->add("qi", -qi_cost);
	if (me->query("qi") <= 0) me->set("qi", 10);

	while( environment(me)->is_character() )
	me->move(environment(environment(me)));

	if(me->query("gender")!="女性")
	{
		message_vision(HIY"$N醒了过来，似乎还沉浸在幸福之中。\n"NOR,me);
		me->set_temp("block_msg/all", 0);
		tell_object(me, "你醒了过来，似乎还沉浸在幸福之中。\n");
		return 1;
	}
	else
	{
		message_vision(HIY"$N醒了过来，脸上还挂着甜蜜的笑容。\n"NOR,me);
		me->set_temp("block_msg/all", 0);
		tell_object(me, "你醒了过来，脸上还挂着甜蜜的笑容。\n");
		obj=slept;

		if((int)(me->query("mud_age")/86400) < 4 ||
			(int)(me->query("mud_age")/864000) < me->query("child") ||
			(int)(me->query("mud_age")/86400) > 36  
			)
			return 1;

		if (me->query_condition("huaiyun"))	return 1;			

		if (!me->query("child") || random(me->query("sex/"+slept->query("id"))) > me->query("age")/2*me->query("child"))
			{
				if(me->query_temp("no_huaiyun")) // 以后增加和这个对应的obj
				{
					message_vision(HIY "\n$N忽觉腹中一阵颤动，不过马上又平静下来。\n"NOR,me);
					return 1;
				}
//				tell_object(me,"你忽然感觉有点头晕，不过马上又恢复了过来。\n");
				me->set("baby/father",slept->query("id"));
				me->set("baby/gender",random(2)+1);
				me->apply_condition("huaiyun",3200); //一个月约 320 heart beat 
			}
			return 3;
	}
}

void del_sleeped(object me)
{
	if (objectp(me) && me->query_temp("sleeped"))
		me->delete_temp("sleeped");
}
int help(object me)
{
	write(@HELP
指令格式 : sleep <人物>
 
    顾名思义，这个指令是用来睡觉的。恢复精和气的有效途径，但睡
觉时是闭着眼的，所以.......要小心哦。

    如果和配偶睡的话，就有机会生下小孩了。:)
HELP
	);
	return 1;
}
