// Room: /d/wudujiao/minju9.c

inherit ROOM;

void create()
{
        set("short", "供桌下");
        set("long", @LONG
你现在蜷缩在低矮的供桌下面，四周到处都是灰尘和蜘蛛网，
稍一抬头就会碰到桌面。桌子四周被肮脏的布帘挡住了，你看不
到外面的情况，别人也发现不了你。
LONG
        );

        set("exits", ([
                "out" : __DIR__"minju7",
        ]));
        set("objects", ([
                  __DIR__"npc/zhanglang": 1,
        ]));
        set("coor/x", -44929);
	set("coor/y", -81010);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

