// Room: /d/henshan/cangjingdian.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "藏经殿");
        set("long", @LONG
藏经殿深掩祥光峰下，因藏明太祖所赠 "大藏经" 故名。这里古木
参天，殿宇飘翼，奇花异草，林壑幽深，景色秀丽， "藏经殿之秀" 是
衡山大四绝之一。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "east"   : __DIR__"shanlu14",
           "south"  : __DIR__"shuzhuangtai",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -340);
	set("coor/y", -1010);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
