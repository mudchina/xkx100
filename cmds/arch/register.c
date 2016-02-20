// register.c
// Created by Xiang@XKX

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int register_user(string wizid, string name, string email)
{
	object ob, body;

       	if( objectp(body = find_player(name)) && geteuid(body)==name ) 
		return notify_fail("你只能在玩家离线时才能给他登记。\n");

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if (!ob->restore())
		return 0;
	else {
		ob->set("registered", 1);
		ob->set("email", email);
		ob->set("registered_by", wizid);
		ob->save();
		destruct(ob);
		return 1; 
	}
}

int main(object me, string arg)
{
	string id, email;

	if (!arg || sscanf(arg, "%s %s", id, email) != 2) {
		return notify_fail("指令格式：register <id> <email>\n");
	}
	switch(register_user(me->query("id"), id, email)) {
	case 0: return notify_fail("登记失败。\n"); break;
	default: return notify_fail(id + " 已经成功地被您登记了。\n"); break;
	}
}

int help(object me)
{
	write(@HELP
指令格式：register <id> <email>

这个指令是用来给还没有登记过的用户登记用的。
HELP
	);
	return 1;
}
