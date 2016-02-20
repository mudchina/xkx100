// shanlu8.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
山上林木茂密，就是炎夏这里还是清凉依旧。朝北走便到了黄龙洞。
南边则是下山的路。
LONG);
        set("exits", ([
            "south"     : __DIR__"road7",
            "north"     : __DIR__"huanglongdong",
        ]));
        set("outdoors", "xihu");
        set("no_clean_up", 0);
	set("coor/x", 4090);
	set("coor/y", -1430);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
