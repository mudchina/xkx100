// Room: /d/tiezhang/pubu.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
void init()
{
	add_action("lingwu","lingwu");
}
void create()
{
	set("short", HIC"瀑布"NOR);
	set("long", @LONG
山路行到这里，忽听远处传来隐隐水声，转过一道山梁，只见一道
白龙似的大瀑布从对面双峰之间奔腾而下，空山寂寂，那水声在山谷中
激荡回响，声势甚是惊人。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"northup"  : __DIR__"xzfeng",
		"eastdown" : __DIR__"sblu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2070);
	set("coor/y", -1910);
	set("coor/z", 80);
	setup();
}

int lingwu(string arg)
{
	object me=this_player();
	string special;
	int bl,sl;

	if (!living(me)) return 0;
	if (me->is_busy() || me->is_fighting())
		 return notify_fail("你正忙着呢。\n");
//	if(!me->query("luohan_winner")) return notify_fail("你级别不够，不能在此领悟。\n");
	if (!arg) return notify_fail("你要领悟什么？\n");
	if (me->query_skill(arg,1) < 100)
		return notify_fail("你的根基不够领悟这种技能。\n");
	if (me->query_skill(arg,1) > 150)
		return notify_fail("你已经不能在这里领悟这项技能了。\n");
	if (!(special=me->query_skill_mapped(arg)))
		return notify_fail("你只能从特殊技能中领悟基本技能。\n");
	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") ||
		me->query("jing")*100/me->query("max_jing") < 20)
	{
		me->receive_damage("jing",bl/2);
		return notify_fail("你没办法集中精神。\n");
	}
	sl=me->query_skill(special,1);
	if (bl > sl)
		return notify_fail("你的"+ to_chinese(special)+"造诣不够，无法领悟更深一层的"+CHINESE_D->chinese(arg)+"。\n");
	write("你瞑思苦想，对"+to_chinese(arg)+"的体会又深了一层。\n");
	me->receive_damage("jing",bl/3);
	me->improve_skill(arg,sl/5+1);
	return 1;
}
