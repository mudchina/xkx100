// caoyuana.c 草原
inherit ROOM;
void create()
{
        set("short", "草原边缘");
        set("long", @LONG
这里是大草原和沙漠接壤之地，青草由稀至密，向西绵绵延伸而去。
地上有几行骆驼踏过的蹄印，看样子这里常常有商队来往。西南方好象有
些炊烟。
LONG);
        set("exits", ([
           "east" : __FILE__,
            "southwest" : __DIR__"caoyuan1",
            "northwest" : __DIR__"caoyuan2",
            "northup" : __DIR__"caoyuan3",
            "north" : __DIR__"caoyuan",
            "south" : __DIR__"caoyuan",
        ]));
        set("outdoors", "hasake");
        setup();
}
