// guchang.c 晒谷场
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "晒谷场");
        set("long", @LONG
这里是村庄中心的晒谷场，地方不大，不过村里也就五、六户人
家，种的谷子也够晒了。现在正是收获的季节，谷场中堆满了谷子，
几个男女童子正在场中嬉闹，不时地扬起一捧谷子相互撒去。
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "southeast" : __DIR__"xiaocun",
                "north" : __DIR__"cunzhangjia",
                "northwest" : __DIR__"minju3",
                "southwest" : __DIR__"minju4",
        ]));
        set("objects", ([
                __DIR__"npc/boy" : 2,
                __DIR__"npc/girl" : 1,
        ]));

	set("coor/x", -3170);
	set("coor/y", 20);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}