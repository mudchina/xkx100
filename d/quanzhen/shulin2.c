// /d/quanzhen/shulin2.c 树林
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
这位于终南山间的一大片树林，生得颇为茂密。走在其间，只听
得脚下沙沙的落叶声，四周昏昏暗暗的，不时几道日光穿过浓密的枝
头，投射而下。偶尔远处几声兽吼声，更添了一分神秘感。往西北和
往东各有一条小径。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northwest"  : __DIR__"shenheyuan",
                "east"       : __DIR__"baoziyan",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/deer": 1,
        ]));
	set("coor/x", -3160);
	set("coor/y", 60);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
