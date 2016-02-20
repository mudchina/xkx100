//      tulu3.c 土路

inherit ROOM;

void create()
{
        set("short","土路");
        set("long",@LONG
这是一条不起眼的土路。尘埃泛起的远方，北边波光潋滟的一大片
幽蓝水光处，就是著名的圣湖。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "south" : __DIR__"tulu2",
                "north" : __DIR__"shenghu",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30020);
	set("coor/y", -8020);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
