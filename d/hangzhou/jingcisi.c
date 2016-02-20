// jingcisi.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "净慈寺");
        set("long", @LONG
净慈寺，原名慧日永明院，又叫兴教寺。净慈寺面向西湖，後拥
苍然挺秀的南屏山。往北就回到大道上。
LONG);
        set("exits", ([
            "north"   : __DIR__"road16",
            "enter"   : __DIR__"jingci",
        ]));
        set("no_clean_up", 0);
	set("coor/x", 4120);
	set("coor/y", -1510);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}