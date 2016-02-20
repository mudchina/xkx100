// /d/xiakedao/shihole6.c 侠客岛 石洞6

inherit ROOM;
#include <ansi.h>

int do_learn(string arg);
void create()
{
        set("short", "石洞");
        set("long", @LONG
眼前烛光黯淡，四周未见任何装饰，光秃粗糙的石壁上四字小篆，
正是最后一句总纲：「天人归真」，下面又有一行小字(xiaozi)。几
张石桌石凳随意地摆放着，似是杂乱无章，又似内藏玄机。
LONG );
        set("exits", ([
                "out"   : __DIR__"shihole5",
                "north" : __DIR__"shiroom21",
                "south" : __DIR__"shiroom22",
                "east"  : __DIR__"shiroom23",
                "west"  : __DIR__"shiroom24",
        ]));
        set("objects", ([
                CLASS_D("xiakedao")+"/long" : 1,
                CLASS_D("xiakedao")+"/mu"   : 1,
        ]));
        set("item_desc", ([
                "xiaozi": 
"小字写的是：「昔年余等沉溺无术，惟石公妙悟神功，盖因...」，
后面的字迹已模糊难辨。\n"
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3090);
	set("coor/y", -25600);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
   if (dir != "west" )  return ::valid_leave(me, dir);
   if (me->query_temp("winner")) return ::valid_leave(me, dir);
   return notify_fail(HIW"一股强大的力量自石洞中涌出，将你挡在洞外。\n"NOR);
}
