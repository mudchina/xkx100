// caoyuan3.c 草原
inherit ROOM;
void create()
{
        set("short", "草原");
        set("long", @LONG
你走进了这遍绵绵不绝的大草原，脚下是寸厚的青草，软绵绵的还真
不好走，看来买匹马来代步到是的好主意。西边可以看见哈萨克帐篷，往
东去就是沙漠了。
LONG);
        set("exits", ([
            "southwest" : __DIR__"caoyuan2",
            "northwest" : __DIR__"shop",
            "northup" : __DIR__"road1",
            "southdown" : __DIR__"caoyuan",
        ]));
        set("outdoors", "hasake");
        setup();
        replace_program(ROOM);
}
