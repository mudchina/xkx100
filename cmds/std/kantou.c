// kantou.c
inherit F_CLEAN_UP;

#include <ansi.h>


int do_kan(object me, object ob, object weapon);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, weapon;

	if( !arg ) return notify_fail("你要砍谁的头？\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		((string)weapon->query("skill_type") != "sword" &&
		(string)weapon->query("skill_type") != "axe" &&
		(string)weapon->query("skill_type") != "dagger" &&
		(string)weapon->query("skill_type") != "hook" &&
		 (string)weapon->query("skill_type") != "blade"))
		return notify_fail("你不用利器哪里砍得动！\n");
	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("你只能砍尸体的头。\n");
	if(userp(obj) || living(obj) )
		return notify_fail("那还是活的！先杀了才能砍头！\n");
	if( me->is_fighting() )
		return notify_fail("你还在战斗中！还想砍人家的头？\n");
	return do_kan(me, obj, weapon);
}
	
int do_kan(object me, object obj, object weapon)
{
	object newob;
	string newname;

	if( !obj ) return 0;
	if( obj->query("kantou") == 1)
	{
		message_vision( "$N是个无头尸。\n", obj );
		return 1;
	}
	newname = obj->query("name");
	if( strsrch(newname, "腐烂的尸体") >= 0)
	{
		message_vision( "腐尸还砍个啥劲呀。\n", obj );
		return 1;
	}
	if(strsrch(newname, "尸体") >= 0)
		newname = replace_string(newname, "尸体", "头颅");
	else
	{
		message_vision(obj->query("name")+"有什么头可砍的。\n", obj );
		return 1;
	}
	newob = new("/clone/misc/head");
	newob ->set("name", HIR+newname+NOR);
	newob ->move(me);
	if( obj->query("userp") == 1) newob-> set("userp", 1);
	if( obj->query("quest") ) newob-> set("quest", obj->query("quest"));
	if( obj->query("owner")) newob->set("owner",obj->query("owner"));
	if( me->is_fighting() ) me->start_busy(1);
	message_vision( "$N挥起"+weapon->query("name")+"将$n的脑袋砍了下来。\n", me, obj );
	obj->set("kantou", 1);
	newname = obj->query("name");
	if(strsrch(newname, "尸体") >= 0)
		newname = replace_string(newname, "尸体", "无头尸体");
	obj->set("name", newname);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : kantou <尸体名称>
 
    这个指令可以让你砍下地上死者的头颅。
    很多任务要求砍头献功的。
 
HELP
	);
	return 1;
}
 
