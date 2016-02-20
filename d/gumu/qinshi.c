// Room: /d/gumu/qinshi.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"琴室"NOR);
	set("long", @LONG
一张石桌(table)，一条石凳，桌上放着一把古琴(qin)，是小龙女
休憩时刻抚琴抒怀的地方。每每琴音袅袅，平淡清和，直引人心弛神往，
与世无争。
LONG	);
	set("exits", ([
		"west" : __DIR__"mudao18",
	]));
	set("item_desc", ([
		"qin"   : HIC"这是一把年代极远的古琴，琴风古朴，暗蕴玄机。
琴上刻着“至远 宁心 渡风”六个字。\n"NOR,
		"table" : "桌上放着一把古琴。 \n",
	]));
	set("coor/x", -3160);
	set("coor/y", 10);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_tan", "tan");
	add_action("do_tan", "play");
}

int do_tan(string arg)
{
	mapping fam;
	object me = this_player();
	int c_exp, c_skill;

	c_skill=(int)me->query_skill("force", 1);
	c_exp=me->query("combat_exp");

	if (arg == "qin")
	{
		if(!(fam = me->query("family")) || fam["family_name"]!="古墓派")
			return notify_fail("非古墓传人，怎能领悟古墓武功？\n");
		if (me->query("qi") < 30 || me->query("jing") < 30)
			return notify_fail("你精神恍忽，先去歇息一会再来弹琴吧。\n");
		write(HIC"你闭目调理一会气息，心神宁静的抚琴而弹。\n"NOR);
		if (c_skill < 50 )
			return notify_fail("你弹了半天，琴声仿若鸦鸣，你还是弹棉花去吧。\n");
		if (me->query_skill("force", 1) > 100)
		{
			message_vision(
HIC"$N心随弦走，融入琴境，伴随琴声，高声吟道：\n\n"
BLINK HIY"沧海一声笑 滔滔两岸潮\t浮沉随浪 只记今朝
苍天笑 纷纷世上潮\t谁负谁胜出 天知晓
江山笑 烟雨遥\t涛浪淘尽 红尘俗世几多娇
清风笑 竟惹寂寥\t豪情还剩了一襟晚照
苍生笑 不再寂寥\t豪情仍在 痴痴笑笑\n"NOR,me);
			return 1;
		}
		if( c_skill > 100)
			return notify_fail("你内功精湛，弹琴已无益于你修行内力。\n");
		write("你心随弦走，融入琴境，渐渐心气平和，周身真气自然流动。\n");
		me->receive_damage("qi", 15+random(10), me);
		me->receive_damage("jing", 15+random(10), me);
		if ((random(10)>3) && c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("force", random(me->query("int")) );
		return 1;
	}
	write("你要弹什么？弹棉花？\n");
	return 1;
}

