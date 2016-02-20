// d/qingcheng/bingqishi.c

inherit ROOM;

void create()
{
	set("short", "兵器室");
	set("long", @LONG
这是一间存放兵器的屋子。刀、枪、剑、戟等各种兵器都按类放在
各自的兵器架上。整个屋子落满灰尘，显然已经好久没人来过。
LONG );
	set("exits", ([
		"south" : __DIR__"zoulang2",
	]));
	set("objects", ([
		__DIR__"obj/chui" : random(3),
		__DIR__"obj/zhui" : random(2),
	]) );
	set("coor/x", -8070);
	set("coor/y", -830);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}