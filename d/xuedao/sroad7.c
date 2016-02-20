// sroad7.c
// Modified by Java Apr.27 1998
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","大雪山口");
        set("long",@LONG
群山环绕，四周积雪终年不化。南边不远处有一个山谷。
LONG );
        set("exits",([
                "eastdown"  : __DIR__"sroad6",
                "southup"   : __DIR__"sroad8",
        ]));
        set("objects",([
                __DIR__"npc/caiyaoren": 1,
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
	set("coor/x", -110000);
	set("coor/y", -50000);
	set("coor/z", 400);
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "southup")
        {
message_vision(HIW"突然轰隆一声巨响，$N脚下踏了个空，... 啊...雪崩了！\n"NOR, me);
                me->receive_damage("qi", 70);
                me->receive_wound("qi",  70);
                if( random(me->query_dex()) >= 7) 
                {
                        me->move(__DIR__"sroad8");
tell_object(me,HIW"只见大片的积雪从山峰上奔腾而下，向你铺天盖地地扑过来，沿途并夹带了不少岩石。赶紧逃命吧！\n"NOR);
message("vision",HIW"只见大片的积雪从山峰上奔腾而下，向"+me->query("name")+"铺天盖地地扑过来，沿途并夹带了不少岩石。赶紧逃命吧！\n"NOR,environment(me),me);
                        return notify_fail("");
                }
		else 
                {
                        me->move(__DIR__"sroad5");
tell_object(me,HIW"只见大片的积雪从山峰上奔腾而下，向你铺天盖地地扑过来，沿途并夹带了不少岩石。赶紧逃命吧！\n"NOR);
message("vision",HIW"只见大片的积雪从山峰上奔腾而下，向"+me->query("name")+"铺天盖地地扑过来，沿途并夹带了不少岩石。赶紧逃命吧！\n"NOR,environment(me),me);
                        return notify_fail("");
                }
        }
        else if( random(me->query("dex")) <= 10) 
        {
                me->move(__DIR__"sroad5");
tell_object(me,HIW"只见大片的积雪从山峰上奔腾而下，向你铺天盖地地扑过来，沿途并夹带了不少岩石。赶紧逃命吧！\n"NOR);
message("vision",HIW"只见大片的积雪从山峰上奔腾而下，向"+me->query("name")+"铺天盖地地扑过来，沿途并夹带了不少岩石。赶紧逃命吧！\n"NOR,environment(me),me);
                return notify_fail("");
        }
        return ::valid_leave(me,dir);
}