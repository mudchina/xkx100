// road5.c 山路

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是侠客岛的后山，你走在一条岩石嶙峋的山道上，这是通向
侠客岛 "望云台" 的唯一路径，旁边是万丈悬崖，抬头隐约可见笼
罩在云雾中的山峰，一条山路环山而行。
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
                "southup" : __DIR__"road6",
                "north" : __DIR__"shidong8",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3110);
	set("coor/y", -22110);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}