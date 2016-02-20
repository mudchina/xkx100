//      shanjiao.c 山脚

inherit ROOM;

void create()
{
        set("short","山脚");
        set("long",@LONG
这里是山脚下的一片平地，山上不远处，皑皑白雪映照下的一大片
红墙金瓦处，就是远近闻名的雪山寺。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "westup" : "/d/xuedao/nroad7",
                "south"  : __DIR__"hubian4",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -29990);
	set("coor/y", -7980);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
