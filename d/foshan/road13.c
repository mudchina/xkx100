//Room: /d/foshan/road13.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。进入福建省境了，闽西
山林茂密，多产毒虫，各位行路要十分小心。
LONG);
	set("objects", ([
	   __DIR__"obj/shuzhi": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "northeast" : __DIR__"road14",
	    "southwest" : __DIR__"road11",
	]));
	set("coor/x", 1600);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
