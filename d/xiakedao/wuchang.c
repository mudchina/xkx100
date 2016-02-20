// ROOM: /xiakedao/wuchang.c

inherit ROOM;
void create()
{
        set("short", "武场");
        set("long", @LONG
这是一个宽大的石洞，足可以装下几百人，两旁放着十八般兵器
。四周零散的放着许多椅子，中间一大块铺着猩红色的地毯，武士们
可以在这比试武功。
LONG );
        set("exits", ([
                "west" : __DIR__"shibi",
        ]));
        set("objects", ([
                "/d/shaolin/npc/mu-ren" : 4,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -3070);
	set("coor/y", -25000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}