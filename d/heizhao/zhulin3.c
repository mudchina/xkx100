// Room: /heizhao/zhulin3.c
// Date: Oct.28 1999 by Winder
inherit ROOM;

void create()
{
        set("short", "竹林");
        set("long",@LONG
凤尾森森，龙吟细细，竿竿青竹纵横交错，遮蔽天日。这里人
迹罕至，微风拂过竹林，发出沙沙之声，你只觉绿荫森森，幽静无
比，令人烦俗尽消。林中一道道石子铺成的羊肠小道向前延伸。
LONG );
        set("outdoors", "taoyuan");
        set("exits", ([
            "west" : __DIR__"zhulin4",
            "east" : __DIR__"zhulin2",
            "north": __DIR__"zhulin3",
            "south": __DIR__"zhulin1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -5020);
	set("coor/y", -1100);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}