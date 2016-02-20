// foyezhang.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "佛爷掌");
        set("long", @LONG
只见此处颇为荒凉，是一处寺院的遗址。四周青松翠柏环绕，寺
院的断垣残璧依稀可见，似乎还是一座不小的寺院。往北是一片平原。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "east"  : __DIR__"shenheyuan",
        ]));

	set("coor/x", -3180);
	set("coor/y", 70);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}