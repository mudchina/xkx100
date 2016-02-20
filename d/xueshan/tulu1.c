//      tulu1.c 土路

inherit ROOM;

void create()
{
        set("short","土路");
        set("long",@LONG
这是一条不起眼的土路，不宽却也不窄，松散的浮尘显露出来往行
商的频繁。它是连接雪山寺与中原的必经之路。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"caoyuan",
                "west" : __DIR__"tulu2",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30010);
	set("coor/y", -8030);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
