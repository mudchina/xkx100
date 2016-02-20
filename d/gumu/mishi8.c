// mishi8.c 密室
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这里是古墓中的密室，四周密不透风，你只能借着墙上昏暗的灯光
来勉强分辨方向。墙是用整块的青石砌合起来的，接合的甚是完美，你
难以从中找出一丝缝隙。密室中摆放着一些简单的家居用具，原来这是
古墓派祖师林朝英的居室。
LONG	);
	set("exits", ([
		"west" : __DIR__"mishi7",
		"out"  : "/d/city/shilijie4",
	]));
	set("objects", ([
		CLASS_D("gumu")+"/lin" : 1,
	]));
	set("coor/x", -3000);
	set("coor/y", 0);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
