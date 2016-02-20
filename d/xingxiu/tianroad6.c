// room: /d/xingxiu/tianroad6.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;
#include <ansi.h>
string look_wind();
int lian(string arg);
void create()
{
	set("short", "天山顶峰");
	set("long", @LONG
这里是天山顶峰。从这里向周围望去，帕米尔高原的风光尽收眼底。
东面一条小路可以下山。山风(wind)凛冽，极为强劲，几乎无法站立。
LONG
	);
	set("exits", ([
		"eastdown" : __DIR__"tianroad5",
	]));
	set("item_desc", ([
		"wind" : (: look_wind :),
	]));
	set("objects", ([
		__DIR__"npc/snake" : 2, 
	]));
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	set("coor/x", -52020);
	set("coor/y", 20100);
	set("coor/z", 50);
	setup();
}

string look_wind()
{
	return
"这是一年到头永无止歇的来自极北溟海的玄风，刺面刮耳，\n"
"凛冽非常。\n";
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
	if (arg!="blade")
	{
		write("天风浩荡，你没法练这种武功。\n");
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
			write(HIY"借助天风浩荡的威势，你的"+to_chinese(skillname)+"大有进步了！\n"NOR);
		}
		else return 0;
	}
}
