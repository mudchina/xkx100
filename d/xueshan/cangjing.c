//      cangjingge.c 藏经阁

inherit ROOM;

void create()
{
        set("short","藏经阁");
        set("long",@LONG
这里是雪山寺的藏经之处。书架上林林总总都是梵文典籍。你一个
字也看不懂。
LONG );
        set("exits",([
                "northwest" : __DIR__"dating",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/lingzhi" : 1,
        ]));

        set("coor/x", -69990);
	set("coor/y", -19900);
	set("coor/z", 130);
	setup();
        replace_program(ROOM);
}

