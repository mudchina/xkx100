//      tiantai.c 天台

inherit ROOM;

void create()
{
        set("short","天台");
        set("long",@LONG
这里是雪山寺的高处。北边可见雄伟的大雪山，南边可以俯瞰美丽
如镜的圣湖。
LONG );
	set("outdoors", "xueshansi");
        set("exits",([
                "west" : __DIR__"neidian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -69990);
	set("coor/y", -19880);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}
