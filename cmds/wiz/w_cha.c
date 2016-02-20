// skills.c
// 增加巫师察看不在线玩家技能的功能。
// Added by Spacenet@FXLT 1.18.2000

inherit F_CLEAN_UP;

#include <ansi.h>


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
	object ob;
	mapping skl, lrn, map;
	string *sname, *mapped, str, skill1;
	int i, flag = 0, parents = 0;

	seteuid(getuid());

	if(!arg || arg == me->query("id"))
		ob = me;
	else
	{
		if( sscanf(arg, "%s %s", arg, skill1) >= 3 )
			return notify_fail("你要察看什么？\n");
		ob = present(arg, environment(me));
//		if ( ob->query("SPSKILLS", 1)  ) return ob->skills();
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (wizardp(me))
		{
			if (!ob)
			{
				ob = new(USER_OB);
				seteuid(arg);
				export_uid(ob);
				flag = 1;
				if (!ob->restore())
					return notify_fail("没有这个玩家。\n");
			}
		}else
		{
			if (!ob) return notify_fail("你要察看谁的技能？\n");
		       	if( ob->query("parents"))
		       		if (member_array(me->query("id"), ob->query("parents")) >=0 )
		       			parents = 1;
		       		else return notify_fail("只有爹娘能察看宝宝的技能。\n");

		}
	}

	if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
	&& !me->is_apprentice_of(ob) && parents!=1 )
		return notify_fail("只有巫师或有师徒或亲情关系的人能察看他人的技能。\n");

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
		return 1;
	}
	write( (ob==me ? "你" : ob->name()) +"目前所学过的技能：\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	str = "\n";
	str += HIC"≡"HIY"─────────────────────────────────"HIC"≡\n"NOR;
	if (!skill1)
	{
		for(i=0; i<sizeof(skl); i++)
		{
			str += sprintf("%s%s%-40s"NOR" - %-10s "NOR"%3d/%5d  "HIM"%s\n"NOR, 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": "□"),
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],
			(wizardp(me) ? chinese_number((60-SKILL_D(sname[i])->learn_bonus()-SKILL_D(sname[i])->practice_bonus())/6) : ""));
		}
	}
	else
	{
		for(i=0; i<sizeof(skl); i++)
		{
			if (sname[i] == skill1)
			{
			str += sprintf("%s%s%-40s"NOR" - %-10s "NOR"%3d/%5d  "HIM"%d\n"NOR, 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": "□"),
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],
			(wizardp(me) ? chinese_number((60-SKILL_D(sname[i])->learn_bonus()-SKILL_D(sname[i])->practice_bonus())/6) : ""));
			}
		}
	}
//	write("\n");
	str += HIC"≡"HIY"─────────────────────────────────"HIC"≡\n"NOR;
	str += sprintf("%s\n", flag?"该玩家目前不在线上。":"");
	me->start_more(str);
	if (flag)
		destruct(ob);
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
// 宠物的技能。本命令不引用。在pet程序中引用。
string pet_skill(object ob)
{
	string desc;
	object  *list, couple_ob;
	mapping skl, lrn, map;
	string *sname, *mapped,target,cardname;
	int i, marry_flag;

	seteuid(getuid());
	skl = ob->query_skills();
	if(!sizeof(skl)) {
		desc =  ob->name() + "目前并没有学会任何技能。\n";
		return desc;
	}
		desc =  ob->name() +"目前所学过的技能：\n\n";
	sname  = sort_array( keys(skl), (: strcmp :) );

	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);

	for(i=0; i<sizeof(skl); i++)
	{
		desc += sprintf("%s%s%-40s" NOR " - %-10s "NOR"%3d/%5d\n",
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": "＊"),
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],);
	}
	return desc +"\n";
}

int help(object me)
{
	write(@HELP
指令格式 : skills|cha [<某人>] [<技能名>]

这个指令可以让你(你)查询所学过的技能。

你也可以指定一个和你有师徒关系的对象，用 skills 可以查知对方的技能状况。

巫师可以查询任何人或 NPC 的技能状况。

HELP
    );
    return 1;
}
