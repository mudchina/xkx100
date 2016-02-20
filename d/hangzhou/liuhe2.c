// liuhe2.c
// Date: Nov.1997 by Java
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "六和塔");
        set("long", @LONG
这里是六和塔的二层。窗(window)外是浓妆淡抹的西子湖，塔
中玲珑八角，青砖砌地，雕栏飞檐间粘连了些许蛛网。
LONG);
        set("exits", ([
            "down"  : __DIR__"liuhe1",
            "up"    : __DIR__"liuhe3",
        ]));
        set("objects", ([
            __DIR__"honghua/xinyan" :1,
            __DIR__"honghua/zhouyi" :1,
        ]));
        set("item_desc", ([
            "window": "从窗口望出去，钱江东去。近处农田中，有一农夫正荷锄耕耘。\n",
        ]));
        set("no_clean_up", 0);
	set("coor/x", 3890);
	set("coor/y", -1800);
	set("coor/z", 20);
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "up" &&
            objectp(present("xin yan", environment(me)))) 
            return notify_fail("心砚哈哈一笑：这里还没打过呢，就想上楼。\n");
        if (dir == "up" &&
            objectp(present("zhou yi", environment(me))))
            return notify_fail("周绮俏眼一瞪：没看见本姑娘在这里吗？\n");

        return ::valid_leave(me, dir);
}