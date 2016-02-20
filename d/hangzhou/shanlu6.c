// shanlu6.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
山路崎岖，曲折蜿延。四周林木苍翠，修竹茂密。山路旁有一山
洞，据说洞里有时会传出虎哮声，故名老虎洞。西边是下山的路，往
东下山便到了山底。
LONG);
        set("exits", ([
            "eastup"  : __DIR__"yuhuangsd",
            "westdown": __DIR__"yuhuangshan",
        ]));
        set("objects", ([
            __DIR__"npc/laohu" : 1,
            __DIR__"obj/shuzhi" : 1,
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4090);
	set("coor/y", -1700);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
