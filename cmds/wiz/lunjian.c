inherit F_CLEAN_UP;

int main(object me,string arg)
{
  int level=-1;
	if (!wizardp(me))
	  return 0;
	if (arg=="少侠试剑" || arg=="1") 
	  level=0;
	else if (arg=="名侠比剑"|| arg=="2") 
	  level=1;
	else if (arg=="大侠评剑"|| arg=="3") 
	  level=2;
	else if (arg=="宗师论剑"|| arg=="4") 
	  level=3;
	else 
	  return notify_fail("只能指定 少侠试剑(1)、名侠比剑(2)、大侠评剑(3)、宗师论剑(4) 中的一个。\n");
	return PK_D->start_by_others(level);
}
int help(string arg)
{
write(@help
lunjian <指定的比赛>

该命令用于巫师手动开启华山论剑。
目前可以指定的比赛有：少侠试剑(1)、名侠比剑(2)、大侠评剑(3)、宗师论剑(4)。
help
);
return 1;
}