// feilaifeng.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "飞来峰");
        set("long", @LONG
飞来峰又名灵鹫峰。沿着盘山小道往上走，只见溪盘岩石壁间雕
着一尊袒腹露胸，喜笑自若的弥勒佛。旁边是一座气魄雄伟的多闻天
王。北边是下山的路。小路往上延伸向东西两边。
LONG);
        set("exits", ([
                "north"     : __DIR__"road1",
                "eastup"    : __DIR__"qinglindong",
                "westup"    : __DIR__"longhongdong",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
	set("coor/x", 2500);
	set("coor/y", -1600);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
