// tongtiandian.c 通天殿
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "通天殿");
        set("long", @LONG
这里是供奉三清之末--通天教主的大殿，殿内的香烟不甚旺盛。
在通天教主的金身旁边，塑着几位截教道友象长耳仙、归云仙、申
公豹的塑像。
LONG
        );
        set("exits", ([
                "north" : __DIR__"laojundian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2770);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}