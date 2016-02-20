// mipcheck.c
// Last Modified by winder on May. 15 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	int i, j, count = 0;
	object *lob, obj, *obs;
	string ip, tmp, str = HIR"\n  …… 检查多重登录 …… "NOR;
	mixed groups;
     	int ip1,ip2,ip3,ip4,n,myip,yourip;
    	string arg1;
	
	obs = filter_array(objects(), (: interactive :));
	obs = filter_array(obs, (:environment:));
	obs = sort_array(obs, (:strcmp(query_ip_number($2), query_ip_number($1)):));
	i = sizeof(obs);
	
	if( stringp(arg) )
	{
		if( arg == "all")
		{
			groups = unique_array(obs, (: query_ip_number($1) :));
			if ( !sizeof(groups) )
				return notify_fail(HIR"\n …… 完毕 ……\n"NOR);
			for(i = 0; i < sizeof(groups); i++)
			{
				if( sizeof( groups[i]) < 1) continue;
				obs = groups[i];
				lob = obs->query_temp("link_ob") - ({0});
				ip = query_ip_number(obs[0]);
				tmp = sprintf("\n"HIY"%-16s"WHT" → "NOR, ip);
				for( j = 0; j < sizeof(obs); j++ )
				{
					if( j > 0 && j % 4 == 0 ) tmp += "\n\t\t    ";
					tmp += sprintf("%-8s", obs[j]->query("id"));
				}
				str += tmp;
			}

			str += HIR"\n  …… 完毕 …… "NOR;
			str += HIR"总共有"+chinese_number(sizeof(groups))+"个地址连接本泥巴"NOR;
			me->start_more(str);
			return 1;
		}
		if( objectp(obj = LOGIN_D->find_body(arg)) &&
			me->visible(obj) && interactive(obj))
		{
			arg = query_ip_number(obj);
			tmp = "\n"+ obj->name(1)+"("+ obj->query("id") +")\nIP："+ arg + "\n";
			tmp += "目前和此人从相同IP连入的玩家有：\n\t";
		}
		else tmp = "\n目前通过 " + arg + " 连入的玩家有：\n\t";
 		n=sscanf(arg,"%d.%d.%d.%d",ip1,ip2,ip3,ip4);
		myip = (ip1<<24)+(ip2<<16)+(ip3<<8)+ip4;
		while(i--)
		{
			if( obs[i] == obj ) continue;
			arg1 = query_ip_number(obs[i]);
			sscanf(arg1,"%d.%d.%d.%d",ip1,ip2,ip3,ip4);
			yourip = (ip1<<24)+(ip2<<16)+(ip3<<8)+ip4;
			if (query_ip_number(obs[i]) == arg ||
				(myip>>(8*(4-n)))==(yourip>>(8*(4-n))))
			{
				tmp += sprintf("%-15s ", obs[i]->query("name") + "("+obs[i]->query("id")+")");
				count++;
				if( count % 3 == 0 )
				{
					tmp += "\n\t";
					count = 0;
				}
			}
		}
		write(tmp+"\n");
		return 1;
	}
	
	groups = unique_array(obs, (: query_ip_number($1) :));
	if ( !sizeof(groups) ) return notify_fail(HIR"\n …… 完毕 …… \n"NOR);
	
	for(i = 0; i < sizeof(groups); i++)
	{
		if( sizeof( groups[i])  <= 1) continue;
		obs = groups[i];
		lob = obs->query_temp("link_ob") - ({0});
		ip = query_ip_number(obs[0]);
		tmp = sprintf("\n"HIY"%-16s"WHT" → "NOR, ip);
		for( j = 0; j < sizeof(obs); j++ )
		{
			if( j > 0 && j % 4 == 0 ) tmp += "\n\t\t    ";
			tmp += sprintf("%-8s", obs[j]->query("id"));
		}
		str += tmp;
		lob = sort_array(lob, (:strcmp($1->query("password"), $2->query("password")):));
		count = sizeof(lob);
		ip = j = 0;
		tmp = arg = "";
		while(count--)
		{
			if (lob[count]->query("password") != ip)
			{
				if (j > 1) arg += "(" +tmp+") ";
				ip = lob[count]->query("password");
				j = 0;
				tmp = "";
			}
			tmp += lob[count]->query("id")+", ";
			j++;
		}
	 	if (j > 1) arg += "(" +tmp+") ";
		if( arg != "" ) str += HIG"\n\t\t    口令相同的有："+arg+NOR;
		lob = sort_array(lob, (:strcmp($1->query("email"), $2->query("email")):));
		count = sizeof(lob);
		ip = j = 0;
		tmp = arg = "";
		while(count--)
		{
			if (lob[count]->query("email") != ip)
			{
				if (j > 1) arg += "(" +tmp+") ";
				ip = lob[count]->query("email");
				j = 0;
				tmp = "";
			}
			tmp += lob[count]->query("id")+", ";
			j++;
		}
		if (j > 1) arg += "(" +tmp+") ";
		if( arg != "" ) str += HIC"\n\t\t    Email相同的有："+arg+NOR;
	}

	str += HIR"\n  …… 完毕 …… \n"NOR;
	me->start_more(str);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：mipcheck [ip|某人]

例：
	mipcheck 210.34.4.1 列出从此ip连入的玩家。
	mipcheck 210.34.    列出从此ip范围内连入的玩家。
	mipcheck xxxxxxx    列出和此玩家相同ip的其它玩家。
	mipcheck all        列出所有登录玩家列表，按ip分列。
	mipcheck            列出所有相同ip的列表，附带相同email，passwd列表。
	
HELP
	);
	return 1;
}

