// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "西厢房");
	set("long", @LONG
这是供来客休息的厢房，房子不大，但是很整洁，墙上挂
着一些字画。有个丫鬟正忙着为客人泡茶。
LONG
	);
	set("exits", ([ 
            "east" : __DIR__"yuanzi",
	]));
	set("objects", ([
            "/d/changan/obj/chairs" : 1,
            __DIR__"npc/yahuan" : 1,
	]));
	set("coor/x", 1600);
	set("coor/y", -1960);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
