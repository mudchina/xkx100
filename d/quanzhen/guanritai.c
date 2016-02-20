// guanritai.c 观日台
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "观日台");
        set("long", @LONG
这里是终南山上的观日台，不知哪朝哪代何人在这里修筑了这个
平台，用来观瞻日出的美景。这里的山势非常陡峻，往下一看，悬崖
壁立，脚下白云飘过，真不知身在何境。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "north" : __DIR__"shijie9",
        ]));
        set("objects",([
                __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 1,
        ]));
	set("coor/x", -3150);
	set("coor/y", 80);
	set("coor/z", 180);
	setup();
        replace_program(ROOM);
}