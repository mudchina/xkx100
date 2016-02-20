// guandao1.c 官道
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "官道");
        set("long", @LONG
这是一条大道，西面通往武功镇。道上的行人很多，大多是低
着头自己赶自己的路。忽然在你的身后响起得得的马蹄声，不一会
儿，几匹骏马从你身边飞驰而过，掠起了一片黄沙。
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "west" : __DIR__"guandao2",
                "east" : "/d/changan/road3",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3100);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
