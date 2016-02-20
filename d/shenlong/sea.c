// /d/shenlong/sea.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;
#include <ansi.h>
int do_practice(string arg);

string *practice_types = ({
	"blade",
	"club",
	"staff",
	"stick",
	"sword",
	"whip",
	"cuff",
	"strike",
	"parry",
	"dodge",
});
	
int *cost(object, string);

void create()
{
	set("short","大海");
	set("long", @LONG
这是辽阔的海面，海风「呼呼」在你耳边吹过，海浪一个接着一个
向你泼打过来，突然一个巨浪打来几乎把你陷入旋涡中，你还是尽快离
开这儿吧。
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"south" : __DIR__"beach",
	]));
	set("outdoors", "shenlong");
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_practice", "practice");
	add_action("do_practice", "lian");
}

int do_practice(string arg)
{
	object *inv, weapon, me = this_player();
	string skillarg, str, multiple, skillname;
	int w, *cost, times, total, skill_special, skill_basic;
	mapping fam, skills, learned;

	skills = me->query_skills();
	learned = me->query_learned();
	skill_basic = me->query_skill(arg, 1);
	if( !stringp(skillname = me->query_skill_mapped(arg)) )
	{
		tell_object(me,"你必须有特殊武功方能与基本武技参照领悟！\n");
		return 1;
	}
	skill_special = me->query_skill(skillname, 1);

	if( skill_special < 1 )
	{
		tell_object(me,"你对这方面的技能还是一窍不通，最好从先从基本学起。\n");
		return 1;
	}	
	if( skill_basic > skill_special )
	{
		tell_object(me,"你" + to_chinese(skillname) + "功力不够，无法继续领悟" + to_chinese(arg) + "！\n");
		return 1;
	}
	skill_special = skill_special * me->query("max_jing") * 2 / (1000 + me->query("max_jing"));

	if( me->is_busy() )
	{
		tell_object(me, "你现在正忙着呢。\n");
		return 1;
	}
	if( me->is_fighting() )
	{
		tell_object(me, "你已经在战斗中了，学一点实战经验吧。\n");
		return 1;
	}
	if( !arg ) return ("/cmds/skill/enable")->main(me, arg);
	if(sscanf(arg, "%s %d", skillarg, times) != 2 )
		skillarg = arg;
	if( (w = member_array(skillarg, practice_types)) == -1 )
	{
		tell_object(me, "这项技能不能在这儿练习。\n");
		return 1;
	}
	if( w < 6 )
	{
		if( !objectp(weapon = me->query_temp("weapon")) )
		{
			tell_object(me, "你没有拿武器怎么练习？\n");
			return 1;
		}
		else
			if( weapon->query("skill_type") != skillarg )
			{
				tell_object(me, "你手中的武器不适合练你想练习的技能。\n");
				return 1;
			}
	}
	if( (int)me->query_skill(skillarg, 1) < 30 )
	{
		tell_object(me, "你还是先去跟师父多学习。\n");
		return 1;
	}
	if(!times || times == 0)
	{
		times = 1;
		multiple="";
	}
	else multiple="反复";
	switch(skillarg) {
		case "blade" :
		case "club"  :
		case "staff" :
		case "stick" :
		case "sword" : 
		case "whip"  : str = "挥舞" + weapon->name(); break;
		case "cuff"  : str = "挥舞双拳"; break;
		case "strike": str = "挥舞双掌"; break;
		case "parry" : str = "奋力拚博"; break;
		case "dodge" : str = "纵闪跳跃"; break;
	}		
	message_vision("$N在海浪中" + str + multiple + "练习着" + to_chinese(skillarg) + "。\n", me);

	for(times; times > 0; times--)
	{
		cost = cost(me, skillarg);
		if( (int)me->query("jing") < cost[0] ||
			 (int)me->query("qi") < cost[1] )
		{
			tell_object(me, "依你当前的状况来看你不能如此练习。\n");
			return 1;
		}
		me->receive_damage("qi", cost[1]);
		me->receive_damage("jing", random(skill_basic)/2,"冥思苦想把脑袋给想破了，白白的脑浆流了一地");
		me->improve_skill(skillarg, skill_special/8 + random(skill_special/4));

		total = (int)me->query("jing") + (int)me->query("qi");
		if( total < 500 && random(total) < 20 )
		{
			message_vision("突然一个巨浪打来，$N陷入旋涡中，立即被海水吞没了。\n", me);
			for(int i = 0; i < sizeof(inv); i++)
			{
				if( userp(inv[i]) )
					inv[i]->receive_wound("qi", 50 + inv[i]->query("max_qi"), "掉进海里淹死了");
				else destruct(inv[i]);
			}

			me->unconcious();
			me->move("/d/shenlong/beach");
			message("vision","你发现一个浑身水淋淋的家伙被海水冲上岸来，不由得走近一看，原来是"+me->name()+"\241\243\n", environment(me), ({me}));
			return 1;
		}
	}
	
	return 1;
}

int *cost(object ob, string skill)
{
	if( (int)ob->query("potential") > 0 && (int)ob->query("neili") > 10 )
	{
		if( !random(3) ) ob->add("potential", -1);
		else ob->add("neili", -8);
		return ({0, 0});
	}
	else
	{
		switch(skill)
		{
			case "blade" : return ({150, 300});
			case "club"  : return ({200, 250});
			case "staff" : return ({250, 200});
			case "stick" : return ({300, 150});
			case "sword" : return ({350, 100});
			case "cuff"  : return ({350, 200});
			case "strike": return ({200, 350});
			case "parry" : return ({150, 250});
			case "dodge" : return ({250, 150});
		}
	}
	return ({20, 20});
}

