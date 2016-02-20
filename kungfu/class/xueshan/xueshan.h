// xueshan.h

string ask_for_join()
{
	object me = this_player();

	if( (string)me->query("class")=="lama" )
		return "阿弥陀佛！你我同是出家人，何故跟贫僧开这等玩笑？\n";

	if( (string)me->query("gender") != "男性" )
		return "施主若真心向佛，真是可喜可贺，可惜本寺只收男徒。\n";

	me->set_temp("pending/join_bonze", 1);
	return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。\n";
}

int do_kneel()
{
	object me = this_player();

	if( !me->query_temp("pending/join_bonze") ) return 0;
	message_vision("$N双手合十，恭恭敬敬地跪了下来。\n\n$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n", me, this_object() );
	command("smile");
	me->set("class", "lama");
	return 1;
}

