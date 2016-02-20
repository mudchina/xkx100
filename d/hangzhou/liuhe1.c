// liuhe1.c
// Date: Nov.1997 by Java
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "六和塔");
        set("long", @LONG
这里是六和塔的底层。窗(window)外是浓妆淡抹的西子湖，塔
中玲珑八角，青砖砌地，雕栏飞檐间粘连了些许蛛网。
LONG);
        set("exits", ([
            "out"   : __DIR__"liuheta",
            "up"    : __DIR__"liuhe2",
        ]));
        set("objects", ([
            __DIR__"honghua/an" :1,
            __DIR__"honghua/meng" :1,
        ]));
        set("item_desc", ([
            "window": "从窗口望出去，钱江东去。近处农田中，有一农夫正荷锄耕耘。\n",
        ]));
        set("no_clean_up", 0);
	set("coor/x", 3890);
	set("coor/y", -1800);
	set("coor/z", 10);
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "up" &&
            objectp(present("an jiangang", environment(me))))
            return notify_fail("安健刚一把拦住你：瞎窜什么，过来吧你给我！\n");
        if (dir == "up" &&
            objectp(present("meng jianxiong", environment(me))))
            return notify_fail("孟健雄一把拦住你：要上楼，先过了我这关！\n");
        return ::valid_leave(me, dir);
}