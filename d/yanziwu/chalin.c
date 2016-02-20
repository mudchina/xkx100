// Room: /d/yanziwu/chalin.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "茶花林");
	set("long", @LONG
一眼望将出去，都是红白缤纷的茶花，不见房屋。回望水边，小船
居然不知道什么时候已经撑走了。看来，只有免力入林，一寻出路了。
LONG );
	set("outdoors", "mantuo");
	set("exits", ([
		"north" : __DIR__"chalin1",
	]));
	set("objects", ([
		"/d/dali/obj/shanchahua" : 1,
	]));
	set("coor/x", 1210);
	set("coor/y", -1300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

