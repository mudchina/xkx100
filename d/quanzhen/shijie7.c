// shijie7.c 石阶
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
                "northup" : __DIR__"fangzhenqiao",
                "southdown" : __DIR__"shijie6",
        ]));
        set("objects",([
              __DIR__"npc/youke" : 1,
              __DIR__"npc/xiangke" : 1,
        ]));

	set("coor/x", -3140);
	set("coor/y", 130);
	set("coor/z", 180);
	setup();
        replace_program(ROOM);
}