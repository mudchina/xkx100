//      shanlu2.c 山路
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","山路");
        set("long",@LONG
这是一条上山的小路。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "northup" : __DIR__"shanmen",
                "eastdown" : __DIR__"shanlu1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
