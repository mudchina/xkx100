// Room: /d/henshan/jigaoming.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "极高明台");
        set("long", @LONG
这里是福严寺最高处。唐邺侯李泌手书 "极高明" 三个大字于此，
意即佛相极高 (高无见顶相) ，佛光极明 (明不借他光) ，佛是至高无
上的，故曰极高明台。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "northdown"  : __DIR__"sansheng",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -340);
	set("coor/y", -1080);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
