// xijie.c 西街
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "西街");
        set("long", @LONG
汉中镇的西面是贫苦百姓的聚居区，西街比起其他几条街道来也
显得破朽杂乱得多。街南面是一座年久失修的小庙，已经摇摇欲坠了。
北面是一户低矮的茅屋，西面是汉中的西门。从这里转而往东，就走
到汉中镇的中心了。
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "east" : __DIR__"zhongxin",
                "north" : __DIR__"minju2",
                "south" : __DIR__"xiaomiao",
                "west" : __DIR__"ximen",
        ]));
        set("objects", ([
                __DIR__"npc/punk" : 1,
        ]));

	set("coor/x", -3160);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}