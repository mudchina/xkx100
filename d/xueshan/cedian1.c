//      cedian1.c 侧殿
#include <room.h>
inherit ROOM;

void create()
{
        set("short","侧殿");
        set("long",@LONG
这里是雪山寺的东侧殿。殿内有神态各异的十八罗汉塑像，金旒玉
镶，很是庄严。
LONG );
        set("exits",([
                "up"   : __DIR__"zoulang1",
                "west" : __DIR__"dadian",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/jiamu" : 1,
                __DIR__"npc/xiang-ke"       : 3,
        ]));
	set("coor/x", -69990);
	set("coor/y", -19890);
	set("coor/z", 120);
	setup();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam=(mapping)me->query("family");
        if( (!myfam || myfam["family_name"] !="雪山寺") && dir=="up"
        && objectp(present ("jiamu huofo", environment(me))))
                return notify_fail("嘉木活佛说道: 你非雪山寺弟子, 不能入内。\n");
        return ::valid_leave(me,dir);
}
