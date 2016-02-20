// Room: /d/taohua/zoulang5.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
一条连接大厅和练武场的回廊。走廊外花木扶疏，桃花满地，远处
碧蓝色的大海和翠绿的岛屿映衬着点点白帆，历历如画。东边望去，是
一大片的海滩。
LONG
	);
	set("exits", ([
		"east" : __DIR__"haitan",
		"north": __DIR__"zoulang2",
		"south": __DIR__"zoulang1",
	]) );
	set("objects", ([
		__DIR__"npc/yapu": 1,
	]));
	set("outdoors","taohua");
	set("coor/x", 9000);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	set("coor/x", 9000);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}