// Room: /t/wanjiegu/bridge.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "铁索桥");
        set("long", @LONG
一座横跨澜沧江的铁索桥，此桥共有四道铁索，两条在下，上
铺木板，以供行走，两条在旁，作为扶手。一踏上桥，几条铁索便
即晃动。江水荡荡，如快马奔腾从脚底飞过，只要一个失足，卷入
江水，任你多好的水性也难活命。
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"port2",
            "east" : __DIR__"port",
        ]));
        set("no_clean_up", 0);

	set("coor/x", -50060);
	set("coor/y", -19000);
	set("coor/z", -10);
	setup();
}

int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i;

        if(wizardp(me)) return 1;

        switch( random(5) ) {
            case 0: 
            inv = all_inventory(me);
                    if( !sizeof(inv) ) {
                        message_vision(HIW "$N在桥上晃了一下，差点儿掉入汹涌的澜沧江中！\n" NOR,me);
                        return notify_fail("");
                    } else {
                        i = random ( sizeof(inv) );
                        if(! inv[i]->query("no_drop") && !userp(inv[i])) {
                           message_vision(HIW "$N在桥上一晃，身上的"+inv[i]->name()+HIW+"掉入了澜沧江之中！\n" NOR,me);
                           destruct(inv[i]);
                           return notify_fail("");
                        }
                    }
            case 1:
            case 2:  
            message_vision( HIW "$N在桥上晃了一下，差点儿掉入汹涌的澜沧江中！\n" NOR,me);
            return notify_fail("");
            default: return 1;
        }
}