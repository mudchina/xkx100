// check.c
inherit F_CLEAN_UP;

#include <ansi.h>



/*string *skill_level_desc = ({
	BLU "初学乍练" NOR,
	HIB "粗通皮毛" NOR,
	HIB "半生不熟" NOR,
	HIB "马马虎虎" NOR,
	HIB "驾轻就熟" NOR,
	CYN "出类拔萃" NOR,
	CYN "神乎其技" NOR,
	CYN "出神入化" NOR,
	HIC "登峰造极" NOR,
	HIC "一代宗师" NOR,
	HIW "深不可测" NOR
});

string *knowledge_level_desc = ({
	BLU "新学乍用" NOR,
	HIB "初窥门径" NOR,
	HIB "略知一二" NOR,
	HIB "马马虎虎" NOR,
	HIB "已有小成" NOR,
	CYN "心领神会" NOR,
	CYN "了然於胸" NOR,
	CYN "豁然贯通" NOR,
	HIC "举世无双" NOR,
	HIC "震古铄今" NOR,
	HIW "深不可测" NOR
});
*/
string *skill_level_desc = ({
	BLU"不堪一击",BLU"毫不足虑",BLU"不足挂齿",BLU"初学乍练",BLU"勉勉强强",
	HIB"初窥门径",HIB"初出茅庐",HIB"略知一二",HIB"普普通通",HIB"平平淡淡",
	CYN"平淡无奇",CYN"粗通皮毛",CYN"半生不熟",CYN"马马虎虎",CYN"略有小成",
	HIC"已有小成",HIC"鹤立鸡群",HIC"驾轻就熟",HIC"青出于蓝",HIC"融会贯通",
	HIG"心领神会",HIG"炉火纯青",HIG"了然于胸",HIG"略有大成",HIG"已有大成",
	YEL"豁然贯通",YEL"出类拔萃",YEL"无可匹敌",YEL"技冠群雄",YEL"神乎其技",
	HIY"出神入化",HIY"非同凡响",HIY"傲视群雄",HIY"登峰造极",HIY"无与伦比",
	RED"所向披靡",RED"一代宗师",RED"精深奥妙",RED"神功盖世",RED"举世无双",
	WHT"惊世骇俗",WHT"撼天动地",WHT"震古铄今",WHT"超凡入圣",WHT"威镇寰宇",
	HIW"空前绝后",HIW"天人合一",MAG"深藏不露",HIM"深不可测",HIR"返璞归真" 
});

string *knowledge_level_desc = ({
	BLU"新学乍用",BLU"初窥门径",HIB"略知一二",HIB"半生不熟",
	CYN"马马虎虎",CYN"已有小成",HIC"融会贯通",HIC"心领神会",
	GRN"了然於胸",GRN"豁然贯通",YEL"非同凡响",YEL"举世无双",
	HIY"震古铄今",RED"无与伦比",WHT"超凡入圣",HIW"空前绝后",
});
string skill_level(string, int);

int main(object me, string arg)
{
	object ob, man, *all;
	mapping fam, skl, lrn, map;
	string *sname, *mapped;
	int sp, dp, i, cost, check_lvl, skl_lvl, adj_lvl;
/* adj_lvl是误差级别。等于100-checking级别 */

	seteuid(getuid());

	all = all_inventory(environment(me));
	for(i=0; i<sizeof(all); i++)
	{
		if( living(all[i]) && !userp(all[i]) ) man = all[i];
	}
	if ( (!(fam = me->query("family")) || fam["family_name"] != "丐帮") )
		return notify_fail("只有乞丐才能打探别人的技能！\n");
	if ( !objectp(man) )
		return notify_fail("周围没人能帮你去了解别人的技能！\n");
	check_lvl = me->query_skill("checking", 1);
	if ( check_lvl < 10 )
		return notify_fail("你的打探本领尚未纯熟，无法了解别人的技能！\n");
	if(check_lvl < 150) adj_lvl = 150 - check_lvl;
	else adj_lvl = 0;

	if ( !arg ) return notify_fail("你要打听谁的技能？\n");
	if ( present(arg, environment(me)) )
		return notify_fail("你要打听的人就在边上，在这里问不大妥当吧？\n");
	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("你要打听谁的技能？\n");
	if (!me->visible(ob))
		return notify_fail("你要打听谁的技能？\n");
	if ( ob == me )
		return notify_fail("你没这么笨吧，要别人告诉你自己的技能？\n");
	cost = me->query("max_jing")/(check_lvl/10) - 10;
	if ( me->query("jing") <= cost )
		return notify_fail("现在你太累了，无法去打听别人的技能。\n");

	tell_object(me, "你走上前去，小心翼翼地向" + man->name() + "打听关于" + ob->name() + "的情况 ...\n\n");
	message("vision", "只见" + me->name() + "陪着笑脸跟" + man->name() + "说着话，好象在打听些什么。\n\n", environment(me), ({ me, man }) );

	sp = check_lvl*10+me->query("kar")*5+me->query("jing")+man->query("jing");
	dp = ob->query("kar")*5 + ob->query("jing")*2;
	if ( random(sp) < random(dp) && !wizardp(ob))
		return notify_fail(man->name() + "摇了摇头，说道：这事我可不清楚，" + RANK_D->query_respect(me) + "还是去向别人打听一下吧！\n");
	me->receive_damage("jing", cost );
	skl = ob->query_skills();
	if(!sizeof(skl) || ob->query("yinshi"))
	{
		write(man->name() + "告诉你： " + ob->name() + "目前并没有学会任何技能。\n");
		return 1;
	}
	write(man->name()+"告诉你："+ob->name()+"目前所学过的技能大概有：\n\n");
	sname = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	 
	i = random(sizeof(skl));
	skl_lvl = skl[sname[i]]-adj_lvl/2+random(adj_lvl);
	if(skl_lvl < 0) skl_lvl = random(10) + 1;
	

	printf("%s%s%-40s"NOR" - %-10s"NOR" %3d/%5d\n", 
		(lrn[sname[i]]>=(skl[sname[i]]+1)*(skl[sname[i]]+1)) ? HIM : "",
		(member_array(sname[i], mapped)==-1? "  ": "□"),
		to_chinese(sname[i]) + " (" + sname[i] + ")",
		skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
		skl_lvl, (int)lrn[sname[i]],
	);
	if ( me->query("combat_exp") > (check_lvl*check_lvl*check_lvl)/10)
	{
		me->improve_skill("checking", random(me->query("int")));
	}

	write("\n");
	return 1;
}

string skill_level(string type, int level)
{
	int grade;


	switch(type) {
		case "knowledge":
	grade = level / 30;
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
	grade = level / 10;
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int help(object me)
{
	write(@HELP
指令格式 : check|dating [<某人>]

    这个指令可以让你打听别人所学过的技能。但是如果你技能不够精熟
的话，打听结果未免有偏差。

    你也可以指定一个和你有师徒关系的对象，用 skills|cha 可以查知
对方的技能状况。

    此命令为丐帮弟子专用，并需学习相应的技能。

HELP
	);
	return 1;
}
