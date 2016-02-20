// jujingyuan.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "聚景园");
        set("long", @LONG
漫步园中，只见湖傍遍置垂柳。柳树丛中，种了不少碧桃。东风
送暖之时，这里“杨柳千条拂面丝，绿烟金穗不胜吹”。诗人刘禹锡
的“桃红李白皆夸好，须得垂杨相发挥”形容的恰到好处。东面是清
波门，往东北便是柳浪桥。
LONG);
        set("exits", ([
            "east"      : __DIR__"qingbomen",
            "northeast" : __DIR__"liulangqiao",
        ]));
        set("objects", ([
            __DIR__"npc/jian-ke" : 1,
            __DIR__"npc/honghua2" : 1,
        ]));
        set("outdoors", "xihu");
//        set("no_clean_up", 0);
	set("coor/x", 4120);
	set("coor/y", -1490);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
