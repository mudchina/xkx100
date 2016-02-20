//      houyuan.c 后院

inherit ROOM;

void create()
{
        set("short","后院");
        set("long",@LONG
这里是雪山寺的后院，后院不大，栽了几株参天雪松，在白晃晃的
雪山背景下，竟是飘然出世的心动。南边是练武场，北边是后门。
LONG );
        set("outdoors","xueshansi");
        set("exits",([
                "eastdown" : __DIR__"dilao",
                "north" : __DIR__"houmen",
                "south" : __DIR__"chang",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -70050);
	set("coor/y", -19890);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
