// daxiaochang.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "大校场");
        set("long", @LONG
这是一个位於终南山山腰的圆坪，四周群山环抱。山脚下有一座
大池。每年腊月，全真派便於此地举行大校，以考察门下弟子在这一
年间的进境。往南是一条崎岖的山道。往西是一条通往峰顶的山路。
往北行便是重阳宫。只见远处十馀幢道观屋宇疏疏落落的散处山间。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"     : __DIR__"shijie1",
                "westup"      : __DIR__"shanlu13",
                "southdown"   : __DIR__"shanlu12",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/pi": 1,
        ]));

	set("coor/x", -3170);
	set("coor/y", 110);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
