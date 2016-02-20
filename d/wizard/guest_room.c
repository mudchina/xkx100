// /d/wizard/guest_room.c

#include <room.h>
inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", "巫师会客室");
	set("long", @LONG
这里是巫师和玩家交流的地方，如果你有什么问题需要向巫师请
教，可以在这里留言(post)。不过如果问题牵涉到解谜或者已经在帮
助文件里有详细说明，巫师们就不一定会回答。楼上是巫师休息室，
一般玩家到这里后就上不去了。西边是新建的BUG留言室，如果有发现
什么bug，或者想看看处理的结果，都可以过去逛逛。
LONG );

	set("exits", ([
		"up": __DIR__"wizard_room",
		"southeast": "/d/city/wumiao",
		"west" : __DIR__"bug_room",
        ]));
	set("item_desc", ([
		"up": "不要偷窥。\n",	
        ]));
//  set("objects", ([
//      "/clone/npc/qingyun" : 1,
//  ]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	create_door("southeast", "竹门", "northwest", DOOR_CLOSED);
	setup();
	call_other("/clone/board/towiz_b", "???");
	"/clone/npc/qingyun"->move(this_object());
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}

