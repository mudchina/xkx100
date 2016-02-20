// shijie1.c 石阶
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
这是一条整齐的石板路，依山而建，随着山势的曲折蜿蜒曲折。
由于山势陡了，当初修建这条石阶时肯定费了不小的功夫。走到这
里，已经可以看见全真教重阳观的檐角了。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"   : __DIR__"shijie2",
                "southdown" : __DIR__"daxiaochang",
        ]));

        set("objects",([
              __DIR__"npc/youke" : 1,
              __DIR__"npc/xiangke" : 2,
        ]));

	set("coor/x", -3170);
	set("coor/y", 120);
	set("coor/z", 130);
	setup();
        replace_program(ROOM);
}
