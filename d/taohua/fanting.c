// Room: /d/taohua/fanting.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "饭厅");
	set("long", @LONG
这是黄药师一家人吃饭的地方。饭厅中央摆着大圆桌，周围则放着
几张竹椅。窗口还摆着几盆水仙花。你吸了一下鼻子，啊．．．好香！
也不知到底是花香还是饭香。
LONG
	);
	set("exits", ([
		"east"  : __DIR__"neishi1",
		"north" : __DIR__"chufang",
	]));
	set("objects", ([
		__DIR__"npc/cheng" : 1,
	]));

	set("coor/x", 8990);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}