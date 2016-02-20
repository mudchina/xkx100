// Room: /d/nanshaolin/huizhizuo.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIG"晦智圣座"NOR);
	set("long", @LONG
晦智禅师圣座内修真之处原是一间石洞，入得洞来只见青石铺地竟
是颇为宽敞，几处钟乳珠缨金络，晶壁玉障。不但合洞通明亮入白昼；
玉床碧几，不染纤尘。而且石室修整，门户井然，到处光华灿烂，目迷
五色。想是禅师有意于世俗富贵眩目之气内修真，更增禅心。四壁各雕
了一座千手如来佛像姿态各不相同，栩栩如生，凝望之下令人忘俗。
LONG );
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_ningwang",({"gaze","ningwang"}));
}
int do_ningwang(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("hand", 1), exp = me->query("combat_exp");
	if (arg!="foxiang") return notify_fail("你要凝望什么？\n");
	if (!living(me)) return 0;
	if (!random(5))
	message("vision", me->name()+"正在对着墙壁凝神观看佛像的手法。\n", environment(me), ({me}) );
	if (lvl < 30)
	{
		write("你凝望佛像，但觉千手繁复，实无半点脉络可寻。\n");
		return 1;
	}
        if (lvl * lvl * lvl / 10 < exp)
        {
                write(HIR"你凝望佛像，心中似有所悟，但毕竟经验尚浅，什么也没领悟到。\n"NOR);
                return 1;
        }
	if (lvl > 100)
	{
		write("佛像姿势虽繁但你已尽数领悟于心。\n");
		return 1;
	}
        me->receive_damage("jing", 30);
        me->improve_skill("hand", (me->query("int"))*3/2);
        write("你望着佛像千奇百怪之手法，心中对基本手法有所领悟。\n");
	return 1;
}
