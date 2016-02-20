// sroad8.c
// Modified by Java Apr.27 1998
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","大雪山山谷");
        set("long",@LONG
一个宽大山谷, 群山环绕, 山顶上全是白闪闪的积雪, 山谷南方有两个山洞。
LONG );
        set("exits",([
                "enter"  : __DIR__"shandong1",
                "north"  : __DIR__"wangyougu",
                "northup": __DIR__"sroad7",
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
	set("coor/x", -110000);
	set("coor/y", -60000);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}