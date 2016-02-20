// hp cmds (Mon  09-04-95)
// Added by Spacenet@FXLT 1.18.2000 
inherit F_CLEAN_UP;
 
#include <ansi.h>
 

 
string status_color(int current, int max);
 
int main(object me, string arg)
{
	object ob;
	mapping my;
	int flag = 0;
 
	seteuid(getuid(me));
 
	if(!arg || arg == me->query("id"))
		ob = me;
	else
		{
			ob = present(arg, environment(me));
			if (!ob) ob = find_player(arg);
			if (!ob) ob = find_living(arg);
			if (!ob)
			{
				ob = new(USER_OB);
				seteuid(arg);
				export_uid(ob);
				flag = 1;
				if (!ob->restore())
					return notify_fail("没有这个玩家。\n");
			}
		}

	if (!ob->is_character())
		return notify_fail("那不是活物。\n");

	my = ob->query_entire_dbase();
    printf(HIC"≡"HIY"──────────────────────────────"HIC"≡\n"NOR);
    printf(HIC"【 精 气 】 %s%4d/ %4d %s(%3d％)" HIC "   【 精 力 】 %s%4d / %4d (+%d)\n" NOR,
		status_color(my["jing"], my["eff_jing"]), my["jing"], my["eff_jing"],
		status_color(my["eff_jing"], my["max_jing"]),	my["eff_jing"] * 100 / my["max_jing"],
		status_color(my["jingli"], my["max_jingli"]),	my["jingli"], my["max_jingli"],
		my["jiajing"] );
    printf(HIC"【 气 血 】 %s%4d/ %4d %s(%3d％)" HIC "   【 内 力 】 %s%4d / %4d (+%d)\n" NOR,
		status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
		status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / my["max_qi"],
		status_color(my["neili"], my["max_neili"]), my["neili"], my["max_neili"],
		my["jiali"] );

	if (ob->query("shen") >=0)
		printf(HIR"【 正 气 】%8d" HIC "              【 体 力 】 %s%4d / %4d \n"NOR,
		ob->query("shen"), 
		status_color(my["tili"], my["max_tili"]), my["tili"], my["max_tili"]);
	else
		printf(HIG"【 戾 气 】%8d" HIC "              【 体 力 】 %s%4d / %4d \n"NOR,
		ob->query("shen"), 
		status_color(my["tili"], my["max_tili"]), my["tili"], my["max_tili"]);

	printf(HIW"【 食 物 】 %s%4d/ %4d      " HIW "     【 潜 能 】  %s%d\n" NOR,
		status_color(my["food"], ob->max_food_capacity()),
		my["food"], ob->max_food_capacity(), HIY,
		(int)ob->query("potential") - (int)ob->query("learned_points"));
	printf(HIW"【 饮 水 】 %s%4d/ %4d      " HIW "     【 经 验 】  %s%d\n" NOR,
		status_color(my["water"], ob->max_water_capacity()),
		my["water"], ob->max_water_capacity(), HIM,
		my["combat_exp"] );
	printf(HIC"≡"HIY"──────────────────────────────"HIC"≡\n"NOR);
	
	if (flag) {
		printf("该玩家目前不在线。\n");
		destruct(ob);
	}
	return 1;
}
 
string status_color(int current, int max)
{
	int percent;
 
	if( max>0 ) percent = current * 100 / max;
	else percent = 100;
	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}
 
int help(object me)
{
	write(@HELP
指令格式 : hp
           hp <对象名称>                   (巫师专用)
 
这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。
 
see also : score
HELP
    );
    return 1;
}
