// chang.c 练武场

inherit ROOM;

void create()
{
        set("short","练武场");
        set("long",@LONG
这里是雪山寺练武场，树着好多木桩和沙袋，僧人们日常均在此习
武。东边是广场，西边有个小库房，南边一大片开阔地，就是雪山闻名
海内的祭坛了。
LONG );
        set("outdoors","xueshansi");
        set("exits",([
                "east" : __DIR__"guangchang",
                "west" : __DIR__"kufang",
                "north" : __DIR__"houyuan",
                "south" : __DIR__"jitan",
        ]));
        set("objects", ([
//                CLASS_D("xueshan")+"/gelunbu" :1,
		__DIR__"npc/x_lama" : 1 ,
        ]));
//        set("no_clean_up", 0);
        set("coor/x", -70050);
	set("coor/y", -19900);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}

