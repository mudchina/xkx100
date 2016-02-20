// Room: /d/henshan/mojingtai.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "磨镜台");
        set("long", @LONG
磨镜台位于燕子岩下，与半山亭一沟相邻。台前峰回路转，台旁古
松苍翠，环境清幽。相传南宗禅宗怀让在此宣扬 "顿悟法门" ，坐台高
僧斗法，怀让磨镜，智服北宗道一，此台因而传名。 "磨镜台之幽" 是
衡山大四绝之一。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"shanlu8",
           "westup"     : __DIR__"shanlu7",
           "northup"    : __DIR__"shanlu6",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -330);
	set("coor/y", -1050);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
