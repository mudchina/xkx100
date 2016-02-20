// Room: /d/jiaxing/njroad2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "村中小路");
	set("long", @LONG
一条村中的小路。路边是一家民房，不过好象已经很久很久没有人
住了。
LONG
	);
	set("outdoors","jiaxing");

	set("exits", ([
		"west" : __DIR__"njroad1",
		"east" : __DIR__"njroad3",
		"north": __DIR__"guojia",
	]) );
	set("objects", ([
		"/d/village/npc/girl" : 1,
	]) );

	set("coor/x", 1570);
	set("coor/y", -1050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}