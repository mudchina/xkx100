inherit F_CLEAN_UP;

#include <ansi.h>



void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object where = environment(me);

	if (! me->query("is_vendor"))
		return notify_fail("只有从事商业的人才能摆摊。\n");
	if (! present("shang ling", me))
		return notify_fail("你未带商令！如今世道乱，小心为妙。\n");

	if (me->is_fighting())
		return notify_fail("你还是好好打你的架吧。\n");

	if (me->query_temp("on_baitan"))
		return notify_fail("你现在已经占了一个摊位，就适可而止吧。\n");
	if (me->is_busy() || me->query_temp("pending/deriving"))
		return notify_fail("你现在正忙着呢，没功夫摆摊设点。\n");
	if (me->query_condition("killer"))
		return notify_fail("官府正到处追查你呢，难得还有心情摆摊？\n");
	if (where->query("no_trade"))
		return notify_fail("这里常有官兵巡逻，最好换个地方做生意。\n");
	if (where->query("no_fight") && ! where->query("can_trade") && !wizardp(me))
		return notify_fail("此处过于嘈杂，还是换个地方做生意吧。\n");
	message_vision(WHT"$N"WHT"寻了块空地，一屁股坐了下来，随后掏出一块布摊开在地。\n" NOR, me);
	tell_object(me, HIC"现在你可以摆上(" HIW "stock" HIC ")货物或是收起(" HIW "unstock" HIC ")某种货物。\n" NOR);

	me->set_temp("on_baitan", 1);
	me->set_temp("baitan_place",file_name(environment(me)));
	me->delete("vendor_goods");
//	me->set_short_desc("正在地上摆摊。");
//	me->start_busy((:baitan:),(:halt_baitan:));
	me->set_temp("apply/short",({me->name()+"正坐在地上摆地摊。"}));
	me->apply_condition("baitan",1);
//        me->start_call_out((:call_other,__FILE__,"baitan",me,3:), 10);
        return 1;
}

int baitan(object me)
{
//	switch (random(4))
	switch (random(15))
	{
		case 0:
			message_vision(CYN"$N"CYN"环顾了一下四周，笑眯眯地招呼着众人。\n"NOR, me);
			break;
		case 1:
			message_vision(CYN"$N"CYN"吆喝道：走过路过不要错过，大家快来看看货。\n"NOR, me);
			break;
		case 2:
			message_vision(CYN"$N"CYN"吆喝道：大家来看看，我这里货物齐全，包您满意。\n"NOR, me);
			break;
		case 3:
			message_vision(CYN"$N"CYN"吆喝道：来来来，现在所有物品贱价出售，别错过。\n"NOR, me);
			break;
		default:
		  break;
	}

	return 1;
}

varargs int halt_baitan(object me,int silent)
{
	if (!silent)
	message_vision(WHT"$N"WHT"提起摊布的四个角，把货物一股脑的收了起来，站起身来。\n" NOR, me);

	me->delete_temp("on_baitan");
	me->delete_temp("apply/short");
	me->delete_temp("baitan_place");
	me->delete("vendor_goods");
	me->set_short_desc(0);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : baitan

摆摊设点，兜售货物。

HELP);
	return 1;
}
