// Room: /d/5lt/paijuroom.c

inherit ROOM;

void create()
{
        set("short", "牌局室");
        set("long", @LONG
这里是牌局室。
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"zoulang1",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -140);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}