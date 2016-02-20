//      mishi.c 密室

inherit ROOM;

void create()
{
        set("short","密室");
        set("long",@LONG
这是一条小房间。什么东西都没有。
LONG );
        set("exits",([
                "south" : __DIR__"midao",
                "down" : "/d/city/shilijie4" ,
        ]));
        set("no_clean_up", 0);
	set("coor/x", -70010);
	set("coor/y", -19870);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}