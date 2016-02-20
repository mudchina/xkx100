// houhuayuan.c 后花园
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "后花园");
        set("long", @LONG
这里是一个小花园，杂乱地种着各种花草，看来无人打理，
杂草已经长得很高了。有一些红的，白的鲜花夹杂在草丛中，阵
阵花香不断地飘过。东面有一道小门，南面是一座两层小楼。
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "northwest" : __DIR__"fu-houyuan",
                "south"     : __DIR__"guanjinglou",
                "east"      : __DIR__"houhuayuan1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3120);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
