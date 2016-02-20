// Room: gbdixiaoshi.c
// by aji

inherit ROOM;
void create()
{
        set("short", "林间小屋");
        set("long", @LONG
你走进了一间小屋。四周墙壁都由青竹篾编成，窗外是一望无际的
竹林。屋里的桌椅、床铺均为竹制。但一阵扑鼻而来的狗肉香味，却显
得与这清雅的气氛格格不入。
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"gbandao"
        ]));
	set("objects", ([
		CLASS_D("gaibang") + "/hong" : 1,
		"/d/city/obj/zhubang": 1,
		"/d/city/obj/gourou": 1,
		"/d/city/obj/jiudai": 1,
		"/d/city/obj/jitui": 1
	]));

	set("coor/x", 71);
	set("coor/y", 61);
	set("coor/z", 0);
	setup();

        replace_program(ROOM);
}
