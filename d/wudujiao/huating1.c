// Room: /d/wudujiao/huating1.c

inherit ROOM;

void create()
{
        set("short", "花厅");
        set("long", @LONG
这里是一个幽雅别致的花厅，四周挂着碧纱的幔帐，屋角香炉中飘着一
股奇异的香气。有一个粉红衣裙的少女正坐在窗边发呆，听见脚步声不觉瞟
了你一样，秀眉微微一颦，似乎不太高兴。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"huating2",
                "north" : __DIR__"huating3",
                "west"  : __DIR__"huayuan1",
        ]));
        set("objects", ([
                CLASS_D("wudujiao")+"/hetieshou": 1,
        ]));

	set("coor/x", -44890);
	set("coor/y", -81050);
	set("coor/z", 30);
	setup();
}
