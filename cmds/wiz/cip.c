
inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{
	object ob;
	seteuid(getuid());
	ob=find_object("/clone/misc/queryip");
	if (!ob)
  	ob=new("/clone/misc/queryip");
	ob->connect_to(arg);
  return 1;
}

int help(object me)
{
	write("指令格式：cip <ip|网址>

   用来查询玩家的所在之处。
   因为对玩家有一定影响，少用

   例如： cip 210.34.4.100
          cip 210.34.4
          cip www.sina.com.cn
");
	        return 1;
}