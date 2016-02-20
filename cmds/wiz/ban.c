// ban.c	

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string *str, site;
	int num = 0;

	if (!arg) {
		BAN_D->print();
		return 1;
	}

	str = explode(arg, " ");
	switch (sizeof(str)) {
		case 2 : site = str[1]; break;
		case 3 : site = str[1]; num = atoi(str[2]); break;
		default : write("指令格式：ban [+|- 地址 [num]]\n"); return 1;
	}

	if (str[0] == "+")
		BAN_D->add(site, num);
	else if (str[0] == "-")
		BAN_D->delete(site, num);
	else	write("指令格式：ban [+|- 地址 [num]]\n");

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：ban [+|- 地址 [num]]

这条命令是用来封禁或解禁地址site。
若num为0或不接num，表示封禁一个确定的地址，不允许进行任何登录；
若num为-1，表示封禁与该地址相匹配的多个地址，不允许进行任何登录；
若num为正数，表示限制该地址最大登录人数为num；
若地址为clear，则清除相应的列表。
HELP
);
	return 1;
}

