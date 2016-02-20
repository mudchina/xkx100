// pilidan.c 霹雳弹
#include <ansi.h>
#include <command.h>
inherit ITEM;
void create()
{
	set_name(HIC"霹雳弹"NOR, ({"pilidan", "dan"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一粒精致但威力无比的霹雳弹。\n");
		set("unit", "粒");
		set("value", 100);
	}
}

void init()
{
	add_action("do_apply","apply");
}
int do_apply(string arg)
{
	object me,ob;
	object *inv;
	int i;

	me = this_player();
	if( environment(me)->query("no_fight") )
		return notify_fail("你要搞破坏啊。\n");
	if(!id(arg)) return notify_fail("你要搞什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要搞什么？\n");

	if (me->is_busy()) return notify_fail("你正在忙啊。\n");

	tell_room(environment(me),me->query("name")+"的手猛地向下一掷，一声巨响，大家什么也看不见，一片混乱中四散逃开。\n"NOR);

	inv = all_inventory(environment(me));
	for(i=0; i<sizeof(inv); i++)
	{
		ob=inv[i];
		ob->set_temp("no_follow",1);
		if( (ob->is_character()) && (!ob->is_corpse()) )
		{
			GO_CMD->do_flee(ob);
		}
	}

	destruct(this_object());
	return 1;
}
