//room: changl15.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","画廊");
	set("long",@LONG
这是一条非常精美的长廊，柱子和栏杆是用华贵的紫檀木制成，上
面雕饰着美丽的图画，画工精巧，美不胜收。地板不知是用什么材料做
的，走在上面毫无声息，你只感到脚下软软的，非常舒服。一阵阵花香
从北边传来。
LONG );
	set("exits",([
		"west"  : __DIR__"changl7",
		"east"  : __DIR__"changl8",
		"south" : __DIR__"dating",
		"north" : __DIR__"huayuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -51000);
	set("coor/y", 30140);
	set("coor/z", 70);
	setup();
}

void init()
{
	object me = this_player();
	if((string)me->query("family/family_name")!="逍遥派"
	&& (string)me->query("family/family_name")!="灵鹫宫"
	)
	{
		if(random(3)>0)
		{
			me->receive_damage("qi",80);
			me->receive_wound("qi",80);
			message_vision(HIR"$N脚下一滑,...啊...,一声惨叫!\n"NOR,me);
			me->move(__DIR__"shanjiao");
			tell_object(me,HIR"你莫名其妙的到了山脚.\n"NOR);
		}
	}
}	