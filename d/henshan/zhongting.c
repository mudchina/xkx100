// Room: /d/henshan/zhongting.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "钟亭");
        set("long", @LONG
钟亭内设铁钟一口，重九千斤。每逢山洪暴发，鸣钟镇洪，亦以示
警，声闻二十里外。 
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "west"   : __DIR__"kuixingge",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -290);
	set("coor/y", -1180);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
