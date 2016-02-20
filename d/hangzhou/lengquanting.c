// lengquanting.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "冷泉亭");
        set("long", @LONG
冷泉亭建在灵隐寺西边，亭下小溪清澈见底，游鱼往复，历历可
数。亭边就是飞来峰。亭柱两旁有一对联(duilian)。
LONG);
        set("exits", ([
            "east" : __DIR__"lingyinsi",
        ]));
        set("item_desc", ([
            "duilian" :
"泉          峰
自          从
几          何
时          处
冷          飞
起          来
？          ？\n"
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
	set("coor/x", 2490);
	set("coor/y", -1400);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
