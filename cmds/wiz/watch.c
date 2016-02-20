// Last Modified by winder on Apr. 25 2001
// 看临时参数的命令文件
inherit F_CLEAN_UP;

#include <login.h>
#include <obj.h.es2>


string time_period(int timep);

int main(object me, string arg)
{
	int i, j, tim, sum=0;

	i = LOGIN_D->get_dienpc();
       j = LOGIN_D->get_madlock();
	tim = DISASTER_D->query_hj_startT();
	tim = time() - tim;
	sum += DISASTER_D->query_children("/clone/haojie/pker9.c");
	sum += DISASTER_D->query_children("/clone/haojie/pker8.c");
	sum += DISASTER_D->query_children("/clone/haojie/pker7.c");
	sum += DISASTER_D->query_children("/clone/haojie/pker6.c");
	sum += DISASTER_D->query_children("/clone/haojie/pker5.c");
	sum += DISASTER_D->query_children("/clone/haojie/pker4.c");
	sum += DISASTER_D->query_children("/clone/haojie/pker3.c");
	sum += DISASTER_D->query_children("/clone/haojie/pker2.c");
	sum += DISASTER_D->query_children("/clone/haojie/pker1.c");
	write("被杀 NPC人数："+i+"\n");
	write("系统封锁状态："+j+"\n");
	write("封锁持续时间："+time_period(tim)+"\n");
	write("当前杀手数量："+sum+"\n");
        return 1;
}

string time_period(int timep)
{
	int t, d, h, m, s;
	string time;
	if ( timep>=1800 ) return "已超时";
	t = timep;
	s = t % 60;	t /= 60;
	m = t % 60;	t /= 60;
	h = t % 24;	t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "天";
	else time = "";

	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";
	return time;
}
