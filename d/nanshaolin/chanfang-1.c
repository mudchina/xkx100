// Room: /d/nanshaolin/chanfang-1.c
// Last Modified by Winder on May. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "禅房");
	set("long", @LONG
这里是诵经的禅房。房中有一座小香炉，淡淡的清烟从中散出，弥
漫在整间房内。阳光透过窗格照在青石地上，在青烟中形成根根耀眼的
光柱。屋中的地上散放着几个蒲团，几个年青的僧人正闭目打坐于其上。
LONG
	);
	set("exits", ([
		"north" : __DIR__"chanfang-2",
		"south" : __DIR__"chanfang-3",
		"east"  : __DIR__"zdyuan",
	]));
	set("objects", ([
		CLASS_D("nanshaolin") + "/dafeng" : 1,
	]));
	set("no_fight", 1);
	set("coor/x", 1790);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
//	replace_program(ROOM);
}
void init()
{
	  add_action("do_ask", "chanwu");
}
int do_ask()
{
	object me;
	me = this_player();
	if ((int)me->query("jing")<35)
	{
		write(RED"你太累了精力无法集中。\n"NOR);
		return 1;
	} 
	if ((int)me->query_skill("buddhism",1)<50 &&
		present("moheseng dilu", me) )
	{
		write("你的禅宗修为不到，无法在此领悟禅理。\n");
		return 1;
	}
	if ((int)me->query_skill("buddhism",1)>101
		&& present("moheseng dilu", me) )    
	{
		write("大疯大师低声说道："+ RANK_D->query_respect(this_player()) +"的佛法已颇为渊深，已不需老衲指点。\n");
		return 1;
	}
	if ((int)me->query_skill("buddhism", 1) >= 50 &&
		(int)me->query_skill("buddhism", 1) <= 101 &&
		present("moheseng dilu", me) )
	{
		me->receive_damage("jing", 35);
		me->improve_skill("buddhism", me->query("int"));
		if ( random(5) == 0 )
			tell_object(me, RED"你听了大疯大师对于禅悟的讲解，顿时觉得禅宗心法有所提高。\n"NOR);
	}
	return 1;
} 
