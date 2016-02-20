// qiantang.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "钱塘江畔");
        set("long", @LONG
钱塘江，每年八月十八是观潮的好日子。“八月十八潮，壮观天
下无”。潮水来时“远若素练横江，声如金鼓；近则亘如山岳，奋如
雷霆”，刹那间，漫江沸腾，泼涛万顷，潮高丈馀，万马奔腾，真有
“涛来势转雄，猎猎驾长风。雷震云霓里，山飞霜雪中”的壮丽气势。
西上月轮山便到了六和塔。
LONG);
        set("exits", ([
            "north"     : __DIR__"road17",
            "westup"    : __DIR__"liuheta",
            "eastdown"  : "/d/binghuo/qiantang",
        ]));
        set("objects", ([
            __DIR__"npc/jian-ke" : 1,
        ]));
        set("outdoors", "xihu");
//        set("no_clean_up", 0);
	set("coor/x", 4000);
	set("coor/y", -1800);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
