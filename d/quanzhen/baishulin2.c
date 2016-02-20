// baishulin2.c 柏树林
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "柏树林");
        set("long", @LONG
你走进了柏树林的深处，脚下踩着厚厚的落叶，松松软软。这里
的光线非常阴暗，你几乎什么都看不清了。突然一只松鼠从你眼前的
树枝上猛地跳了过去，吓了你一跳。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup" : __DIR__"baishulin4",
                "west" : __DIR__"baishulin1",
        ]));
        set("objects", ([
                __DIR__"npc/yunbao" : 1,
        ]));
	set("coor/x", -3130);
	set("coor/y", 30);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}