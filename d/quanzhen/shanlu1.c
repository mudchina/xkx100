// /d/quanzhen/shanlu1.c 山路
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
一条山路弯弯曲曲地通向山上。北面的山上好象有一片柏树林，
树林中隐隐露出亭子的一角，南面就是上山的路。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northeast" : __DIR__"shanlu2",
                "southeast" : __DIR__"shanlu3",
                "westdown"  : "/d/hanzhong/shanlu",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3150);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
