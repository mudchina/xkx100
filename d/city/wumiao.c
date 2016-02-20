// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "武庙");
	set("long", @LONG
这里是岳王庙的正殿，内有岳飞像，像上方悬挂岳飞手书“还我河
山”的横匾。殿两侧壁上嵌着“精忠报国”四个大字。武人到此，都放
下武器，毕恭毕敬地上香礼拜。旁边似乎有一道侧门。
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");

	set("valid_startroom","1");
	set("objects", ([
		__DIR__"obj/box" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"shilijie3",
		"up"   : __DIR__"wumiao2",
		"northwest": "/d/wizard/guest_room",
	]));
        create_door("northwest", "竹门", "southeast", DOOR_CLOSED);
	set("coor/x", 0);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        "/clone/board/wiz2_b"->foo();
}

void init()
{
	object me;
	me=this_player();
	if (!wizardp(me)) me->set("startroom",base_name(environment(me)));
	if (!wizardp(me)) me->save();
	return;
}