// Room: /d/henshan/dadian.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "大殿");
        set("long", @LONG
这里是南岳大殿，供祭祀炎帝之用。大殿结构为重檐歇山顶，顶覆
七彩琉璃。殿高七十二尺，正面七间，有石柱七十二根，合南岳七十二
峰之数。殿中南岳圣帝宝相庄严。南岳庙之雄为衡山小四绝之一。 
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"yushulou",
           "north"  : __DIR__"houdian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1130);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
