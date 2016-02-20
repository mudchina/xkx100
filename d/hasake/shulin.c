// shulin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short",HIY"山陵"NOR);
       set("long", @LONG
突然之间，西北方出现了一片山陵，山上树木苍葱，在戈壁中突然看到，
真如见到世外仙山一般。大戈壁上丘陵起伏，几个沙丘将这片山陵遮住了，
因此远处完全望不见。
LONG);
        set("exits", ([
                "west" : __DIR__"gebi2",
                "south" : __DIR__"gebi1",
                "east" : __DIR__"gebi4",
                "northwest" : __DIR__"shulin1",
        ]));
        set("outdoors", "hasake");
        set("no_quest",1);
        setup();
       replace_program(ROOM);
}