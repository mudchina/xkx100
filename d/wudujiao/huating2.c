// Room: /d/wudujiao/huating2.c

inherit ROOM;

void create()
{
        set("short", "栖凤亭");
        set("long", @LONG
这里是一个花园中的小亭子，雕梁画栋，古色古香。亭子当中立着几个木人。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "west" : __DIR__"huayuan2",
                "north" : __DIR__"huating1",
        ]));
        set("objects", ([
                 "/d/shaolin/obj/mu-ren": 4,
        ]));

	set("coor/x", -44890);
	set("coor/y", -81060);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}