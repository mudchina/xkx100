// Room: /d/taohua/zoulang1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
一条连接大厅和内室的回廊。走廊外花木扶疏，桃花满地，远处碧
蓝色的大海和翠绿的岛屿映衬着点点白帆，历历如画。
LONG
	);
	set("exits", ([
		"east" : __DIR__"dating",
		"west" : __DIR__"zoulang3",
		"north": __DIR__"zoulang5",
	]) );
	set("objects", ([
		CLASS_D("taohua")+"/qu": 1,
	]));
	set("outdoors","taohua");
	set("coor/x", 9000);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}