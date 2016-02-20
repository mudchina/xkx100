// Room: /d/henshan/beimen.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "正北门");
        set("long", @LONG
南岳大庙正北门是大庙的后门，正在衡山山麓。回望大庙，红墙黄
瓦，金碧辉煌。北面是上山的六小路。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"houdian",
           "northup": __DIR__"shanlu1",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1110);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
