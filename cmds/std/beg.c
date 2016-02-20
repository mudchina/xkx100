// beg.c
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;

	object where = environment(me);

	seteuid(getuid());

	if ( (!(myfam = me->query("family")) || myfam["family_name"] != "丐帮"))
		return notify_fail("只有乞丐才能乞讨！\n");
	if( me->is_busy() ) return notify_fail("你上一个动作还没有完成！\n");
	if( environment(me)->query("no_beg") ||
		environment(me)->query("no_fight"))
		return notify_fail("这里不是你叫化子能来讨饭的地方！\n");
	if( me->query_temp("begging") )
		return notify_fail("你已经在向人家乞讨了！\n");
	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 )
		return notify_fail("指令格式：beg <物品> from <人物>\n");
	victim = present(who, environment(me));
	if( !victim || victim==me)
		return notify_fail("你想乞讨的对象不在这里。\n");
	if( !living(victim) || victim->query_temp("noliving") ||
		!objectp(victim) )
		return notify_fail("你要向谁乞讨？\n");
	if( (vtfam = victim->query("family")) && vtfam["family_name"] == "丐帮")
		return notify_fail("你不能向乞丐乞讨！\n");
	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("玩家不能向巫师乞讨。\n");
	if( me->is_fighting() )
		return notify_fail("一边打架一边要饭？你真是活腻了！\n");
	if( victim->is_fighting() )
		return notify_fail(victim->name() + "正在打架，没空理你！\n");
	if( !living(victim) || victim->query_temp("noliving") )
		return notify_fail(victim->name()+ "都已经这样了，你还用得着乞讨吗？\n"); 
	if( userp(victim) && victim->query("kar") == me->query("kar") )
		return notify_fail("这是那人的随身家伙，肯定不会给你。\n");

//	if( ob->query_temp("is_rided_by") == me->query("id"))
	if( !ob = present(what, victim) )
	{
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "身上看起来没有什么让你感兴趣的东西。\n");
		ob = inv[random(sizeof(inv))];
	}

	if ( ob->query("equipped") || ob->query("no_drop") )
		return notify_fail("这是那人的随身家伙，肯定不会给你。\n");
	if ( ob->query_temp("is_rided_by") )
		return notify_fail("这是那人的坐骑，肯定不会给你。\n");
	if ((ob->query("id"))=="bao wu")
		return notify_fail("人家的宝物怎么舍得给你\n");
	sp = (int)me->query_skill("begging", 1) * 15 + (int)me->query("kar") * 5 - (int)me->query("begger") * 2;
	if( sp < 1 ) sp = 1;
	dp = (int)victim->query("jing");

	tell_object(me, "你装出可怜巴巴的样子，慢慢地向" + victim->name() + "走过去，伸出双手，想要" + ob->query("unit") + ob->name() +"...\n\n");
	tell_object(victim, me->name() + "可怜巴巴地向你慢慢走过来，伸出手，说道：" + RANK_D->query_respect(victim) + "行行好，给我" + ob->query("unit") + ob->name() + "吧 ...！\n\n");
	message("vision", "只见" + me->name() + "装出可怜巴巴的样子，慢慢地向" + victim->name() + "走过去，\n伸出双手，说道：" + RANK_D->query_respect(victim) + "，行行好吧 ...\n\n", environment(me), ({ me, victim}) );
	me->start_busy(4);
	me->set_temp("begging", 1);
	call_out( "compelete_beg", 3, me, victim, ob, sp, dp);
	return 1;
}

private void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
	int amount, blvl;
	object ob1;
	object where = environment(me);

	me->delete_temp("begging");

	if( environment(victim) != environment(me) )
	{
		tell_object(me, "太可惜了，你要乞讨的人已经走了。\n");
		return;
	}
  if (!objectp(ob) || environment(ob) != victim)
  {
    tell_object(me, "太可惜了，"+ob->name()+"好像已经不在人家身上了。\n");
    return;
  }

	if( living(victim) && !victim->query_temp("noliving") &&
		(random(sp+dp) > dp) )
	{
		if ( ob->query("money_id") )
		{
			amount = ob->query_amount();
			if( amount < 5 )
			{
				tell_object(me,"看来还是走吧，这家伙身上已经没有多少油水可榨了。\n");
				return;
			}

			ob->set_amount(amount - amount/5);

			ob1=new("/clone/money/" + ob->query("money_id"));
			ob1->set_amount(amount/5);
			ob1->move(me);

		}
		else if( !ob->move(me) )
			{
				ob->move(where);
				tell_object(me, "你讨到一" + ob->query("unit") + ob->name() + "，可是对你而言太重了，不得不丢在地下。\n");
				return;
			}

		tell_object(me, victim->name() + "低头想了一会，又看了看你，摇摇头，叹了口气，丢给你一" + ob->query("unit") + ob->name() + "。\n");
		tell_object(victim, "你看着" + me->name() + "的可怜样，叹了口气，丢给他一" + ob->query("unit") + ob->name() + "。\n");
// 下面防止潜能和技能达无限增长
		blvl = me->query_skill("begging", 1);
		if ( (int)me->query("combat_exp") > (blvl*blvl*blvl)/10)
		{
			me->improve_skill("begging", random(me->query("int")));
		}
		else
		{
			tell_object(me, "就这点经验值也去叫化？还是别去丢人了！\n");
		}
		me->add("potential", 1);
		me->add("combat_exp", 1);

		if( random(sp) < dp/2 )
			message("vision", "你看到" + victim->name() + "冲着" + me->name() + "满脸不屑地摇摇头，" + "丢给他一" + ob->query("unit") + ob->name() + "！\n", environment(me), ({ me, victim }) );
		me->add("jing",-8);
		me->add("eff_jing", -2);
	}
	else
	{
		if( random(sp) > dp/2 )
		{
			message_vision( victim->name() + "狠狠地瞪了$N一眼，喝道：滚！ $N吓了一跳，急忙扭头灰溜溜地走开了。\n", me);
			me->add("begger", 1);
			me->add("jing",-4);
			me->add("eff_jing", -2);
			return;
		}

		tell_object(me, victim->name() + "扭过头去，对你理都不理。\n");
		tell_object(victim, "你扭过头去，对"+me->name()+"理都不理。\n");
		message("vision", victim->name() + "扭过头去，对" + me->name() + "理都不理。\n", environment(me), ({ me, victim }) );
	}
}

int help(object me)
{
	write(@HELP
指令格式 : beg <某物> from <某人>

    乞讨（丐帮弟子专用）。

HELP
	);
	return 1;
}

