// abandon.c
// Modified by zeratul,2000.3.31

inherit F_CLEAN_UP;
#include <ansi.h>

mapping valid_skill = ([
/*
        "jiuyin-baiguzhao":  "九阴白骨抓",
        "bixie-jian":        "辟邪剑法",
        "zhengqijue":        "正气诀",
*/
]);
int main(object me, string arg)
{
	int skill_lvl, lvl=0, i;
	string skill, *sname;
	mapping smap, pmap, skl;

	smap = me->query_skill_map();
	pmap = me->query_skill_prepare();
	if(arg == "all" && wizardp(me))
	{
		skl = me->query_skills();
		if(!sizeof(skl))
		{
			write("你目前并没有学会任何技能。\n");
			return 1;
		}
		sname = sort_array( keys(skl), (: strcmp :) );
		write("你决定放弃学习所有技能。\n");
		for( i = sizeof(skl)-1; i >= 0; i--)
		{
			me->delete_skill(sname[i]);
		}
		for (i = sizeof(smap)-1; i >= 0; i --)
			me->map_skill(keys(smap)[i]);
		for (i = sizeof(pmap)-1; i >= 0; i -- )
			me->prepare_skill(keys(pmap)[i]);
		me->reset_action();
		return 1;
	}
	if(!arg || arg == "" || sscanf(arg, "%s %d", skill, lvl)!=2 &&
		sscanf(arg, "%s", skill)!=1)
		return notify_fail("你要放弃哪一项技能？\n");
	if( !undefinedp(valid_skill[skill]) )
		return notify_fail(to_chinese(skill)+"如附骨之蛆，让你无法放弃！\n");
	skill_lvl = me->query_skill(skill,1);
	if( lvl <0 )
		return notify_fail("技能级别不能为负。\n");
	if( lvl == skill_lvl && lvl>0)
		return notify_fail("你有问题啊。你不就是这级别么？\n");
	if( lvl > skill_lvl || lvl > 800)
		return notify_fail("你这项技能并没有学到这个级别。\n");
	if( undefinedp((me->query_skills())[skill]) )
		return notify_fail("你并没有学过这项技能。\n");
	if ((int)skill_lvl >= 100)
  {
  	write(HIW"确定将"+to_chinese(skill)+"("+skill+")"+
           "从"+HIR+chinese_number(skill_lvl)+HIW+"级放弃到"+
           HIR+chinese_number(lvl)+HIW+"级？(y/n)\n"NOR
           );
  	input_to("check_input",1,me,skill,lvl);
  }
  else
  {
		if( !me->delete_skill(skill) )
	    	return notify_fail("你并没有学过这项技能。\n");
  	write("你决定放弃继续学习" + to_chinese(skill) + "。\n");
		if( lvl > 0 ) me->set_skill(skill, lvl);
// 增加如下语句，当完全放弃某一项技能时，自动从enable列表中删除之，避免战斗中的Bad action。 Added by Spacenet@FXLT
		else 
		{
			for (i = sizeof(smap)-1; i >= 0; i --)
				if ((string)smap[keys(smap)[i]] == skill)
					me->map_skill(keys(smap)[i]);
// 放弃时也从prepare表中删除，Added by zeratul
			for (i = sizeof(pmap)-1; i >= 0; i -- )
				if ( ( string ) values(pmap)[i] == skill )
					me->prepare_skill(keys(pmap)[i]);
			me->reset_action();
		}
  }
  return 1;
}
int check_input(string arg,object me,string skill,int lvl)
{
	int i;
	mapping smap, pmap, skl;

	smap = me->query_skill_map();
	pmap = me->query_skill_prepare();
	if (strsrch(arg,"y")>=0)
	{
		if( !me->delete_skill(skill) )
	    	return notify_fail("你并没有学过这项技能。\n");
		if( lvl > 0 ) {
  		write(HIW"你决定放弃部分的" + to_chinese(skill)+"。\n"NOR);
			me->set_skill(skill, lvl);
		}
	// 增加如下语句，当完全放弃某一项技能时，自动从enable列表中删除之，避免战斗中的Bad action。 Added by Spacenet@FXLT
		else {
		write(HIW"你决心尽弃所学之" + to_chinese(skill) + "。\n"NOR);
			for (i = sizeof(smap)-1; i >= 0; i --)
				if ((string)smap[keys(smap)[i]] == skill)
					me->map_skill(keys(smap)[i]);
	// 放弃时也从prepare表中删除，Added by zeratul
			for (i = sizeof(pmap)-1; i >= 0; i -- )
				if ( ( string ) values(pmap)[i] == skill )
					me->prepare_skill(keys(pmap)[i]);
			me->reset_action();
		}
	return 1;
	}
	else
//  	write("你决定放弃继续学习" + to_chinese(skill) + "。\n");
	return 1;
}
int help()
{
	write(@TEXT
指令格式：abandon | fangqi <技能名称> [级别]

    这个指令用来完全或部分放弃一项你所学过的技能，如果不带级别数这个
参数则表示是完全放弃一项技能，将这项技能从你人物的资料中删除，如果你
以后还要练，必须从０开始重练，请务必考虑清楚。如果带了级别数这个参数
则表示部分放弃某技能，放弃到哪一级。

    例如：ｆａｎｇｑｉ ｌｉｔｅｒａｔｅ ５０  表示放弃后只剩下５０
级读书写字，这个指令使用的场合通常是用来删除一些不小心练出来的技能，
由于每个人有着不同的天赋，所修习的武功也不会相同。如果样样都学，到头
来只会样样不精。

TEXT
	);
	return 1;
}
