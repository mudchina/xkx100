// wang.c
// Last Modified by winder on May. 15 2001
inherit F_CLEAN_UP;

#include <room.h>
#include <ansi.h>

string *dd= ({
/* 城市 */
	"/mobei/", "/guanwai/", "/huijiang/", "/city/", "/beijing/", "/chengdu/", "/changan/", "/wuxi/", "/suzhou/", "/hangzhou/", "/fuzhou/", "/quanzhou/", "/lingzhou/", "/lanzhou/", "/luoyang/", "/xiangyang/", "/jiangling/", "/foshan/", "/jiaxing/", "/dali/", "/gaochang/", "/yixing/", "/hanzhong/", "/kaifeng/", "/nanyang/", "/yueyang/", "/yanping/", "/taiwan/",
/* 风景 */
	"/hasake/", "/shaolin/", "/nanshaolin/", "/wudang/", "/emei/", "/kunlun/", "/qingcheng/", "/huangshan/", "/taishan/", "/huashan/", "/henshan/", "/hengshan/", "/songshan/", "/qilian/", "/wuyi/", "/wuliang/", "/huanghe/", "/changcheng/", "/huanggong/", "/shouxihu/", "/beihai/",
/* 门派 */
	"/gaibang/", "/quanzhen/", "/gumu/", "/yanziwu/", "/tianlongsi/", "/xueshan/", "/xuedao/", "/baihuagu/", "/jueqinggu/", "/wanjiegu/", "/meizhuang/", "/guiyun/", "/village/", "/taohuacun/", "/taohua/", "/xiakedao/", "/binghuo/", "/shenlong/", "/xiaoyao/", "/lingjiu/", "/tiezhang/", "/heimuya/", "/mingjiao/", "/xingxiu/", "/baituo/", "/wudujiao/", "/heizhao/", "/jianzhong/", "/jinshe/", "lingxiao", "/shiliang/", "/yubifeng/",
	"/death/","/wuguan/","/wizard/",
});

void create() { seteuid(getuid()); }

int main(object me, string file)
{
	int i, bri=0, d1, d2, u1, u2;
	object *inv, env, *user;
	mapping exits;
	string str, str1, *dirs;
	int flag;

	if(!file)
	{
		str = HIM"                            玩家地域分布表\n                            ==============\n\n";
		user = users();
		u2 = sizeof(user);
		d2 = sizeof(dd);
		for (d1 = 0; d1 < d2; d1++)
		{
			flag=0;
			for (u1 = 0; u1 < u2; u1++)
			{
				env = environment(user[u1]);
				if(env)
				{
					str1 = file_name(environment(user[u1]));
					if(strsrch(str1, dd[d1]) >= 0)
					{
				   if (flag==0)
				   {
				   	flag=1;
    			  str+=HIY+to_chinese(replace_string(dd[d1],"/",""))+HIC"：";
				   }
				    str += user[u1]->query("name")+"、";
					}
				}
			}
			
			if (flag==1) str += "  \n"NOR;
		}
		this_player()->start_more(str);
		return 1;
	}
	if(file_size(file+".c")==-1)
	{
		env=find_object(file);
		if(!env) env=find_player(file);
		if(!env) env=find_living(file);
		if(!env) return notify_fail("没有这个地方或玩家！\n");
//		if( !me->visible(env) )
//			return notify_fail("没有这个地方或玩家！\n");
		if (living(env)) env=environment(env);
		if(!env) return notify_fail("这个环境不存在！\n");
	}
	else
	{
		if(!env=find_object(file)) env=load_object(file);
	}
//	str = sprintf( "%s - %s\n    %s%s",
	str = sprintf(HIC + "%s" + NOR +  " - %s\n    %s%s", env->query("short"), wizardp(me)? file_name(env): "", bri ? "\n":env->query("long"), env->query("outdoors") ?  NATURE_D->outdoor_room_description() : "" );
	if( mapp(exits = env->query("exits")) )
	{
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if((int)env->query_door(dirs[i],"status") & DOOR_CLOSED)
				dirs[i] = 0;
		dirs -= ({ 0 });
		if( sizeof(dirs)==0 )
			str += "    这里没有任何明显的出路。\n";
		else if( sizeof(dirs)==1 )
				str +="    这里唯一的出口是 " + BOLD HIY + dirs[0] + NOR + "。\n";
			else
				str += sprintf("    这里明显的出口是 " + BOLD HIY+ "%s" + NOR + " 和 " + BOLD HIY+ "%s" + NOR + "。\n", implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
	}
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++)
	{
		if( inv[i]==me ) continue;
		if( !me->visible(inv[i]) ) continue;
		str += "  " + inv[i]->short() + "\n";
	}

	write(str);
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: wang [place or sb.]
 
这个指令让你查看远处景物。
 
HELP
);
	return 1;
}

