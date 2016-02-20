// xiaolu1.c 林间小径
// by Xiang

inherit ROOM;

void create()
{
        set("short", "林间小径");
        set("long", @LONG
你走在一条小径上，两旁种满了竹子，修篁森森，绿荫满地，除了
竹叶声和鸟鸣声，听不到别的动静。
LONG );
        set("exits", ([
                "south" : __DIR__"xiaolu2",
                "north" : __DIR__"houyuan",
        ]));
        set("objects", ([
                CLASS_D("wudang")+"/qingfeng": 1,
        ]));
        set("outdoors", "wudang");
	set("coor/x", -2050);
	set("coor/y", -940);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
