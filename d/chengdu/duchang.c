// Room: /d/chengdu/duchang.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
        set("short", "赌场");
        set("long", @LONG
这里是一家赌场，一进门，你就会看见遒劲有力的四个大字“愿赌
服输”。听说有两个世外高人在这里开了这个大场子。没钱的人最好回
家抱娃娃去。
LONG	);
        set("exits", ([
                "west" : __DIR__"beijie2",                              
        ]));
	set("no_clean_up", 0);
        set("coor/x", -8040);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

 
