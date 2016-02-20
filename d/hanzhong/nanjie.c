// nanjie.c 南街
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "南街");
        set("long", @LONG
这里是汉中的南街，说是街，不过是一条小胡同而已。路上一个
人也没有。街的尽头有一扇小门。从这里往北，就是汉中镇的中心了。
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "north" : __DIR__"zhongxin",
                "southeast" : __DIR__"fu-cemen",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3150);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}