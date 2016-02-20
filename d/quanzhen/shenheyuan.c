// shenheyuan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "神禾原");
        set("long", @LONG
此处位於终南山中部的翠华山附近。放眼望去，只见一片坦荡无
垠的大平原，夹在群山之间。传说商朝末年，姜子牙率兵伐纣攻打长
安时，粮草短缺，在此获神禾老汉之助，得米万斛，因此命名为神禾
原。往东南和北上各是一片树林。往南是一处遗迹。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "west"      : __DIR__"foyezhang",
                "north"     : __DIR__"shulin3",
                "southeast" : __DIR__"shulin2",
        ]));
        set("objects", ([
                "/d/hanzhong/npc/seller": 1,
        ]));

	set("coor/x", -3170);
	set("coor/y", 70);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
