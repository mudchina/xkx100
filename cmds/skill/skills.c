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
// 基本武功和特殊武功查不出区别 暂时列表处理
string *all_basic= ({
"array",	"axe",			"blade",	"claw",		"club",	
"cuff",		"dagger",		"dodge",	"finger",	"force",	
"hammer",	"hand",			"hook",		"leg",		"magic",
"parry",	"spear",		"staff",	"stick",	"strike",
"sword",	"throwing",	"unarmed","whip",
});
string skill_level(string, int);

int main(object me, string arg)
{
	object ob;
	mapping skl, lrn, map;
	string *sname, *mapped, str, skill1;
	string msg_sk_know="",msg_sk_basic="",msg_sk_sp="",msg_sk_other="";
	string str_this;
	int num_know=0, num_basic=0, num_sp=0, num_other=0;
	int i, flag = 0, parents = 0;

	seteuid(getuid());

	if(!arg || arg == me->query("id"))
		ob = me;
	else
	{
		ob = present(arg, environment(me));
		if (!ob)
		{
			if( sscanf(arg,"of %s",arg)!=1 )
		if( sscanf(arg,"%s of %s",skill1,arg)!=2 )
		if( sscanf(arg, "%s %s", arg, skill1)>2 )
			return notify_fail("你要察看什么？\n");
//		if ( ob->query("SPSKILLS", 1) ) return ob->skills();
		if (!ob) ob = present(arg, environment(me));
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
				 {
				 	destruct(ob);
					return notify_fail("没有这个玩家。\n");
         }
			}
		}else
		{
			if (!ob || !me->visible(ob)) return notify_fail("你要察看谁的技能？\n");
				if( ob->query("parents"))
					if(member_array(me->query("id"), ob->query("parents")) >=0 )
						parents = 1;
				else return notify_fail("只有爹娘能察看宝宝的技能。\n");
		}
	}
	}

	if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me) &&
		!me->is_apprentice_of(ob) && parents!=1 && me->query("couple/couple_id")!=ob->query("id"))
		return notify_fail("只有巫师或有师徒或亲情关系的人能察看他人的技能。\n");

	skl = ob->query_skills();
	if (skill1 && !ob->query_skill(skill1))
	{
		write( (ob==me ? "你" : ob->name()) + "并没有学会这项技能。\n");
		if (flag==1) destruct(ob);
		return 1;
	}
	if(!sizeof(skl))
	{
		write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
		if (flag==1) destruct(ob);
		return 1;
	}
	sname = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	str = "\n";
//	str += HIC"≡"HIY"─────────────────────────────────"HIC"≡\n"NOR;
	if (!skill1)
	{
		str+=(ob==me ? "你" : ob->name()) +"目前共学过"+chinese_number(sizeof(skl))+"项技能：\n\n";
		for(i=0; i<sizeof(skl); i++)
		{
			str_this=sprintf("│%s%s%-36s"NOR" - %-10s "NOR"%3d/%6d│"HIM"%s"NOR"\n", 
				(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
				(member_array(sname[i], mapped)==-1? "  ": "□"),
				to_chinese(sname[i]) + " (" + sname[i] + ")",
				skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
				skl[sname[i]], (int)lrn[sname[i]],
				(wizardp(me) ? chinese_number((65-SKILL_D(sname[i])->learn_bonus()-SKILL_D(sname[i])->practice_bonus())/6) : "  "));
			if(member_array(sname[i], all_basic)>-1)
			{
				msg_sk_basic+=str_this;
				num_basic+=1;
			} 
			else 
			switch (SKILL_D(sname[i])->type())
		 	{
				case "knowledge":
				{
				msg_sk_know+=str_this;
				num_know+=1;
				break;
				}			
				case "martial":
				{
				msg_sk_sp+=str_this;
				num_sp+=1;	
				break;		
				}
				default:
				{
				msg_sk_other+=str_this;
				num_other+=1;
				}
			}//end switch	
	}//end for
		if (num_know>0)
		{
			str+=sprintf("%s%|20s%s"NOR,
			"┌──"+HIY,
			chinese_number(num_know)+"项知识技能",
			NOR+"──────────────────┐\n");
			str+=msg_sk_know;
			str+="└──────────────────────────────┘\n";
		}
		if (num_basic>0)
		{
			str+=sprintf("%s%|20s%s"NOR,
			"┌──"+HIY,
			chinese_number(num_basic)+"项基本技能",
			NOR+"──────────────────┐\n");
			str+=msg_sk_basic;
			str+="└──────────────────────────────┘\n";
		}
		if (num_sp>0)
		{
			str+=sprintf("%s%|20s%s"NOR,
			"┌──"+HIY,
			chinese_number(num_sp)+"项特殊技能",
			NOR+"──────────────────┐\n");
			str+=msg_sk_sp;
			str+="└──────────────────────────────┘\n";
		}
		if (num_other>0)
		{
			str+=sprintf("%s%|20s%s"NOR,
			"┌──"+HIY,
			chinese_number(num_other)+"项其它技能",
			NOR+"──────────────────┐\n");
			str+=msg_sk_other;
			str+="└──────────────────────────────┘\n";
		}
		

	}
	else
	{
	str+=(ob==me ? "你" : ob->name()) +"目前学习"+to_chinese(skill1)+"技能的情况如下：\n";
			str+="┌──────────────────────────────┐\n";
			str += sprintf("│%s%s%-36s"NOR" - %-10s "NOR"%3d/%6d│"HIM"%s"NOR"\n", 
			(lrn[skill1] >= (skl[skill1]+1) * (skl[skill1]+1)) ? HIM : "",
			(member_array(skill1, mapped)==-1? "  ": "□"),
			to_chinese(skill1) + " (" + skill1 + ")",
			skill_level(SKILL_D(skill1)->type(), skl[skill1]),
			skl[skill1], (int)lrn[skill1],
			(wizardp(me) ? chinese_number((65-SKILL_D(skill1)->learn_bonus()-SKILL_D(skill1)->practice_bonus())/6) : ""));
			str+="└──────────────────────────────┘\n";
	}
//	write("\n");
//	str += HIC"≡"HIY"─────────────────────────────────"HIC"≡\n"NOR;
	str += sprintf("%s", flag?"该玩家目前不在线上。\n":"");
//	me->start_more(str);
	write(str);
	if (flag)
		destruct(ob);
	return 1;
}

string skill_level(string type, int level)
{
	int grade;


	switch(type)
	{
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
	object *list, couple_ob;
	mapping skl, lrn, map;
	string *sname, *mapped,target,cardname;
	int i, marry_flag;

	seteuid(getuid());
	skl = ob->query_skills();
	if(!sizeof(skl)) {
		desc = ob->name() + "目前并没有学会任何技能。\n";
		return desc;
	}
		desc = ob->name() +"目前所学过的技能：\n\n";
	sname = sort_array( keys(skl), (: strcmp :) );

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
           skills|cha [<技能名>] of <某人>
           
    这个指令可以让你查询所学过的技能。

    你也可以指定一个和你有师徒关系的对象，用此命令可以查知对方
的技能状况。

    巫师可以查询任何人或 NPC 的技能状况。

HELP
	);
	return 1;
}
