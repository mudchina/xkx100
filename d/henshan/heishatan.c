// Room: /d/henshan/heishatan.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "黑沙潭");
        set("long", @LONG
黑沙潭又称黑龙潭，深不见底，水色苍黑，瀑布流急，水中黑泡共
白沫徜徉，幽幽可怖。石壁上 "海南龙湫" 四字据载为大宋徽宗赵佶所
留。瘦金字体，一如往昔。
LONG);
        set("exits", ([ /* sizeof() == 4 */
            "up"  : __DIR__"shanjian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -370);
	set("coor/y", -1060);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
    if ((random((int)me->query_skill("dodge")) <= 20) && dir=="up")    
    {
        return notify_fail("你使劲儿一蹦，离瀑布顶还有数丈远就掉了下来，摔的鼻青脸肿。\n");
    }
    if ((random((int)me->query_skill("dodge")) <= 35) && dir=="up")    
    {
        return notify_fail("你奋力一跃，却离瀑布顶还有一丈多远，看来是白费力气。\n");
    }
    if ((random((int)me->query_skill("dodge")) <= 60) && dir=="up")    
    {
        return notify_fail("你纵身而起，离瀑布顶只差一点点了，再加把劲。\n");
    }

    return ::valid_leave(me, dir);
}
