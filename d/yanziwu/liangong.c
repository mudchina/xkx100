//ROOM: /d/yanziwu/linggong.c

inherit ROOM;

void create()
{
	set("short", "神功台");
	set("long",@LONG
这里就是慕容家练功之所。四壁开着窗口，窗外是太湖景物风致，
时时随风带来阵阵江南水乡的绿色和芳香。
LONG );
	set("exits", ([
		"west": __DIR__"qingyun",
	]));
	set("objects", ([
		"/d/shaolin/obj/mu-ren": 6,
	]));
	set("coor/x", 960);
	set("coor/y", -1500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}