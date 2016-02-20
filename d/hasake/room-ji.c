// room-ji.c 草棚

inherit ROOM;

void create()
{
        set("short", "草棚");
        set("long", @LONG
这是在部族东北部孤零零的一座草棚。这棚屋土墙草顶，形式宛如内
地汉人的砖屋，只是甚为简陋，旁边有一个小水漕。你悄悄的掩向小屋後
面，正想探头从窗子向屋内张望，那知窗内有一张脸同时探了上来。望北
去就是大戈壁了。
LONG
        );
        set("exits", ([
            "enter" : __DIR__"room-ji1",
            "south" : __DIR__"road2",
           "northwest" : __DIR__"gebi1",
            "southeast" : __DIR__"caoyuan6",
        ]));

        set("outdoors", "hasake");

        setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
       if( dir == "northwest" && !userp(me))
            return notify_fail("...\n");  
      
       return ::valid_leave(me,dir);
}
