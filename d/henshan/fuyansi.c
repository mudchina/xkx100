// Room: /d/henshan/fuyansi.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "福严寺");
        set("long", @LONG
福严寺为禅宗七祖怀让的道场，怀让在此宏扬顿悟法门。山门上匾
额“天下法院”正是当年写照，两边门联“六朝古刹”“七祖道场”字
迹剥落，颜色极古。山门墙山有古人留字(zi)，年代古远，犹历历可辨。 
寺内石柱有一对联(lian)，字迹圆润回转，不露机锋。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"shanlu9",
           "westup"     : __DIR__"sansheng",
           "northdown"  : __DIR__"shanlu8",
        ]));
        set("item_desc", ([
            "zi":
"\n
诸峰翠少中峰翠  五寺名高此寺名
石路险盘岚霭滑  僧窗高倚济寥明
凌空殿阁由天设  遍地松杉是自生
更有上方难上处  紫苔红藓远峥嵘
\n",
            "lian":
"\n
     福      般
     严      若
     为      是
     南      老
     山      祖
     第      不
     一      二
     古      法
     刹      门
\n",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -330);
	set("coor/y", -1070);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
