// info.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object obj;
	object *ob;
	string str;
	int i,dest;
	object env;
	string place;
	string name;

	if (!arg) return help(me);

	seteuid(geteuid(me));
	if (sscanf(arg,"-d %s",arg)==1) dest=1;
	if( arg=="me" ) obj = me;
	else if( arg=="my link" ) obj = me->query_temp("link_ob");
	else {
		obj = present(arg, me);
		if (!obj) obj = present(arg, environment(me));
		if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) );
		if (!obj && sizeof(children(arg))) obj = find_object( resolve_path(me->query("cwd"), file_name(children(arg)[0])));
		if (!obj) return notify_fail("没有这样物件....。\n");
	}

	printf("物件 [%O]\n-----------------------------------------------------\n", obj);
	write("档案：\t\t" + base_name(obj) + ".c\n");
	write("领域：\t\t" + domain_file(base_name(obj)) + "\n");
	write("作者：\t\t" + author_file(base_name(obj)) + "\n");
	write("权限：\t\tuid = " + getuid(obj) + ", euid = " + geteuid(obj) + "\n");
	write("等级：\t\t" + wizhood(obj) + "\n");
	write("使用记忆体：\t" + memory_info(obj) + "\n");
	str = "";
	if( living(obj) ) 		str += "生物 ";
	if( userp(obj) )		str += "使用者 ";
	if( interactive(obj) )	str += "线上 ";
	if( wizardp(obj) ) 		str += "巫师 ";
	if( clonep(obj) ) 		str += "复制 ";
	if( virtualp(obj) ) 	str += "虚拟 ";
	if( query_heart_beat(obj) ) str += "心跳:" + query_heart_beat(obj) + " ";
	write("属性：\t\t" + str + "\n");
	write("参考连结：\t" + refs(obj) + "\n");
	write("复制个数：\t" + sizeof(children(base_name(obj)+".c")) + "\n");
	write("分别如下：\n");
	ob=children(base_name(obj));
	if (dest==1)
	if ( base_name(obj)=="/clone/misc/void" 
			||base_name(obj)=="/clone/user/user")
	{	
		write("这样东西不允许这样删除。\n");
		return 1;
	}
	for (i=0;i<sizeof(ob);i++)
	{
	if (dest==1)
	{
		write("清除"+file_name(ob[i]));
		destruct(find_object(resolve_path(me->query("cwd"), file_name(ob[i])) ));
		write("成功。\n");
	}else
		{
			write(sprintf("%-24s ",file_name(ob[i])));
			if (ob[i]->query("name") && ob[i]->query("id"))
			name=ob[i]->query("name")+"("+ob[i]->query("id")+")";
			else 
      name="";
			write(sprintf("%-20s",name));
			if (objectp(env=environment(ob[i])))
			{
				place=env->query("name");
				if (!place)
				place=env->query("short");
				if (!place)
				place=env->query_short();
				write(sprintf("%-10s %s",place,file_name(env)));
			}
			write("\n");
		}
	}		

	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : iinfo [-d] <物件之名称或档名>
					 iinfo link me
					 iinfo me
					 iinfo here
	参数 -d 表示删除所有复制出的改物件。
	
利用此一指令可得知一些有关该物件的资讯。
HELP
    );
    return 1;
}
