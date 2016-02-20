// kickto.c 踢某人至阴间
inherit F_CLEAN_UP;


#include <ansi.h>
#include <command.h>


int main(object me, string arg)
{
	object ob;
	string wiz_status, tmpstr;

	if( me!=this_player(1) ) return 0;
	if( !arg )
		return notify_fail("你要踢谁？\n");
	wiz_status=SECURITY_D->get_status(me) ;
//	if (wiz_status != "(admin)" )
//		return notify_fail("踢什么踢？\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("咦... 有这个人吗？\n");
	if ( !living(ob) || !ob->is_character() || ob==me )
		return notify_fail("ob error!\n");
	message_vision(HIW"\n$N一脚踹在$n的屁股上，$n顿时横着飞了出去。\n\n"NOR, me,ob);
	tell_object( me, "你把 " + ob->query("name") + " 踹到监狱去了。\n");
	seteuid(getuid(ob));
	me->save();
	seteuid(ROOT_UID);
	ob->move("/d/wizard/wizard_jail");
	ob->save();
	seteuid(getuid());
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : kickto <某人>
作    用 : 防止某些玩家捣乱。
HELP);
	return 1;
}

