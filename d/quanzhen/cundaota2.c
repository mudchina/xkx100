// cundaota2.c 存道塔二层
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "存道塔二层");
        set("long", @LONG
这里是存道塔的二层，塔梯绕着塔内向塔顶延伸。这里空空如
也，经书也许全被全真弟子们借去阅读了。
LONG
        );
        set("exits", ([
                "eastup" : __DIR__"cundaota3",
                "eastdown" : __DIR__"cundaota1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2790);
	set("coor/y", 130);
	set("coor/z", 180);
	setup();
        replace_program(ROOM);
}