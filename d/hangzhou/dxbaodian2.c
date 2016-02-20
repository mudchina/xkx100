// dxbaodian2.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "大雄宝殿");
        set("long", @LONG
殿内正中一尊如来佛像，两旁塑有二十尊诸天的佛像，大殿後壁
有五十三参海岛像，岛上有姿态各异的大小佛像一百五十个。
LONG);
        set("exits", ([
                "out"     : __DIR__"dxbaodian1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", 2500);
	set("coor/y", -1370);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}