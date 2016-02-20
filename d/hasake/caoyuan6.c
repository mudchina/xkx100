// caoyuan6.c 草原
inherit ROOM;
void create()
{
        set("short", "大草原");
        set("long", @LONG
你走进了这遍绵绵不绝的大草原，脚下是寸厚的青草，软绵绵的还真
不好走，看来买匹马来代步到是的好主意。
LONG);
        set("exits", ([
           "southwest" : __DIR__"road2",
            "northwest" : __DIR__"room-ji",
            "east" : __DIR__"caoyuana",
            "north" : __DIR__"caoyuana",
            "south" : __DIR__"caoyuana",
            "west" : __DIR__"caoyuana",
        ]));
        set("outdoors", "hasake");
        setup();
        replace_program(ROOM);
}
