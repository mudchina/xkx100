// Room: god1

#include <ansi.h>
inherit ROOM;
inherit SKILL;

void create()
{
	set("short", HIY"天庭"NOR);
	set("long", HIC @LONG
这里就是天庭。祥云朵朵，色泽洁白无瑕，慢慢从你眼前飘过，那
翠绿色一片的草地上开满了色彩各异的鲜花，香气缭绕不散，闻着看着，
你都快要醉了。远处一栋洁白的宫殿，巍然耸入云霄，从那儿传来阵阵
仙乐，音律和祥悦耳，听着听着，你觉得自己的心灵都已得了到净化，
从此脱离了凡尘俗世……。这儿的一切都令你觉得安然、陶醉、宁静、
和祥……
LONG
NOR   );
	set("no_clean_up", 0);
	setup();
}

void reset()
{
	::reset();
	set("exits", ([ /* sizeof() == 2 */
		"up"   : __DIR__"god2",
		"down" : "/d/city/wumiao",
	]));
}

int valid_leave(object me, string dir)
{
	switch(dir)
	{
		case "up":
			write(HIC"你心如明镜，慢慢走向圣殿。\n"NOR);
			return 1;
		case "down":
			write(HIW"你要返回凡尘俗世了吗？……\n\n"NOR);
			break;
		default:
			write(HIG"唉……你既然心意已决，那就去吧……\n\n"NOR);
	}
	write(HIB"去吧……去吧……一个声音轻轻地说道。\n\n\n\n"NOR);
	write(HIY"你脚下忽然升起一朵祥云，你一踏上去，就慢慢向下飘去了，……\n\n\n\n"NOR);
	me->reincarnate();
/*
	me->add("combat_exp", (int)me->query("combat_exp") / 49);
	me->add("potential", 50);
	me->add("max_neili", 2);
	me->set("eff_jing",(int)me->query("max_jing"));
	me->set("eff_qi",(int)me->query("max_qi"));
	me->set("jing",(int)me->query("eff_jing"));
	me->set("qi",(int)me->query("eff_qi"));
	me->skillreincarnate();
*/
	return 1;
}
