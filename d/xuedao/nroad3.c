// nroad3.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","大雪山北麓");
        set("long",@LONG
这里山势比大雪山东面稍缓，也不是十分的严寒。山道两旁长得
有稀稀拉拉的一些野草。四下毫无人迹，只有几只秃鹰在高处盘旋，
俯视着茫茫雪山。
LONG );
        set("exits",([
                "south"     : __DIR__"nroad4",
                "eastdown"  : __DIR__"nroad2",
        ]));
        set("objects",([
                __DIR__"npc/lutianshu" : 1,
                __DIR__"npc/shuidai"   : 1,
                __DIR__"npc/eagle"     : 2,
        ]));
        set("outdoors", "xueshan");
	set("coor/x", -60000);
	set("coor/y", -9000);
	set("coor/z", 100);
	setup();
        replace_program(ROOM);
}