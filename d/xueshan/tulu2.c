//      tulu2.c 土路

inherit ROOM;

void create()
{
        set("short","土路");
        set("long",@LONG
这是一条不起眼的土路，却是连接雪山寺与中原的必经之路。西边
点点的炊烟依稀可见。往北可以通往声震西域的雪山寺。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"tulu1",
                "north" : __DIR__"tulu3",
                "west" : __DIR__"kedian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30020);
	set("coor/y", -8030);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
