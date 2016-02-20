//Room: shanhongpb.c 山洪瀑布
//Date: Oct. 2 1997 by Venus

inherit ROOM;
#include <ansi.h>
string look_hongshui();
int do_lian(string arg);

void create()
{
	set("short","山洪瀑布");
	set("long",@LONG
这里是一处峡谷，每年雨季山洪爆发时就形成了一处蔚为壮观的瀑
布。传说当年神雕侠杨过就是在这里练成绝世的玄铁剑法的。现在人去
谷空，只剩下空寥的山谷和奔腾的洪水(hongshui)。
LONG);
	set("outdoors", "huashan");
	set("no_clean_up", 0);
	set("item_desc", ([
		"hongshui" : (: look_hongshui :),
	]));
	set("exits",([ /* sizeof() == 1 */
		"southwest" : __DIR__"shaluo",
	]));
	set("coor/x", -900);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
}
string look_hongshui()
{
	return "这是一股奔腾不息的洪水，水中隐隐有个东西在发光，但你定睛\n仔细一看，发现那只不过是水面反射的日光罢了。\n";
}
void init()
{
	add_action("lian", "lian");
	add_action("lian", "practice");
}

int lian(string arg)
{
	string skillname;
	int skill, skill_basic, times, pertimes;
	object me=this_player();
	if (!arg)
	{
		write("你要练什么武功？\n");
		return 1;
	}
	if ( (sscanf(arg, "%s %d", arg, times)!=2 ))
		return notify_fail("指令格式：practice|lian <技能种类> <次数>\n");
	if ( times < 1 || times > 30)
		return notify_fail("练习次数必须大于一次，但不能超过三十次。\n");
	if (arg!="sword")
	{
		write("山洪流急，你没法练这种武功。\n");
		return 1;
	}
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");
	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");
	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("你只能练习用 enable 指定的特殊技能。\n");

	for (pertimes = 1; pertimes <=times ; pertimes ++)
	{
		skill_basic = me->query_skill(arg, 1);
		skill = me->query_skill(skillname, 1);
		if( skill < 1 )
			return notify_fail("你好像还没有学过这项技能吧？最好先去请教别人。\n");
		if( skill_basic < 1 )
			return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");
		if( skill_basic/2 <= skill/3 )
			return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

		notify_fail("你现在不能练习这项技能。\n");
		if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

		notify_fail("你试着练习" + to_chinese(skillname) + "，但是并没有任何进步。\n");
		if (skill*skill*skill/10 > (int)me->query("combat_exp")) 
		{
			return notify_fail("也许是缺乏实战经验，你的练习总没法进步。\n");
			return 1;
		}

		if( SKILL_D(skillname)->practice_skill(me) )
		{
			me->improve_skill(skillname, skill_basic/2 +1, skill_basic > skill? 0: 1);
			write(HIY"借助洪涛冲刷的威力，你的"+to_chinese(skillname)+"大有进步了！\n"NOR);
		}
		else return 0;
	}
}
