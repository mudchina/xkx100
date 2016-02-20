// /d/shenlong/yaofang 药房
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "药房");
        set("long", @LONG
这是神龙岛的药房，靠墙放了许多柜子，抽屉中放满了许多中草药，
陆大夫常在这儿给岛上的众人抓药、诊治。不过陆大夫现在遇到点头疼
的事，如果你想要一些雄黄以避免岛上的毒蛇侵扰，只好去他的小屋了。
LONG
        );
	set("exits", ([
                "north" : __DIR__"zhulin1",
        ]));
	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

