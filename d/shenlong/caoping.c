// /d/shenlong/caoping.c
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>
inherit ROOM;
string* flowers = ({
	__DIR__"obj/hua",
	__DIR__"obj/hua",
	__DIR__"obj/hua3",
	__DIR__"obj/hua2",
	__DIR__"obj/hua3",
	__DIR__"obj/hua4",
});
string* npcs = ({
	__DIR__"npc/boy",
	__DIR__"npc/boy2",
	__DIR__"npc/boy3",
	__DIR__"npc/boy4",
	__DIR__"npc/girl",
	__DIR__"npc/boy",
	__DIR__"npc/boy2",
	__DIR__"npc/boy3",
	__DIR__"npc/boy4",
	__DIR__"npc/girl",
	__DIR__"npc/girl",
});

void create()
{
	set("short", "草坪");
	set("long", @LONG
这里是一片青青的草坪，有几个少年在玩耍。四周开满了各色的鲜
花，一阵凉风吹过，清新的空气中传来几缕淡淡的花香。
LONG );
	set("exits", ([
		"east" : __DIR__"kongdi",
	]));
	set("objects", ([
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		flowers[random(sizeof(flowers))] : 1,
		flowers[random(sizeof(flowers))] : 1,
		flowers[random(sizeof(flowers))] : 1,
	]));
	set("outdoors", "shenlong");
	set("coor/x", 3990);
	set("coor/y", 3030);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("duanchang", environment(me)))) 
	{
		if((int)this_player()->query_condition("flower_poison") < 10 )
		{
			this_player()->apply_condition("flower_poison", 30);
			tell_object(me,HIG"你只觉一股淡香袭来，顿时脑中一阵麻木！\n"NOR);
		}
	}
	return ::valid_leave(me, dir);
}

