// Room: /city/biaojucyf.c

inherit ROOM;

void create()
{
	set("short", "签押房");
   	set("long", @LONG
这里是福威镖局签押房。镖局和官府交情既深，与江湖上的同道自
也不免也是瓜葛重重。这些局子里大面上的迎来送往，都由这里招呼。
LONG
        );
	set("exits", ([
		"east" : __DIR__"biaojudy",
	]));
	set("objects", ([
		__DIR__"npc/gao" : 1,
	]));
	set("coor/x", 1829);
	set("coor/y", -6298);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
