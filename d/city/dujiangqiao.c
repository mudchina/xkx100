// Room: /yangzhou/dujiangqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","渡江桥");
	set("long",@LONG
一座三拱石桥横卧在大运河上，桥的侧栏上由知州欧阳修题着「渡
江桥」，桥下各色船只穿流不息。东边是扬州最大的码头，漕运的粮食，
两淮产的盐，多在此装卸。过了桥就是扬州的南门：安定门。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"north"  : __DIR__"nanmen",
		"south"  : "/d/wudang/wdroad1",
	]));
	set("objects", ([
		"/d/beijing/npc/shisong" :1,
	]));
	set("coor/x", 10);
	set("coor/y", -110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
