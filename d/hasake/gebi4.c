// gebi1.c
#include <room.h>
inherit ROOM;
void create()
{
       set("short","西域大戈壁");
       set("long", @LONG
这是西域的大戈壁，要走出这里并非易事。不远处尘土沙粒铺天盖
地般吹来，看来要起风暴了。
LONG);
        set("exits", ([
                "north" : __DIR__"gebi2",
                "south" : __DIR__"gebi3",
                "east" : __DIR__"gebi1",
                "west" : __FILE__,
        ]));
        set("outdoors", "hasake");
        set("no_quest",1);
        setup();
}
#include "gebi.h";