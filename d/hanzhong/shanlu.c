// shanlu.c 山路
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
从汉中西门出来，路势变急了，这是一条用石块铺成的山路。路
两旁光秃秃的，没有什么树木，全是一块块的大石头。这条路好象通
往前面的终南山上。北面有一个小村庄，村中正升起冉冉的炊烟。
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "eastup"    : "/d/quanzhen/shanlu1",
                "northup"   : __DIR__"xiaocun",
                "southwest" : __DIR__"ximen",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3160);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
