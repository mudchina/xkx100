//      houmen.c 后门

inherit ROOM;

void create()
{
        set("short","后门");
        set("long",@LONG
这是雪山寺的后门。一片破落而萧索模样。喇嘛们香火也足，花用
也大。这是后门，虽然未免寒酸，可也总可以掖着。
LONG );
	set("outdoors", "xueshansi");
        set("exits",([
            "south" : __DIR__"houyuan",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -70050);
	set("coor/y", -19880);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
