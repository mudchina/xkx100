// houyuan.c 后院
// by Xiang

inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这里是后院，北面是三清殿，南面是一个圆形的门洞，有一条小路
通往后山。
LONG );
        set("exits", ([
                "south" : __DIR__"xiaolu1",
                "north" : __DIR__"sanqingdian",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/yu" : 1
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -930);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
