//      dadian.c 大殿

inherit ROOM;

void create()
{
        set("short","大殿");
        set("long",@LONG
这里是雪山寺的大殿，中央供奉着佛祖塑像。僧人们在念着经文。
远来的香客们在这里虔诚地膜拜。大殿两侧都是侧殿。
LONG );
        set("exits",([
                "east"  : __DIR__"cedian1",
                "west"  : __DIR__"cedian2",
                "south" : __DIR__"guangchang",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/lazhang" : 1,
                CLASS_D("xueshan")+"/first" : 1,
		__DIR__"npc/xiang-ke" : 2,
        ]));
        set("valid_startroom", 1);
//        set("no_clean_up", 0);
	set("coor/x", -70000);
	set("coor/y", -19890);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);

        "/clone/board/xueshan_b"->foo();
}
