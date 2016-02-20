// passwd.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}
int main(object me, string arg)
{
	object ob,link_ob;
	string id,password;
	if(!arg||sscanf(arg,"%s %s",id,password)!=2)
		return notify_fail("瞧你要更改谁的密码？更改密码之前请三思一定要得到其本人同意。\n");
	ob=find_player(id);

	if(!ob)
	{
		ob = new(LOGIN_OB);
		ob->set("id",id);
		if( !ob->restore() ) return notify_fail("没有这个玩家。\n");
		else
		{
			ob->set("password",crypt(password,0));
			ob->save();
			destruct(ob);
			return 1;
		}
	}
	link_ob=ob->query_temp("link_ob");
	if(link_ob)
	{
		link_ob->set("password",crypt(password,0));
		link_ob->save();
		return 1;
	}
	else
		return notify_fail("错误。无法进行修改。\n");
	return 1;
}


int help(object me)
{
	write(@HELP
指令格式 : passwd

这个指令可以修改你的人物密码。

HELP
    );
    return 1;
}
