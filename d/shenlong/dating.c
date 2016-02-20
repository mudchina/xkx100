// /d/shenlong/dating 大厅
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;
string* npcs = ({
	__DIR__"npc/boy",
	__DIR__"npc/boy2",
	__DIR__"npc/boy3",
	__DIR__"npc/boy4",
	__DIR__"npc/girl",
});
string look_jia();

void create()
{
	set("short", "大厅");
	set("long", @LONG
你来到了一个大厅之中，这厅硕大无朋，足可容得下千人之众，一
群群少男少女分五色站好，青、白、黑、黄四色的都是少年，穿红的却
是少女，背上各负短剑，每一队约有百人。每个队列之前都站着一个头
目。大厅四周有很多出口。四周竖着一排兵器架(shelf)。
LONG
	);
	set("exits", ([
		"out"   : __DIR__"tingkou",
		"east"  : __DIR__"shibanlu",
		"north" : __DIR__"zoulang",
	]));
	set("objects", ([
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		__DIR__"npc/yunsumei": 1,
		CLASS_D("shenlong")+"/wu": 1,
	]));
	set("item_desc", ([
		"shelf": (: look_jia :),
	]));
	set("weapon_count", 10);
	setup();
}

void init()
{
	add_action("do_get", "get");
}

int do_get(string arg)
{
	object weapon, me = this_player();
	string type;

	if(!arg) return 0;
	if( me->is_fighting() || me->is_busy() ) return 0;
	if( sscanf(arg, "%s from shelf", type) != 1) return 0;
	if( time() < me->query("sg/weapontime") + 300 && !wizardp(me))
	{
		tell_object(me, "你太贪心了，还是等一下再来吧。\n");
		return 1;
	}
	if(query("weapon_count") < 1)
	{
		tell_object(me, "兵器架空空如也，看来都给别人取光了吧。\n");
		return 1;
	}
	if( type != "armor" )
	{
		if( (int)me->query_skill(type, 1) < 1 )
		{
			tell_object(me, "你不会用这种武器。\n");
			return 1;
		}
	}
	switch(type)
	{
		case "sword":   if(me->query("gender") == "无性") 
					weapon = new(WEAPON_DIR"treasure/zhen");
				else weapon = new(WEAPON_DIR"sword/changjian");
				break;
		case "blade":   weapon = new(WEAPON_DIR"blade/gangdao");
				break;
		case "stick":   weapon = new(WEAPON_DIR"zhubang");
				break;
		case "staff":   weapon = new(WEAPON_DIR"gangzhang");
				break;
		case "hammer":   weapon = new(WEAPON_DIR"hammer/tongchui");
				break;
		case "whip" :   weapon = new(WEAPON_DIR"changbian");
				break;
		case "hook" :   weapon = new(WEAPON_DIR"hook");
				break;
		case "armor":   weapon = new(ARMOR_DIR"tiejia");
				break;
		default:	tell_object(me, "找不到"+type+"这种兵器。\n");
				return 1;
	}
	if( weapon->move(me) )
	{
		message_vision("$N从兵器架上取下一"+weapon->query("unit")+weapon->name()+"。\n", me);
		me->set("sg/weapontime", time());
	}
	else
	{
		destruct(weapon);
	}
	add("weapon_count", -1);
	return 1;
}

string look_jia() 
{
	string msg;

	msg ="这是一个兵器架，十八般武器是应有尽有。\n";
	msg+="目前存放有剑(sword)，刀(blade)，钩(hook)，棒(stick)，杖(staff)，锤(hammer)，鞭(whip)。还有一些铁甲(armor)。\n";
	msg+= "请用指令“get 种类 from shelf”拿取你称手的兵器或甲胄。\n";
	return msg;
}

int valid_leave(object me, string dir)
{
	if (dir == "east" &&
		me->query("party/party_name") !=HIY "神龙教" NOR &&
		present("wugen daozhang", environment(me)) &&
		living(present("wugen daozhang", environment(me))))
			return notify_fail("无根道长喝道：后面是本教重地，这位" + RANK_D->query_respect(me) + "请止步。\n");
	else return ::valid_leave(me, dir);

}
