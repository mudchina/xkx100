// datang2.c 大堂二进
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "大堂二进");
        set("long", @LONG
这里是大堂的第二重，是全真教弟子做功课的所在。现在还不到
功课时间，大堂里空荡荡的，只有全真教掌管上下杂事的掌理道长带
领着几个小道童在整理桌椅，预备餐饭。
LONG
        );
        set("exits", ([
                "east" : __DIR__"datang3",
                "west" : __DIR__"datang1",
                "north" : __DIR__"cetang",
                "south" : __DIR__"piandian",
        ]));
        set("objects",([
                CLASS_D("quanzhen")+"/zhangli" : 1,
                __DIR__"npc/daotong1" : 1,
        ]));
	set("coor/x", -2790);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}