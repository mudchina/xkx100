// Room: /d/taohua/zoulang2.c
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
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("exits", ([
		"north": __DIR__"neishi1",
		"south": __DIR__"zoulang5",
	]) );

	set("coor/x", 9000);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}