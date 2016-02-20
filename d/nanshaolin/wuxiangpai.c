// Room: /d/nanshaolin/wuxiangpai.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIB"无相牌"NOR);
	set("long", @LONG
通过无相牌进入无相禅师生前修真的密室，室内颇为灰暗，密不透
光。密室中摆着一个大铜缸，缸中盛满净水，波光粼粼。为室内添加一
点光亮据说无相大师当年受挫于昆仑高人之后，又寻张君宝不遇，愤懑
归寺，既隐居于此练掌(strike)，将掌法练到登峰造极之地步。其一生
武学秘奥尽藏于此斗室之中。
LONG );
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_strike","strike");
}
int do_strike(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("strike", 1), exp = me->query("combat_exp");

	if (arg!="shui") return 0;
	if (!living(me)) return 0;
	message("vision", me->name()+"对准铜缸中的水面发掌击出。\n", environment(me), ({me}) );
	if (lvl<30)
	{
		write(HIR"你功力太浅，铜缸中连水花也没溅出一点。\n"NOR);
 		return 1;
	}
	if (lvl * lvl * lvl / 10 < exp)
	{
		write(HIR"你经验太浅，铜缸中连水花也没溅出一点。\n"NOR);
		return 1;
	}
	if (lvl>100)
	{
		write(HIR"你掌力沉雄，铜缸内净水为你掌力所激，已回应之力。\n"NOR);
		return 1;
	}
        if (lvl >= 30 && lvl <= 100&&arg=="shui" )
	{
		if ((int)me->query("jing")<30)
		{
			me->unconcious();     
			return 0;
		}
                me->receive_damage("jing", 30);
                me->improve_skill("strike", (me->query("int"))*3/2);
                write(HIB"你对着水面遥遥发掌，缸内激起片片水花。你觉的掌力颇有精进。\n"NOR);
		return 1;
	}
}

