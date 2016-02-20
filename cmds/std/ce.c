// ce.c
inherit F_CLEAN_UP;

#include <ansi.h>
#include <net/dns.h>



int help(object me);
void create() {seteuid(getuid());}

int main(object me, string arg)
{
	object obj;
	int flag=1;
	if(!me->query("couple/have_couple")) return help(me);

	obj = find_player(me->query("couple/couple_id"));

		if(!obj || (!wizardp(me) && !me->visible(obj)))
			flag=0;

//	if (!wizardp(me) && obj->query_temp("pigging_seat"))
//		return notify_fail("你的伴侣正在拱猪，听不到悄悄话....\n");

	if( !arg )
	{
//		message_vision(MAG "\n$N多么思念"+me->query("couple/couple_gender")+me->query("couple/couple_name")+"啊，可是伊人何方呢...\n"NOR, me);
		write(MAG "\n你多么思念"+me->query("couple/couple_gender")+me->query("couple/couple_name")+"啊，可是伊人何方呢...\n"NOR);
		if (flag)
		tell_object(obj,MAG"\n你的"+obj->query("couple/couple_gender")+"在思念你... ...\n" NOR);
	}
	else
		switch (arg)
		{
			case "kiss":
				if( objectp(present(me->query("couple/couple_id"), environment(me))) )
//					message_vision(MAG "\n$N拥抱着$n深深地一吻...\n"NOR, me, obj);
				{
					write(MAG "\n你拥抱着"+me->query("couple/couple_name")+"深深地一吻...\n"NOR);
					tell_object(obj,MAG"\n"+obj->query("couple/couple_name")+"拥抱着你深深地一吻...\n" NOR);
				}
				else
				{
					write(MAG "\n你多想拥抱你的" + me->query("couple/couple_gender") + "深深地一吻...\n" NOR);
					if (flag)
					tell_object(obj, MAG "\n你的"+obj->query("couple/couple_gender")+"多想拥抱你，给你深深的一吻... ...\n" NOR);
				}
				break;	
			case "bye":
				if( objectp(present(me->query("couple/couple_id"), environment(me))) )
//					message_vision(MAG "\n$N含泪凝望着$n，哽咽道: 又要再见了，何时才能长相聚不分离呀...\n"NOR, me, obj);
				{
							write(MAG "\n你含泪凝望着"+me->query("couple/couple_name")+"，哽咽道: 又要再见了，何时才能长相聚不分离呀...\n"NOR);
							tell_object(obj,MAG "\n"+obj->query("couple/couple_name")+"含泪凝望着你，哽咽道: 又要再见了，何时才能长相聚不分离呀...\n"NOR);
				}
				else
				{
					if (me->query("gender")=="女性")
					{
						write(MAG"\n你多想再多看你的"+me->query("couple/couple_gender")+"一眼，让他知道你是这样的一直念挂着他...\n"NOR);
					if (flag)
						tell_object(obj, sprintf(MAG "\n你的%s多想再多看你一眼，山遥水隔，她会一直记挂你的，你要自己保重啊... ...\n" NOR, obj->query("couple/couple_gender")));
					}
					else
					{
						write(MAG"\n你多想再多看你的"+me->query("couple/couple_gender")+"一眼，让她知道你是这样的一直念挂着她...\n"NOR);
					if (flag)
						tell_object(obj, MAG "\n你的"+obj->query("couple/couple_gender")+"多想再多看你一眼，山遥水隔，他会一直记挂你的，你要自己保重啊... ...\n" NOR);
					}
				}
				break;
			default:
			if (!flag)
				if (me->query("gender")=="女性")
					return notify_fail(MAG"你想和你的" + me->query("couple/couple_gender")+"说说话，可是他现在不在线上。\n"NOR);
				else
					return notify_fail(MAG"你想和你的" + me->query("couple/couple_gender")+"说说话，可是她现在不在线上。\n"NOR);
			write(MAG "你悄悄告诉你的" + me->query("couple/couple_gender") + "：" + arg + "\n" NOR);
			tell_object(obj, sprintf( MAG "你的%s悄悄告诉你：%s\n" NOR, obj->query("couple/couple_gender"), arg));
//				message("channel:snp", HIB"【监听】" + me->name() + "悄悄告诉"+ obj->name() + "：" + arg + "\n"NOR, users());
// 				听别人私房话不好吧?
		}
		return 1;
}

int help(object me)
{
	write(@HELP

指令格式：ce [kiss | bye] [<讯息>]

    你可以用这个指令对你的伴侣说悄悄话。

HELP
	);
	return 1;
}
