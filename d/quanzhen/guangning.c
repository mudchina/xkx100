// guangning.c 广宁居
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "广宁居");
        set("long", @LONG
这里是全真七子之六郝大通的卧室，卧室很小，除了一张小床，
一张小茶几而外没有什么别的摆设。茶几晶莹透明，仔细一看，原来
几面是用整块的玉琢磨成的。茶几上摆放着几本先天课术的书，还有
一些卜卦用的金钱。
LONG
        );
        set("exits", ([
                "north" : __DIR__"piandian",
        ]));

        set("objects", ([
                CLASS_D("quanzhen")+"/hao" : 1,
        ]));
	set("coor/x", -2790);
	set("coor/y", 90);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}