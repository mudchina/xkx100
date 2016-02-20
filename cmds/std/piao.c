// piao.c
inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{
	mapping fam;
	object obj, old_target, where = environment(me);
	int oexp,mexp;
	seteuid(getuid());

	if (me->query("gender") =="女性")
		return notify_fail("女人做这种事当然太亏了。\n");

	if (!environment(me)->query("piao_room"))
		return notify_fail("想嫖娼当然要去妓院了！\n");
	if (!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你现在很冲动，可是姑娘们都不在！\n");
	if (me->query("gender") =="无性")
		return notify_fail("你连那个玩意都没有，还想硬上弓？\n");
	if (me->query("age") < 17)
		return notify_fail("小兄弟，要找姑娘过几年再来吧！\n");
	if (obj->query("age") < 17)
		return notify_fail("人家小姑娘还没有十七岁呢！\n");
	if(query_ip_name(obj)==query_ip_name(me))
		return notify_fail("嫖自己？没听说过，够不着嘛。\n");
	if (obj==me) return notify_fail("自己安慰自己？不要这么麻烦的嘛。\n");
	if (!obj->is_character())
		return notify_fail("哇，死的东西都不放过！\n");
	if (!living(obj) || obj->query_temp("noliving") )
		return notify_fail(obj->name() + "立马被蹂躏了。\n");
	if (!wizardp(me) && wizardp(obj) )
		return notify_fail("巫师不做这种事的。\n");
	if (obj->query("eff_jing")<20)
		return notify_fail("发发善心吧，她再被蹂躏会死的！\n");
	if (obj->query_condition("prostitute") < 1)
		return notify_fail("她不是妓女啊！\n");
	tell_object(me,"你故做温柔地走向" + obj->name() + "，伸手三把两把扯去" + obj->query("name") + "的衣服，\n\n");
	tell_object(obj,me->name()+"一副温文尔雅的模样走过来，一到你身边立马露出一副猴急样，伸手就脱你的衣服。\n\n");
	message("vision","只见" + me->name() + "一副温文尔雅的模样走向"+obj->name() + "\n然后猴急猴急地伸手脱去"+obj->name()+"的衣服！\n\n\n", environment(me), ({ me,obj }) );
	me->start_busy(3);
	message_vision("在一个风雨如晦的夜晚，$N和$n双双成就一对露水鸳鸯。\n",obj,me);
	message_vision("$N和$n为人类的进化和繁衍作出了不可磨灭的贡献。\n",obj,me);
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
	me->receive_damage("jing", 3);
	me->receive_wound("jing", 3);
	me->add("mud_age", 240);
	me->add("combat_exp",2);
	me->add("shen",-1000);
	me->set("couple/have_couple",1);
	me->start_busy(3);
	obj->receive_damage("jing",1);
	obj->receive_wound("jing", 20);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : piao <某人>

    嫖。丽春院专用命令。

HELP
	);
	return 1;
}

