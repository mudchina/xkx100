/*


申志凡(Shen zhifan)天枢
王志坦(Wang zhidan)天璇
崔志方(Cui zhifang)天玑
赵志敬(Zhao zhijing)天权
陈志益(Chen zhiyi)玉衡
李志常(Li zhichang)开阳
尹志平(Yin zhiping)摇光

秦志鲲向丘处机打听有关『job』的消息。
丘处机点了点头。
丘处机说道：你去大校场赵志敬那儿好好练习一下「天罡北斗阵」!


尹志平吸了一口气，将内力收回丹田，剑招也恢复正常！

*/
// qixing.c
#include <ansi.h>
int main(object me, string arg)
{
	string msg, enemy, ob1, ob2, ob3, ob4, ob5, ob6;
	string myname=me->query("name");
	object en, obj1, obj2, obj3, obj4, obj5, obj6, *obs;
	int i, j, power;
	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准战斗。\n");
	if( !arg )
	{
		return notify_fail("启动天罡北斗阵必须指定组阵阵友和对手。\n");
	}
	if(sscanf(arg, "%s %s %s %s %s %s %s",enemy,ob1,ob2,ob3,ob4,ob5,ob6)!=7)
	{
		return notify_fail("指令格式：qixing 敌手 阵友1 阵友2 阵友3 阵友4 阵友5 阵友6\n");
	}

	if(!objectp( en= present(enemy, environment(me))))
		return notify_fail("没有敌人啊？\n");
	if(!en->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");
	if( en->is_fighting() )
		return notify_fail("人家已经在战斗中了，还想布阵？\n");
	if( !living(en) || en->query_temp("noliving") )
		return notify_fail(en->name()+"都已倒地了，还用得着围攻吗？\n");
	if((int)en->query("age") <= 15 && userp(en))
		return notify_fail("为了世界更美好，放过小孩子吧。\n");
	if(en==me) return notify_fail("干掉自己？别这么想不开。\n");

	if(!objectp( obj1 = present(ob1, environment(me))))
		return notify_fail("你好象阵友没指定对吧？\n");
	if(!objectp( obj2 = present(ob2, environment(me))))
		return notify_fail("你好象阵友没指定对吧？\n");
	if(!objectp( obj3 = present(ob3, environment(me))))
		return notify_fail("你好象阵友没指定对吧？\n");
	if(!objectp( obj4 = present(ob4, environment(me))))
		return notify_fail("你好象阵友没指定对吧？\n");
	if(!objectp( obj5 = present(ob5, environment(me))))
		return notify_fail("你好象阵友没指定对吧？\n");
	if(!objectp( obj6 = present(ob6, environment(me))))
		return notify_fail("你好象阵友没指定对吧？\n");
	if(en==obj1 || en==obj2 || en==obj3 || en==obj4 || en==obj5 || en==obj6 || en==me || obj1==obj2 || obj1==obj3 || obj1==obj4 || obj1==obj5 || obj1==obj6 || obj1==me || obj2==obj3 || obj2==obj4 || obj2==obj5 || obj2==obj6 || obj2==me || obj3==obj4 || obj3==obj5 || obj3==obj6 || obj3==me || obj4==obj5 || obj4==obj6 || obj4==me || obj5==obj6 || obj5==me || obj6==me)
		return notify_fail("阵列摆设不对。\n");
	me->dismiss_team();
	me->set_leader();
	me->add_team_member(obj1);
	me->add_team_member(obj2);
	me->add_team_member(obj3);
	me->add_team_member(obj4);
	me->add_team_member(obj5);
	me->add_team_member(obj6);

	if(pointerp(obs=me->query_team()) )
	{
		for(i=0;i<sizeof(obs);i++)
		{
			if(!obs[i]->is_character() )
return notify_fail(obs[i]->query("name")+"不是生物。\n");
			if( obs[i]->is_fighting() )
return notify_fail(obs[i]->query("name")+"已在战斗中了。\n");
			if( !living(obs[i]) || obs[i]->query_temp("noliving") )
return notify_fail(obs[i]->name()+"已倒在地上了，无法追随你。\n");
			if((int)obs[i]->query("age") <= 15 && userp(obs[i]))
return notify_fail(obs[i]->query("name")+"人家还小，放弃吧。\n");
			if((int)obs[i]->query_skill("array",1) <= 50 ||
			  (int)obs[i]->query_skill("xiantian-qigong",1) <= 50 ||
			  (int)obs[i]->query_skill("quanzhen-jian",1) <= 50)
return notify_fail(obs[i]->query("name")+"的技能不足布阵。\n");
		}

		if(sizeof(obs) != 7)
			return notify_fail("布阵人数不足。\n");

	}

	for(i=0;i<sizeof(obs);i++)
	{
		if(obs[i] != me)
			message_vision(myname+ "道："+obs[i]->query("name")+"请做好准备！\n",me);
	}
	message_vision(myname+ "清了清喉咙，大声说道：好，时辰已到，现在开始启动「天罡北斗阵」！\n",me);
	message_vision(myname+ "突然身形移动，发动众全真弟子抢占位置，左边四人，右边三人，正是摆的「天罡北斗阵」阵法。\n",me);
	remove_call_out("do_qixing");
	call_out("do_qixing", 1, me, en);
	return 1;
}
int do_qixing(object me, object en)
{
	object *obs, weapon, enweapon;
	int i, j, power;
	string *where = ({
		"天枢",
		"天璇",
		"天玑",
		"天权",
		"玉衡",
		"开阳",
		"摇光"
	});

	if(pointerp(obs=me->query_team()) )
	switch (random (4))
	{
		case 0:
message_vision("天罡北斗阵气势宏大，前攻后击，连环相接，让人眼花撩乱，方寸顿失。\n",me);
			break;
		case 1:
message_vision("天罡北斗阵法滚滚推动，攻势连绵不绝，瞬间将敌人围在垓心。\n",me);
			break;
		case 2:
message_vision("天罡北斗阵越缩越小，无形剑气象浪潮一般逼向中央，令人有窒息之感。\n",me);
			break;
		case 3:
message_vision("只见天罡北斗阵暗合五行八卦之理，阵中人步法精妙，攻守配合得天衣无缝，威力之大，让人叹为观止。\n",me);
			break;
	}
	for(i=0;i<sizeof(obs);i++)
	{
		weapon = obs[i]->query_temp("weapon");
		power = obs[i]->query_skill("force",1)/10;
	        obs[i]->add_temp("apply/attack", power);
	        obs[i]->add_temp("apply/damage", power);

		switch (random(4))
		{
			case 0:
message_vision(where[i]+"位上的"+obs[i]->query("name")+ "气沉丹田，暗运神功，猛然吐气开声，身形往前一纵, 但见", me);
				break;
			case 1:
message_vision(where[i]+"位上的"+obs[i]->query("name")+ "挺身而出，步法精妙，长袖飘飘，攻势如虹。只见", me);
				break;
			default:
		}
		COMBAT_D->do_attack(obs[i],en,weapon);
		if(en->query("qi")*2 <= en->query("max_qi"))
		{
			remove_call_out("do_end");
			call_out("do_end", 1, me, en, 0);
			return 1;
		}
		obs[i]->add_temp("apply/attack", -power);
		obs[i]->add_temp("apply/damage", -power);
	}
	j = random(7);
	enweapon = en->query_temp("weapon");
	COMBAT_D->do_attack(en,obs[j], enweapon);
	if(obs[j]->query("qi")*2 <= obs[j]->query("max_qi"))
	{
message_vision(HIR+obs[j]->query("name")+"一跤趴在地上，摔出北斗阵。\n"NOR,me);
		remove_call_out("do_end");
		call_out("do_end", 1, me, en, 1);
		return 1;
	}
	if(obs[j]->query("qi")*3 <= obs[j]->query("max_qi")*2)
	{
message_vision(obs[j]->query("name")+ "踉跄了一步，差点摔出北斗阵。\n",me);
	}
	else if(obs[j]->query("qi")*5 <= obs[j]->query("max_qi")*4)
message_vision(obs[j]->query("name")+"被打得晃了几晃，不过又站稳了步子。\n",me);

	remove_call_out("do_qixing");
	call_out("do_qixing", 1, me, en);
	return 1;
}
int do_end(object me, object en, int result)
{
	if( result == 1)
	{
		if(en->query_temp("pre_qixing") && !wizardp(en))
		{
			en->set("qixing", 1);
		}
		en->delete_temp("pre_qixing");
		message_vision(HIR"\n天罡北斗阵被"+en->query("name")+"打破了。\n"NOR,me);
	}
	else
	{
		en->delete_temp("pre_qixing");
message_vision(HIR"\n$N笑了笑：天罡北斗阵不愧为全真镇教之宝。\n"NOR,me);
	}
	remove_call_out("do_back");
	call_out("do_back", 1, me);
	return 1;
}
int do_back(object me)
{
	object *obs, weapon;
	int i;

	if(pointerp(obs=me->query_team()) )
	{
		for(i=0;i<sizeof(obs);i++)
		{
			if (objectp(weapon = obs[i]->query_temp("weapon"))
				&& (string)weapon->query("skill_type")=="sword")
message_vision("$N身子向后一纵，使一招『收剑式』，将剑挽了一个剑花，往怀中一抱，退出「天罡北斗阵」。\n", obs[i]);
			else
message_vision("$N身子向后一纵，使一招『收山式』，右拳划了一圈，左掌往怀中一抱，退出「天罡北斗阵」。\n", obs[i]);

message_vision("$N作了个楫道：贫道先告退了！说完就快步离开了。\n", obs[i]);
		}
	}
	me->dismiss_team();
}

